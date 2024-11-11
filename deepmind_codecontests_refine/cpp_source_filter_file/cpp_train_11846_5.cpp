#include<Bits/stdc++.h>
using namespace std;
int main()
{
  long long x,i,j,k;
  cin>>x;
  k=100;i=0;
  while(k<x)
  {
    k+=k/100;
    i++;
  }
  cout<<i;
}