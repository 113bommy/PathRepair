#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long lca(long long a, long long b) { return a / gcd(a, b) * b; }
int main() {
  long long n;
  int y1, y2, yw, xb, yb, r;
  cin >> y1 >> y2 >> yw >> xb >> yb >> r;
  long double x, L = 0, R = xb;
  long double vX, vY = yw - r - yb;
  while (abs(R - L) > 1e-12) {
    long double m = (L + R) / 2;
    vX = abs(m - (long double)xb);
    long double t = m / vX;
    long double yres = (long double)yw - (long double)r - (long double)vY * t;
    long double A = vY, B = vX, C = -B * yres;
    bool bad = false;
    if (abs((B * y2 + C) / sqrt(A * A + B * B)) <= r) bad = true;
    if (yres < y1)
      R = m;
    else if (yres < y2 - r && yres > y1 + r && !bad) {
      cout << fixed << setprecision(12) << m;
      return 0;
    } else if (yres >= y2 - r || bad)
      L = m;
    else
      R = m;
  }
  cout << -1;
  return 0;
}
