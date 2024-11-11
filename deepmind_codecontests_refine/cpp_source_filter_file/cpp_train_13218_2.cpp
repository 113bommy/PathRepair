#include<iostream>
#include<string>
using namespace std;

string rev(string str){
    for(int i=0;i<str.length();i++){
        if(str[i]=='['){
            int j;
            int co=1;
            for(j=i+1;j<str.length();j++){
                if(str[j]=='[')co++;
                if(str[j]==']')co--;
                if(co==0)break;
            }
            string n=rev(str.substr(i+1,j-i-1));
            str=str.substr(0,i)+n+str.substr(j+1,str.length()-j-1);
        }
    }
    string tem="";
    for(int i=0;i<str.length();i++)
        tem+=str[str.length()-1-i];
    return tem;
}

string pm(string str){
    char c=str[str.length()-1];
    for(int i=0;i<str.length()-1;i++){
        if(str[i]=='+'){
            if(c=='Z')
                c='A';
            else c++;
        }
        if(str[i]=='-'){
            if(c=='A')
                c='Z';
            else c--;
        }
    }
    string tem="";
    tem+=c;
    return tem;
}

int main(){
    while(1){
        string str;
        cin>>str;
        if(str==".")break;
        for(int i=0;i<str.length();i++){
            if(str[i]=='+'||str[i]=='-'){
                int j;
                for(j=i+1;str[j]=='+'||str[j]=='-';j++);
                string n;
                if(str[j]=='?')n="A";
                else n=pm(str.substr(i,j-i+1));
                str=str.substr(0,i)+n+str.substr(j+1,str.length()-j-1);
            }
            if(str[i]=='?')n="A";
           // cout<<str<<endl;
        }
        for(int i=0;i<str.length();i++){
            if(str[i]=='['){
                int j;
                int co=1;
                for(j=i+1;j<str.length();j++){
                    if(str[j]=='[')co++;
                    if(str[j]==']')co--;
                    if(co==0)break;
                }
                string n=rev(str.substr(i+1,j-i-1));
                //cout<<n<<endl;
                str=str.substr(0,i)+n+str.substr(j+1,str.length()-j-1);
            }
        }
        cout<<str<<endl;
    }
}