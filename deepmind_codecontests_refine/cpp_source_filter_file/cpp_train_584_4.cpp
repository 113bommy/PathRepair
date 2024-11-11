#include <bits/stdc++.h>
using namespace std;
long long m = 6, n = 11, t, x, pi[22], sp = 762939453125;
long long mul(long long x, long long y, long long mo) {
  long long z = 0;
  while (y) {
    if (y % 2) z = (x + z) % mo;
    x = (x + x) % mo;
    y /= 2;
  }
  return z;
}
long long po(long long x, long long y, long long mo) {
  long long z = 1;
  while (y) {
    if (y % 2) z = mul(x, z, mo);
    x = mul(x, x, mo);
    y /= 2;
  }
  return z;
}
int main() {
  cin >> t;
  pi[1] = 1;
  pi[2] = 4;
  for (int i = 3; i <= 20; i++) pi[i] = pi[i - 1] * 5;
  while (t--) {
    cin >> x;
    x = x * 1000000;
    long long y = (1 << (n + m));
    if (x % y == 0)
      x /= y;
    else
      x = (x / y) + 1;
    while (x % 5 == 0) x++;
    long long la = 1, qu = 5, an = 0;
    for (int i = 1; i <= n + m; i++) {
      long long y = po(2, pi[i], sp);
      while (la % qu != x % qu) {
        la = mul(la, y, sp);
        an += pi[i];
      }
      qu = qu * 5;
    }
    cout << an + 7 << endl;
  }
  return 0;
}
