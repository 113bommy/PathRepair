#include <iostream>
using namespace std;
int main()
{
  int a,b;
  char o;
  cin>>a>>o>>b;
  if(o=='+')
    cout<<a+b;
  else
    cout<<a-b;
  return 0;
}