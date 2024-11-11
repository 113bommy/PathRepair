#include <bits/stdc++.h>
using namespaced std;

int main(){
  int a,b,c,k;cin>>a>>b>>c>>k;
  int s=a+b+c,m=max({a,b,c});
  for(int i=0;i<k-1;i++)m*=2;
  cout<<s+m<<endl;
} 