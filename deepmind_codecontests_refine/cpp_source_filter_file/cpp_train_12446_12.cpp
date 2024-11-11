#include <bits/stdc++.h>
using namespace std;
int64_t gcd(int64_t x, int64_t y, int64_t& t, int64_t& u) {
  if (y == 0) {
    t = 1;
    u = 0;
    return x;
  }
  int64_t res = gcd(y, x % y, t, u);
  int64_t c = t;
  t = u;
  u = c - u * (x / y);
  return res;
}
bool solve(int64_t a, int64_t b, int64_t c, int64_t& x, int64_t& y,
           int64_t& g) {
  g = gcd(a, b, x, y);
  if (c % g) return 0;
  x *= (c / g), y *= (c / g);
  return 1;
}
int64_t sg(int64_t a) {
  if (a < 0) return -1;
  return 1;
}
int64_t ceildiv(int64_t a, int64_t b) {
  if (a % b) {
    if (a > 0)
      return (a + b) / b;
    else
      return a / b;
  }
  return a / b;
}
int64_t floordiv(int64_t a, int64_t b) {
  if (a % b) {
    if (a > 0)
      return a / b;
    else
      return (a + b) / b;
  }
  return a / b;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int64_t a1, b1, a2, b2, l, r;
  cin >> a1 >> b1 >> a2 >> b2 >> l >> r;
  b2 -= b1, l -= b1, r -= b1, b1 = 0;
  int64_t x, y, g;
  if (!solve(a1, -a2, b2 - b1, x, y, g)) return cout << "0\n", 0;
  int64_t q = max(b1, b2);
  if (r < q) return cout << "0\n", 0;
  l = max(l, q);
  g = abs(g);
  int64_t xmin = (l - b1 + a1 - 1) / a1;
  int64_t xmax = (r - b1) / a1;
  int64_t d = a2 / g;
  int64_t kmin = ceildiv(xmin - x, d);
  int64_t kmax = floordiv(xmax - x, d);
  cout << kmax - kmin + 1 << "\n";
  return 0;
}
