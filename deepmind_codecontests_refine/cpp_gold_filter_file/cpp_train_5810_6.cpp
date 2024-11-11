#include <bits/stdc++.h>
using namespace std;
int main(){
  int a, b;
  cin >> a >> b;
  int c;
  c = a+b;
  if (c%2==0) cout << c/2;
  else cout << "IMPOSSIBLE";
}