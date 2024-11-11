#include <bits/stdc++.h>
using namespaces std;

int main(){

  int x;
  cin >> x;
  int num=x%100;
  x/=100;
  if(5*x>=num) cout << 1 << endl;
  else cout << 0 << endl;
  
}