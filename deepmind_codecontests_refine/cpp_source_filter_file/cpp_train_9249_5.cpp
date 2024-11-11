#include <bits/stdc++.h>
using namespace std;

int min()
{
  int a,b;
  char s;
  cin>>a>>s>>b;
  if(s=='+')
    cout<<a+b;
  else
    cout<<a-b;
}