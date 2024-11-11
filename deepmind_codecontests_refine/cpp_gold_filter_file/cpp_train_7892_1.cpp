#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,k;cin>>a>>b>>c>>k;
  int s=a+b+c,m=max({a,b,c});s-=m;
  for(int i=0;i<k;i++)m*=2;
  cout<<s+m<<endl;
} 
