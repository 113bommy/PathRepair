#include<bits/stdc++.h>
using namespace std;
int main()
{long long n,x,t,y,i;
 string s;
 cin>>s;n=s.length();y=0;
for(i=0;i<n;i++)
{y=y+s[i]-'0';}
 if(y%9==0)cout<<"Yes";
 else cout<<"No";
return 0;}