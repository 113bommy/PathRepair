#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int n;
    cin>>n;
    string str;
    getline(cin.str);
    while(n--){
        getline(cin,str);
        bool f=false;
        for(int a=1;!f;a++){
            if(a%2==0||a%13==0)continue;
            for(int b=0;!f&&b<26;b++){
                char m[26];
                for(int i=0;i<26;i++)m[(i*a+b)%26]=i+'a';
                string t=str;
                for(int i=0;i<t.size();i++){
                    if(islower(t[i]))t[i]=m[t[i]-'a'];
                }
                bool f_this=(t.find("this")!=string::npos);
                bool f_that=(t.find("that")!=string::npos);
                if(f_this||f_that){
                    str=t;
                    f=true;
                }
            }
        }
        cout<<str<<endl;
    }
}