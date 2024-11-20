#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <cstdio>

// STEPS TO EXECUTE AND RUN CPP FILE IN CMD
// NAVIGATE TO THE PATH
// EXECUTE g++ filename.cpp -o output (output refers to the exe (executable) file that will be generated after compiling the file )
// then execute "output" in cmd the output will be shown in the terminal.
// to compile the a cpp file again to update its exe file we use g++ -o outputfile.exe sourcecode.cpp

using namespace std;
class shopping
{
private:
    string product_name;
    int product_code;
    float product_cost, discount;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping::menu()
{
m:

    int choice;
    string email;
    string password;
    cout << "\t\t" << endl;
    cout << "\t\t---------------------------------------------SuperMarket Main Menu---------------------------------------------" << endl;
    cout << "\t\t" << endl;
    cout << "\t\t----------------------------------------------1) Administrator-------------------------------------------------" << endl;
    cout << "\t\t" << endl;
    cout << "\t\t---------------------------------------------------2) Buyer ----------------------------------------------" << endl;
    cout << "\t\t" << endl;
    cout << "\t\t---------------------------------------------------3) Exit -----------------------------------------------" << endl;
    cout << "\t\t" << endl;
    cout << "\t\t-------------------------------------------------!!!Please Select!!!--------------------------------------" << endl;
    cout << "\t\t" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Please Login" << endl;
        cout << "Enter email: ";
        cin >> email;
        cout << "Enter password: ";
        cin >> password;
        if (email == "surbhibhandari@gmail.com" and password == "shopping_project")
        {
            system("cls");
            administrator();
        }
        else
        {
            cout << "Invalid Password or email !!!!" << endl;
        }
        break;
    case 2:
        system("cls");
        buyer();
        break;
    case 3:
        exit(0);

    default:
        cout << "Please Select from given options" << endl;
    }
    goto m;
}
void shopping::administrator()
{
m:
    int choice;
    cout << "\t\t--------------------------------------------Administrator Menu--------------------------------------------" << endl;
    cout << "\t\t" << endl;
    cout << "\t\t------------------------|__________________1) Add the product__________________|------------------------" << endl;
    cout << "\t\t" << endl;
    cout << "\t\t------------------------|__________________2) Modify the product________________|------------------------" << endl;
    cout << "\t\t" << endl;
    cout << "\t\t------------------------|__________________3) Delete the product________________|------------------------" << endl;
    cout << "\t\t" << endl;
    cout << "\t\t------------------------|__________________4) Back to main menu_________________|------------------------" << endl;
    cout << endl;
    cout << "\t\t\tPlease enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        system("cls");
        add();
        break;
    case 2:
        system("cls");
        edit();
        break;
    case 3:
        system("cls");
        rem();
        break;
    case 4:
        system("cls");
        menu();
        break;
    default:
        cout << "Invalid choice!!!" << endl;
        goto m;
    }
}
void shopping ::buyer()
{
m:
    int choice;
    system("cls");
    cout << "\t\t--------------------------------------------Buyer Menu-----------------------------------------------" << endl;
    cout << "\t\t" << endl;
    cout << "\t\t----------------------|__________________1) Buy the product__________________|----------------------" << endl;
    cout << "\t\t" << endl;
    cout << "\t\t----------------------|__________________2) Back to main menu________________|----------------------" << endl;
    cout << endl;
    cout << "\t\t\tPlease enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        // system("cls");
        receipt();
        break;
    case 2:
        // system("cls");
        menu();
    default:
        cout << "Invalid choice!!!" << endl;
        goto m;
    }
}
void shopping ::add()
{
m:
    system("cls");
    string pname;
    int pcode;
    float pcost, pdiscount;
    int token = 0;
    fstream data;
    cout << "\t\t-------------------------------------------Add New Product----------------------------------------------" << endl;
    cout << "\t\t" << endl;
    cout << "\t\tEnter the product code: ";
    cin >> product_code;
    cout << endl;
    cout << "\t\tEnter the product name: ";
    cin >> product_name;
    cout << endl;
    cout << "\t\tEnter the product price: ";
    cin >> product_cost;
    cout << endl;
    cout << "\t\tEnter the product discount: ";
    cin >> discount;
    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << product_code << " " << product_name << " " << product_cost << " " << discount << endl;
        data.close();
    }
    else
    {
        data >> pcode >> pname >> pcost >> pdiscount;
        while (!data.eof())
        {
            if (pcode == product_code)
                token++;
            data >> pcode >> pname >> pcost >> pdiscount;
        }
        data.close();
        if (token)
        {
            cout << "\n\t\tDuplicate product code !!" << endl;
            cout << "\n\t\tPlease enter another new product code !!" << endl;
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << product_code << " " << product_name << " " << product_cost << " " << discount << endl;
            data.close();
            cout << "\n\t\t!!Product successfully Added!!" << endl;
        }
        char continueadding;
        cout << "\n\t\tDo you want to add more products ? : (y/n) : ";
        cin >> continueadding;
        if (continueadding == 'y')
            goto m;
        else
        {
            system("cls");
            administrator();
        }
    }
}

