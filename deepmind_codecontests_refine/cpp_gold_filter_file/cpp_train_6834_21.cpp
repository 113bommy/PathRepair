#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  int ocho = a / 2;
  if (ocho > 18 || (ocho > 17 && (a % 2 != 0))) {
    cout << -1 << '\n';
    return 0;
  }
  string resp;
  for (int i = 0; i < ocho; ++i) {
    resp += '8';
  }
  if (a == 1)
    resp += '4';
  else if (a % 2 != 0)
    resp += '0';
  cout << resp << '\n';
}
