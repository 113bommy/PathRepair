#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;
  string s;
  cin>>a>>s>>b;
  cout<<(s=='+' ? a+b:a-b)<<endl;
  return 0;
}