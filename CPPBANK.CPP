#include<fstream>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
using namespace std;

class bank
{
    long long am;
    int a,p,ac;
    char n[30],s,na[30],add[70],u[15];
public:
    void getdata()
    {
        cout<<"Enter the details:\nAccount no.:";
        cin>>ac;
        cout<<"\nName:";
        gets(n);
        cout<<"Age:";
        cin>>a;
        cout<<"Sex(M or F):";
        cin>>s;
        s=toupper(s);
        cout<<"Address:";
        gets(add);
        cout<<"Nationality:";
        cin>>na;
        cout<<"ENTER THE AMOUNT(min 500):";
        cin>>am;
        cout<<"\nEnter username:";
        cin>>u;
        cout<<"\nEnter pin:";
        cin>>p;
        cout<<"!!!!!!!!Details updated successfully!!!!!!!";
    }
    
    void showdata()
    {
        cout<<"Your account details are here:-";
        cout<<"\nName:"<<n;
        cout<<"\nAge:"<<a;
        cout<<"\nSex:"<<s;
        cout<<"\nAddress:"<<add;
        cout<<"\nNationality:"<<na;
        cout<<"\nAmount:"<<am;
    }
    void modify()
    {
        cout<<"\nAccount no.:"<<ac;
        cout<<"\nName:";
        gets(n);
        cout<<"Age:";
        cin>>a;
        cout<<"Sex(M or F):";
        cin>>s;
        s=toupper(s);
        cout<<"Address:";
        gets(add);
        cout<<"Nationality:";
        cin>>na;
        cout<<"ENTER THE AMOUNT(min 500):";
        cin>>am;
    }

    void deposit(long long d)
    {
        am=am+d;
    }
    void withdraw(long long w)
    {
        long long p=0;
        p=am;
        am=am-w;
        if(am<=500)
        {
            am=p;
            cout<<"\n\n\t\t\t\tInsufficient Balance !!";
        }
    }
    int retpin()
    {
        return p;
    }
    char* retun()
    {
        return u;
    }
    long long retam()
    {
        return am;
    }
    int retac()
    {
        return ac;
    }
}s;

void modifyac()
{
    fstream f;
    int v=0;
    f.open("abc.txt",ios::binary|ios::in|ios::app);
    if(!f)
    {
        cout<<"File could not be open!! press any key. . . ";
        return;
    }
    while(f.read((char*)&s,sizeof(s))&& v==0)
    {
        cout<<"Enter new deatils:";
        s.modify();
        long p=(-1)*sizeof(s);
        f.seekp(p,ios::cur);
        f.write((char*)&s,sizeof(s));
        cout<<"\n\t\t\t\trecord updated";
    }
    f.close();
}
void menu();
void login()
{
    ifstream fin;
    ofstream fout;
    int ip,c=0;
    char iu[10];
    cout<<"\n\n\n\n\n\t\t\t\tUser name:";
    cin>>iu;
    cout<<"\t\t\t\tPin:";
    cin>>ip;
    fin.open("abc.txt",ios::binary) ;
    if(!fin)
    {
        cout<<"File could not be opened!! press any key. . .";
        return;
    }
    while(fin.read((char*)&s,sizeof(s)))
    {
        if(strcmp(iu,s.retun())==0)
        {
            if(ip==s.retpin())
            {
                cout<<"\t\t\t\tAccount Details:";
                s.showdata();
                menu();
                c=1;
                return;
            }
        }
    }
    fin.close();
    if(c==0)
    {
        cout<<"\n\n\n\n\t\t\tInvalid user name or pin !!!!!!  press any key . . .";
    }
}

void deleteac()
{
    int n=s.retac();
    ifstream fin;
    ofstream fout;
    fin.open("abc.txt",ios::binary);
    if(!fin)
    {
        cout<<"File could not be open !! Press any Key...";
        return;
    }
    fout.open("xyz.txt",ios::binary);
    fin.seekg(0,ios::beg);
    while(fin.read((char *) &s, sizeof(s)))
    {
        if(s.retac()!=n)
        {
            fout.write((char *) &s, sizeof(s));
        }
    }
      fin.close();
    fout.close();
    remove("abc.txt");
    rename("xyz.txt","abc.txt");
    cout<<"\n\n\tAccount Deleted ..";
}

void deposit1()
{
    long long da;
    ifstream fin;
    ofstream fout;
    cout<<"Enter amount to be deposited:";
    cin>>da;
    fin.open("abc.txt",ios::binary);
    fout.open("mno.txt",ios::binary);
    while(fin.read((char*)&s,sizeof(s)))
    {
        s.deposit(da);
        fout.write((char*)&s,sizeof(s));
    }
    fin.close();
    fout.close();
    remove("abc.txt");
    rename("mno.txt","abc.txt");
}
void withdraw1()
{
    long long wa;
    ifstream fin;
    ofstream fout;
    cout<<"Enter amount to be withdrawn:";
    cin>>wa;
    fin.open("abc.txt",ios::binary);
    fout.open("pqr.txt",ios::binary);
    while(fin.read((char*)&s,sizeof(s)))
    {
        s.withdraw(wa);
        fout.write((char*)&s,sizeof(s));
    }
    fin.close();
    fout.close();
    remove("abc.txt");
    rename("pqr.txt","abc.txt");
}

void menu()
{
    int x;
//    long long da,wa;
    do
    {
        s.showdata();
        cout<<"\n\n\t\t\t\t1.Deposit Amount\n\t\t\t\t2.Withdraw amount\n\t\t\t\t3.Modify Details\n\t\t\t\t4.Delete account\n\t\t\t\t5.Logout\n\t\t\t\tEnter your choice:";
        cin>>x;
        switch(x)
        {
            case 1:
            {
                deposit1();
                break;
            }
            case 2:
            {
                withdraw1();
                break;
            }
            case 3:
            {
                modifyac();
                break;
            }
            case 4:
            {
                deleteac();
                break;
            }
            case 5:
            {
                return;
            }
            default:
                cout<<"\t\t\t\tInvalid input";
                
        }
    }
    while(1);
}

void initialScreen()
{
    ifstream fin;
    ofstream fout;
    fstream f;
    int x;
    cout<<"\n\n\t\t\t\tWELCOME TO BANK\n\t\t\t\t===============\n\n\n\n\t\t\t\t1.Log in\n\t\t\t\t2.Sign up\n\t\t\t\t3.Exit\n\t\t\t\tEnter your choice:";
    cin>>x;
    if(x==1)
    {
        login();
    }
    if(x==2)
    {
        s.getdata();
        fout.open("abc.txt",ios::binary|ios::app);
        fout.write((char*)&s,sizeof(s));
        fout.close();
    }
    else
    {
        cout<<"\n\n\n\n\n\n\n\t!!!!!!!........THANK YOU FOR USING OUR BANK .....!!!!!!";
    }
}

int main()
{

    do
    {
        initialScreen();
    }while(1);
}
