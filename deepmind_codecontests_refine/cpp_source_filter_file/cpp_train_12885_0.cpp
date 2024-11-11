#include<bits/stdc++.h>
using namespace std;
int main(){
long long int n,s,i,cnt=0;
string s,t;
cin>>s>>t;
for(i=0;i<s.size();++i)
if(s[i]!=t[i])++cnt;
cout<<cnt;
  return 0;
}