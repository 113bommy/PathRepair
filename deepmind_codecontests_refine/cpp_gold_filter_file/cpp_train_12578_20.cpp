#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
  int a,b;
  cin>>a>>b;
  int x[]={a+b,a-b,a*b};
  sort(x,x+3);
  cout<<x[2];
}