#include<iostream>
usingnamespace std;
int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  cout<<a+b+c-max(max(a,b),max(b,c))<<endl;
  return 0;
}