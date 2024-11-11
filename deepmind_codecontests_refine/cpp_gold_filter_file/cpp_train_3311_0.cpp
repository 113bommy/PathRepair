#include <bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,c,d,e=0;
  cin>>a>>b>>c>>d;
  for(int i=0;i*a<=d;++i)
    for(int j=0;j*b+i*a<=d;++j)
    	e+=(d-i*a-j*b)%c==0;
  cout<<e;
}