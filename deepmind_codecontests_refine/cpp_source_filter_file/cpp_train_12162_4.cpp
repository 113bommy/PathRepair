#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >> a >> b >> c;
  m = max({a,b,c});
  cout << (a+b+c) - m + (10 * m);
}