#include <bits/stdc++.h>
using namespace std;
int main() {
  char a, b;
  int k, A, B, x, y, z;
  int v[4] = {118, 60, 94, 62};
  while (cin >> a >> b >> k) {
    A = (int)a;
    B = (int)b;
    if (A == 118) {
      x = 0;
    } else if (A == 60) {
      x = 1;
    } else if (A == 94) {
      x = 2;
    } else if (A == 62) {
      x = 3;
    }
    y = (x + k) % 4;
    x = x - k;
    while (x < 0) x = x + 4;
    z = x % 4;
    if (v[y] == B and v[z] == B)
      cout << "undefined\n";
    else if (v[y] == B)
      cout << "cw\n";
    else if (v[z] == B)
      cout << "ccw\n";
    else
      cout << "undefined\n";
  }
  return 0;
}
