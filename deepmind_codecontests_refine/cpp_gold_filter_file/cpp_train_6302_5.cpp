#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d = 0, e = 0, f = 1, g = 1, h[500001], i = 1, j, k,
                     p[500001], r, n[500001], m[500001], q, u, v, w, y, z;
  string s, t, x;
  cin >> a;
  if (a <= 9) {
    cout << a;
    exit(0);
  }
  if (a >= 10 && a <= 189) {
    if (a % 2 == 0) {
      cout << ((a - 10) / 2 + 10) / 10;
    } else {
      cout << ((a - 10) / 2 + 10) % 10;
    }
    exit(0);
  }
  if (a % 3 == 1) {
    cout << ((a - 190) / 3 + 100) / 100;
  }
  if (a % 3 == 2) {
    cout << ((a - 190) / 3 + 100) % 100 / 10;
  }
  if (a % 3 == 0) {
    cout << ((a - 190) / 3 + 100) % 10;
  }
}
