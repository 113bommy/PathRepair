#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin>>a>>b>>c;
  if(a+b>=c) cout<<c+b;
  else cout<<b+a+b+1;
  cout<<endl;
}