void shopping ::edit()
{
    fstream data, data1;
    int c, token = 0;
    float p, d;
    string n;
    int pcodetoedit;
    cout << "\t\t--------------------------------------------Edit the Product-----------------------------------------------" << endl;
    cout << endl;
    data.open("database.txt", ios::in);
    if (!data)
        cout << "ERROR: File does not exist!!!" << endl;
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        cout << "Enter the pcode of the product : ";
        cin >> pcodetoedit;
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (pcodetoedit == c)
            {
                cout << "Enter the new product code : ";
                cin >> product_code;
                cout << "Enter the new product name : ";
                cin >> product_name;
                cout << "Enter the new product price : ";
                cin >> product_cost;
                cout << "Enter the discount on the product : ";
                cin >> discount;
                data1 << " " << product_code << " " << product_name << " " << product_cost << " " << discount << endl;
                cout << "Product successfully editted !!!!" << endl;
                token++;
            }
            else
            {
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
            }
            data >> c >> n >> p >> d;
        }
        if (!token)
        {
            cout << "Record with given product code is not found!!!" << endl;
            cout << "Enter a valid product code" << endl;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        Sleep(5000);
        system("cls");
        administrator();
    }
}
void shopping ::rem()
{
    fstream data, data1;
    int pcodetoedit;
    int c, token = 0;
    float p, d;
    string n;
    cout << "\t\t----------------------------------------------------Remove the product--------------------------------------------------" << endl;
    cout << endl;
    data.open("database.txt", ios::in);
    if (!data)
        cout << "ERROR : File does not exist!!!" << endl;
    else
    {
        cout << "Enter the product code of product to remove: ";
        cin >> pcodetoedit;
        data1.open("database1.txt", ios::app | ios::out);
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcodetoedit)
            {
                cout << "Product successfully removed!!!!!!!" << endl;
                Sleep(3000);
                token++;
            }
            else
            {
                data1 << " " << c << " " << n << " " << p << " " << d << endl;
            }
            data >> c >> n >> p >> d;
        }
        if (!token)
        {
            cout << "Product code not found!!" << endl;
        }
        data1.close();
        data.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        system("cls");
        administrator();
    }
}

void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\t\t-------------------------------------------------------Product Lists-------------------------------------------------------" << endl;
    cout << "\t\t|__________________________________________________________________________________________________________________________|" << endl;
    cout << "\t\t\tProno\t\tName\t\t\tPrice\t\tDiscount" << endl;
    cout << "\t\t|__________________________________________________________________________________________________________________________|" << endl;
    if (!data)
    {
        cout << "Database empty!!!!" << endl;
    }
    else
    {
        data >> product_code >> product_name >> product_cost >> discount;
        while (!data.eof())
        {
            cout << "\t\t\t" << product_code << "\t\t" << product_name << "\t\t" << product_cost << "\t\t" << discount << endl;
            data >> product_code >> product_name >> product_cost >> discount;
        }
    }
    data.close();
}
bool productcheck(int productcode)
{
    fstream data;
    int pcode;
    string pname;
    float pprice, pdiscount;
    data.open("database.txt", ios::in);
    data >> pcode >> pname >> pprice >> pdiscount;
    while (!data.eof())
    {
        if (pcode == productcode)
        {
            data.close();
            return true;
        }
        data >> pcode >> pname >> pprice >> pdiscount;
    }
    return false;
}
void shopping::receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "Empty database!!!!!!" << endl;
    }
    else
    {
        data.close();
        list();
        cout << "\t\t------------------------------------------------------------------------------------------------------------" << endl;
        cout << "\t\t-------------------------------------------Place the Order-------------------------------------------------" << endl;
        cout << "\t\t------------------------------------------------------------------------------------------------------------" << endl;
        do
        {
        m:
            int temp = 0;
            cout << "\t\tEnter the product code : ";
            cin >> temp;
            if (productcheck(temp))
                arrc[c] = temp;
            else
            {
                cout << "\t\tNo such product code exists !!" << endl;
                goto m;
            }

            cout << "\t\tEnter the quantity : ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\t\tDuplicate product code. Please try again!!" << endl;
                    goto m;
                }
            }
            c++;
            cout << endl;
            cout << "\t\tWould you like to buy another product ?? If yes please press\" y\" else n!!:  ";
            cin >> choice;
            cout << c;
        } while (choice == 'y');
        cout << endl;
        cout << "\t\t------------------------------------------------------The Receipt----------------------------------------------------------" << endl;
        cout << "\n\t\tCode\tName\t\tQuantity\tTprice\tTAmount with Discount" << endl;
        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> product_code >> product_name >> product_cost >> discount;

            while (!data.eof())
            {
                if (arrc[i] == product_code)
                {
                    amount = product_cost * arrq[i];
                    dis = amount - (amount * (discount / 100));
                    total = total + dis;
                    cout << "\n\t\t"
                         << product_code << "\t" << product_name << "\t" << arrq[i] << "\t" << amount << "\t\t" << dis << endl;
                }
                data >> product_code >> product_name >> product_cost >> discount;
            }
        }
        data.close();
    }
    cout << "\n\t\t----------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tTotal Amount :: \t\t\t\t" << total << endl;
}
int main()
{
    shopping s;
    s.menu();
    return 0;
}