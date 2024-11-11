#include<bits/stdc++.h>
using namespace std;
int main(){
char s[100006],t[100006];
cin>>s>>t;
int l,c=0,i;
l=strlen(s);
for(i=0;i<l;i++)
{
if(s[i]!=t[i]
c++;
}
cout<<c<<endl;
}