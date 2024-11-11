#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  long long x, y, z, a, b, p, q;
  string g;
  cin >> g;
  x = (g[0] - 48) * 10 + (g[1] - 48);
  y = (g[3] - 48) * 10 + (g[4] - 48);
  p = x;
  q = y;
  while (2) {
    if (x == 24) x = 0;
    a = x % 10;
    b = x / 10;
    z = a * 10 + b;
    if ((x == p) && y == q) {
      if (z <= y)
        ;
      else if (z <= 60) {
        cout << b << a << ":" << a << b;
        return 0;
      }
    } else if ((z <= 60)) {
      cout << b << a << ":" << a << b;
      return 0;
    }
    x++;
  }
}
