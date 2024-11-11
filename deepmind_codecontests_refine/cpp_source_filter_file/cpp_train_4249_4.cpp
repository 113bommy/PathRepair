#include<iostream>
using nmaespace std;
int main()
{
  int n,d;
  cin>>n>>d;
  d=2*d+1;
  if(n%d==0) cout<<n/d;
  else cout<<(n/d)+1;
}
