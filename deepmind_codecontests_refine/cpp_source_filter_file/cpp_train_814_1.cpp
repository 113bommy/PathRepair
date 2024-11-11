#include<bits/stdc++.h>
using namespace std;
int main(){
  string a,b,c,d,e;cin>>a>>b>>c;
  d=a.size();e=b.size();
  if(a[d-1]==b[0]&b[e-1]==c[0])cout<<"YES";else cout<<"NO";}