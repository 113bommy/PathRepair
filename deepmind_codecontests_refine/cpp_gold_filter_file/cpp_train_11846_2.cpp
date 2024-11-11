#include<bits/stdc++.h>
using namespace std;

int main()
{
  long x,p=100,step=0;
  cin>>x;
  while(p<x)
  {
    p+=p/100;
    step++;
  }
  cout<<step<<endl;
}
