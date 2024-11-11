#include<iostream>
using namespace std;
int main()
{
  int n,a,b;
  cin>>n>>a>>b;
  int min=n*a>b?b:a*n;
  cout<<min;
}