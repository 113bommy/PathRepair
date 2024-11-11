#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;
  char s;
  cin>>a>>s>>b;
  cout<<(s=='+' ? a+b:a-b)<<endl;
  return 0;
}