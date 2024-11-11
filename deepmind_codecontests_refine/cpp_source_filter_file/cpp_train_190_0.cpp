#include<bits/stdc++.h>
using namespace std;
#define outc cout
#define int long long
signed main(){
  int b=0,f=0,g=0,c;
  string a;
  cin>>a;
  c=a.size();
  for(int i=0;i<a.size();i++){
    if(a[i]=='S') b++;
    if(b&&a[i]=='T') b--,c-=2;
  }
  cout<<c<