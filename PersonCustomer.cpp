#include <iostream>
using namespace std;

class Person{
    public:
        string name,address;
        int telp;
        Person(string name, string address, int telp){
            Person::name = name;
            Person::address = address;
            Person::telp = telp;
        }
        Person(){
            name = "Unamed";
            address = "Unknown";
            telp = 0;
        }
};
class Customer{
    public:
        Person person;
        int custNumber;
        bool mail;
        Customer(){
            custNumber = 0;
            mail = false;
        }
        Customer(string nama, string address, int telp, int custNumber, bool mail){
            person.name = nama;
            person.address = address;
            person.telp = telp;
            Customer::custNumber = custNumber;
            Customer::mail = mail;
        }
        void print(){
            string isMail = (mail)? "True" : "False";
            cout << "Name            : " << person.name << endl
                 << "Address         : " << person.address << endl
                 << "Telepon         : " << person.telp << endl
                 << "Customer Number : " << custNumber << endl
                 << "Receive Mail ?  : " << isMail << endl;
        }
        void inputData(int custNumber){
            string input, nama, alamat; 
            int num;
            cout << "Name                       : ";cin >> ws; getline(cin, nama);
            cout << "Address                    : ";cin >> ws; getline(cin, alamat);
            cout << "No telp                    : "; cin >> num;
            up:
            cout << "Receive Email (true/false) : "; cin >> input;
            if((input == "True") || (input == "true")) mail = true;
            else if((input == "False") || (input == "false")) mail = false;
            else goto up;
            person.name = nama;
            person.address = alamat;
            person.telp = num;
            Customer::custNumber = custNumber;
        }
        void reset(){
            person.name = "Unamed";
            person.address = "Unknown";
            person.telp = 0;
            Customer::custNumber = 0;
            Customer::mail = false;
        }
};
int main(){
    int n, x, noDelete, noChange;
    bool isLoop = true, check = false;
    Customer customer[100];
    cout << "-- UTS PRAKTEK --\n\n";
    cout << "1. Input Data Customer\n"
             << "2. Change Data Customer\n"
             << "3. Print Data Customer\n"
             << "4. Add Customer\n"
             << "5. Delete Customer\n"
             << "6. Exit\n";
    cout << "Enter many customer : "; cin >> n;
    while(isLoop){
        ulang:
        system("cls");
        cout << "-- UTS PRAKTEK PBO --\n\n";
        cout << "1. Input Data Customer\n"
             << "2. Change Data Customer\n"
             << "3. Print Data Customer\n"
             << "4. Add Customer\n"
             << "5. Delete Customer\n"
             << "6. Exit\n";
        cout << "Menu : "; cin >> x;
        switch(x){
            case 1:
                cout << endl;
                for(int i = 1; i <= n; i++){
                    cout << "Customer "<< i << endl;
                    customer[i-1].inputData(i);
                    cout << endl;
                }break;
            case 2:
                cout << endl;
                for(int i = 1; i <=n; i++){
                    cout << "Customer " << i << " : " << customer[i-1].person.name << endl;
                }
                 cout << "\nWhich Customer Number you to change : "; cin >> noChange;
                for(int i = 1; i <= n; i++){
                    if(i == noChange){
                        customer[noChange-1].inputData(noChange);
                        check = true;
                    }
                }
                if(!check) {
                    cout << "No change is not found\n";
                    system("pause");
                    goto ulang;
                }break;
            case 3:
                cout << endl;
                for(int i = 1; i <= n; i++){
                    cout << "Customer " << i << endl;
                    customer[i-1].print();
                }
                system("pause"); break;
            case 4:
                cout << endl;
                customer[n].inputData(n+1);
                n = n+1;
                break; 
            case 5:
                cout << endl; check = false;
                for(int i = 1; i <=n; i++){
                    cout << "Customer " << i << " : " << customer[i-1].person.name << endl;
                }
                cout << "\nWhich Customer Number you to delete : "; cin >> noDelete;
                for(int i = 1; i <= n; i++){
                    if(i == noDelete){
                        customer[i-1] = customer[i];
                        customer[i].reset();
                        check = true;
                    }
                }
                if(check) n = n-1;
                else {
                    cout << "No delete is not found\n";
                    system("pause");
                    goto ulang;
                }break;
            case 6:
                isLoop = false; break;
            default:
                cout << "you must to enter int in range 1-6\n"; break;
        }
    }
    return 0;
}
