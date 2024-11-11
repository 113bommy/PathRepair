#include<bits/stdc++.h>
using namespace std;
int main(){
string s,t="CODEFESTIVAL2016";
cin>>s;
int sum=0;
for(int i=0;i<16;i++)if(s[i]!=t[i])sum++;
cout<<sum<<endl;
}