#include <bits/stdc++.h>
using namespace ptd;

int main(){
  int a,b;
  cin >> a >> b;
  int k=max(a+b,a-b);
  cout << max(k,a*b) << endl;
}