#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, m, mod;
  cin >> a >> m;
  for (int i = 0; i < 500; i++) {
    mod = a % m;
    a += mod;
    if (mod == 0) break;
  }
  if (mod == 0)
    cout << "yes" << endl;
  else
    cout << "no" << endl;
  return 0;
}
