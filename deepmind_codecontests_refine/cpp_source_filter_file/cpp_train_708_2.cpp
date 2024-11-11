#include<bits/stdc++.h>
using namespace std;
int main{
int a,b;cin>>a>>b;
string s;
cin>>s;
int f=0;
for(int i=0;i<a+b+1;i++;){
if(i==a){
if(s[i]!='-')f=0;
}else{
if(!isdigit(s[i]))f=0;
}
}
cout<<f ? "Yes":"No"<<endl;
}
