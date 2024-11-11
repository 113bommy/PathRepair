#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b, long long &x, long long &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1;
  long long d = gcd(b % a, a, x1, y1);
  y = x1;
  x = y1 - (b / a) * x1;
  return d;
}
bool find_solve(long long a, long long b, long long c, long long &x,
                long long &y, long long &g) {
  g = gcd(abs(a), abs(b), x, y);
  if (c % g != 0) {
    return 0;
  }
  x *= (c / g);
  y *= (c / g);
  if (a < 0) x *= -1;
  if (b < 0) y *= -1;
  return 1;
}
long long step, k, step2, le;
long long get_len(long double l, long double r) {
  long double tl = min(l, r);
  long double tr = min(max(l, r), ((long double)le / step2));
  if (tl > tr) {
    return 0;
  }
  if (tr > (long long)(tr)) tr = (long long)(tr);
  if (tl < (long long)(tl)) tl = (long long)(tl);
  return tr - tl + 1;
}
signed main() {
  long long a1, b1, a2, b2, g, k1, k2, l;
  long double L, R;
  cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
  if (!find_solve(a1, -a2, b2 - b1, k, l, g) || R - b1 < 0) {
    cout << 0;
    return 0;
  }
  step = -a2 / gcd(a1, a2, k1, k2);
  step2 = a1 / gcd(a1, a2, k1, k2);
  le = l;
  long long ans = 0;
  L = max((long double)(L - b1) / a1, (long double)0);
  R = (R - b1) / a1;
  cout << get_len((R - k) / step, (L - k) / step) << endl;
  return 0;
}
