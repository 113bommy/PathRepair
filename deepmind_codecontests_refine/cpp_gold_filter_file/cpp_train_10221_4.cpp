#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (a != 0 && b != 0) {
    if (a >= b)
      a %= b;
    else
      b %= a;
  }
  return a > b ? a : b;
}
int main() {
  long long n, m, q;
  cin >> n >> m >> q;
  long long g = gcd(n, m);
  long long nd = n / g;
  long long md = m / g;
  for (int i = 0; i < q; i++) {
    long long a, b, c, d, e, f;
    cin >> a >> b >> c >> d;
    b--;
    d--;
    if (a == 1)
      e = b / nd;
    else
      e = b / md;
    if (c == 1)
      f = d / nd;
    else
      f = d / md;
    if (e == f)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
