#include <bits/stdc++.h>
using namespace std;
namespace modular {
const long long mod = 1000000007;
inline long long add(long long x, long long y) { return (x + y) % mod; }
inline long long dec(long long x, long long y) {
  return ((x - y) % mod + mod) % mod;
}
inline long long mul(long long x, long long y) { return x * y % mod; }
}  // namespace modular
using namespace modular;
inline long long poww(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = mul(ans, a);
    a = mul(a, a);
    b >>= 1;
  }
  return ans;
}
const long long inv2 = poww(2, mod - 2);
const long long inv3 = poww(3, mod - 2);
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ '0');
    ch = getchar();
  }
  return x * f;
}
long long T;
long long f(long long a, long long b, long long c, long long n) {
  return add(add(mul(a, mul(n, n)), mul(b, n)), c);
}
long long s(long long n) { return (n / 3) + (n % 3); }
long long t(long long n) {
  long long nn = n / 3;
  long long res = f(mul(3, inv2), mul(5, inv2), 0, nn);
  for (long long i = nn * 3 + 1; i <= n; i++) res = add(res, s(i));
  return res;
}
long long a(long long n) {
  long long nn = n / 3;
  long long res = mul(nn, f(mul(3, inv2), mul(9, inv2), 2, nn));
  for (long long i = nn * 3 + 1; i <= n; i++) res = add(res, t(i));
  return res;
}
long long b(long long n) { return mul(n, f(inv2, 2, mul(3, inv2), n)); }
long long c(long long n) {
  long long nn = n / 2;
  long long res = mul(nn, f(1, mul(5, inv2), inv2, nn));
  if (n & 1) res = add(res, t((3ll * n - 1) / 2));
  return res;
}
long long C1(long long X, long long Y) {
  X = min(X, 2 * Y), Y = min(Y, 2 * X);
  long long mid = Y / 2;
  if (mid < 3) mid = 2;
  if (mid > X) mid = X;
  return dec(add(dec(b(mid), b(2)), dec(a(X + Y), a(mid + Y))),
             dec(c(X), c(2)));
}
long long S1(long long n) {
  long long opt = n % 4;
  if (!opt) return mul(f(1, mod - 3, mod - 4, n), mul(inv2, inv2));
  if (opt == 1) return mul(f(1, mod - 1, mod - 8, n), mul(inv2, inv2));
  if (opt == 2) return mul(f(1, mod - 3, mod - 2, n), mul(inv2, inv2));
  return mul(f(1, mod - 1, mod - 6, n), mul(inv2, inv2));
}
long long d(long long n) {
  long long nn = n / 4;
  long long res = mul(nn, f(mul(16, inv3), mod - 2, dec(0, mul(19, inv3)), nn));
  for (long long i = nn * 4 + 1; i <= n; i++) res = add(res, S1(i));
  return res;
}
long long up(long long x) { return (x + 1) / 2; }
long long S2(long long n, long long Y) {
  long long opt = n % 4;
  if (!opt) return dec(add(mul(n / 2, Y - 1), (Y + 1) / 2), 1);
  if (opt == 1) return dec(add(mul((n + 1) / 2, Y - 1), (Y + 1) / 2), 1);
  if (opt == 2) return add(mul(n / 2, Y - 1), Y / 2);
  return add(mul((n + 1) / 2, Y - 1), Y / 2);
}
long long e(long long n, long long Y) {
  long long nn = n / 4;
  long long res = mul(dec(mul(4, Y), 4), add(mul(n, n), n));
  for (long long i = nn * 4 + 1; i <= n; i++) res = add(res, S2(i, Y));
  return res;
}
long long C2(long long X, long long Y) {
  if (2 * Y + 2 >= X) return dec(d(X), d(4));
  return add(dec(d(2 * Y + 2), d(4)), dec(e(X, Y), e(2 * Y + 2, Y)));
}
long long P(long long X, long long Y) {
  if (X < 2 || Y < 2) return 0;
  long long ans = 0;
  for (long long i = 2; i <= min(4ll, Y); i++) ans += 6 - i;
  ans = add(ans, C1(X, Y));
  ans = add(ans, C2(X, Y));
  ans = add(ans, C2(Y, X));
  return ans;
}
signed main() {
  T = read();
  while (T--) {
    long long x = read() - 1, y = read() - 1, n = read() - 1, m = read() - 1;
    printf("%lld\n",
           dec(add(P(n, m), P(x - 1, y - 1)), add(P(x - 1, m), P(n, y - 1))));
  }
  return 0;
}
