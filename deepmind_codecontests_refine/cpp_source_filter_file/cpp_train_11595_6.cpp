#include <bits/stdc++.h>
using namespace std;
const long long mo = (long long)7e10;
struct Huge {
  long long A;
  long double B;
  Huge(long long A = 0, long double B = 0) : A(A), B(B) {}
  inline long long mul(const long long &x, const long long &y) {
    return (x / 100000ll * y % mo * 100000ll + x % 100000ll * y % mo) % mo;
  }
  inline Huge operator+(const int &v) const {
    return Huge((A + v) % mo, B + v);
  }
  inline Huge operator-(const int &v) const {
    return Huge((A - v) % mo, B - v);
  }
  inline Huge operator*(const int &v) const {
    return Huge((A * v) % mo, B * v);
  }
  inline Huge operator/(const int &v) const { return Huge(A / v, B / v); }
  inline Huge operator+(const Huge &x) const {
    return Huge((A + x.A) % mo, B + x.B);
  }
  inline Huge operator-(const Huge &x) const {
    return Huge((A - x.A) % mo, B - x.B);
  }
  inline Huge operator*(const Huge &x) { return Huge(mul(A, x.A), B * x.B); }
};
inline Huge sum(long long x) {
  Huge A = Huge(x, x), B = Huge(x + 1, x + 1), C = Huge(x * 2 + 1, x * 2 + 1);
  return A * B * C / 6;
}
inline Huge calc(long long x, long long y) {
  if (!x || !y) return Huge(0, 0);
  Huge n, m, sqr, res;
  n = Huge(x, x);
  m = Huge(y, y);
  if (x > y)
    sqr = Huge(y, y);
  else
    sqr = Huge(x, x);
  sqr = (sqr * sqr + 1) * sqr * sqr / 2;
  res = sqr;
  if (y > x) {
    res = res + n * (sum(y - 1) - sum(x - 1)) + n * (n + 1) * (m - n) / 2;
  } else {
    res = res + m * (sum(x) - sum(y)) - (n - m) * (m - 1) * m / 2;
  }
  return res;
}
inline void solve(long long x1, long long y1, long long x2, long long y2) {
  Huge ans = calc(x2, y2) + calc(x1, y1) - calc(x1, y2) - calc(x2, y1);
  while (ans.A < 0) ans.A += mo;
  ans.A %= (long long)1e10;
  if (ans.B >= 1e10)
    printf("%..%10I64d\n", ans.A);
  else
    printf("%I64d\n", ans.A);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long x1, x2, y1, y2;
    scanf("%I64d%I64d%I64d%I64d", &x1, &y1, &x2, &y2);
    solve(x1 - 1, y1 - 1, x2, y2);
  }
  return 0;
}
