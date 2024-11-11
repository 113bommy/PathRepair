#include <bits/stdc++.h>
using namespace std;
namespace modular {
const int mod = 1000000007;
inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int dec(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
}  // namespace modular
using namespace modular;
inline int poww(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = mul(ans, a);
    a = mul(a, a);
    b >>= 1;
  }
  return ans;
}
const int inv2 = poww(2, mod - 2);
const int inv3 = poww(3, mod - 2);
inline int read() {
  int x = 0, f = 1;
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
int T;
int f(int a, int b, int c, int n) {
  return add(add(mul(a, mul(n, n)), mul(b, n)), c);
}
int s(int n) { return (n / 3) + (n % 3); }
int t(int n) {
  int nn = n / 3;
  int res = f(mul(3, inv2), mul(5, inv2), 0, nn);
  for (int i = nn * 3 + 1; i <= n; i++) res = add(res, s(i));
  return res;
}
int a(int n) {
  int nn = n / 3;
  int res = mul(nn, f(mul(3, inv2), mul(9, inv2), 2, nn));
  for (int i = nn * 3 + 1; i <= n; i++) res = add(res, t(i));
  return res;
}
int b(int n) { return mul(n, f(inv2, 2, mul(3, inv2), n)); }
int c(int n) {
  int nn = n / 2;
  int res = mul(nn, f(1, mul(5, inv2), inv2, nn));
  if (n & 1) res = add(res, t((3ll * n - 1) / 2));
  return res;
}
int C1(int X, int Y) {
  X = min(X, 2 * Y), Y = min(Y, 2 * X);
  int mid = Y / 2;
  if (mid < 3) mid = 2;
  if (mid > X) mid = X;
  return dec(add(dec(b(mid), b(2)), dec(a(X + Y), a(mid + Y))),
             dec(c(X), c(2)));
}
int S1(int n) {
  int opt = n % 4;
  if (!opt) return mul(f(1, mod - 3, mod - 4, n), mul(inv2, inv2));
  if (opt == 1) return mul(f(1, mod - 1, mod - 8, n), mul(inv2, inv2));
  if (opt == 2) return mul(f(1, mod - 3, mod - 2, n), mul(inv2, inv2));
  return mul(f(1, mod - 1, mod - 6, n), mul(inv2, inv2));
}
int d(int n) {
  int nn = n / 4;
  int res = mul(nn, f(mul(16, inv3), mod - 2, dec(0, mul(19, inv3)), nn));
  for (int i = nn * 4 + 1; i <= n; i++) res = add(res, S1(i));
  return res;
}
int up(int x) { return (x + 1) / 2; }
int S2(int n, int Y) {
  int opt = n % 4;
  if (!opt) return dec(add(mul(n / 2, Y - 1), (Y + 1) / 2), 1);
  if (opt == 1) return dec(add(mul((n + 1) / 2, Y - 1), (Y + 1) / 2), 1);
  if (opt == 2) return add(mul(n / 2, Y - 1), Y / 2);
  return add(mul((n + 1) / 2, Y - 1), Y / 2);
}
int e(int n, int Y) {
  int nn = n / 4;
  int res = mul(dec(mul(4, Y), 4), add(mul(nn, nn), nn));
  for (int i = nn * 4 + 1; i <= n; i++) res = add(res, S2(i, Y));
  return res;
}
int C2(int X, int Y) {
  if (2 * Y + 2 >= X) return dec(d(X), d(4));
  return add(dec(d(2 * Y + 2), d(4)), dec(e(X, Y), e(2 * Y + 2, Y)));
}
int P(int X, int Y) {
  if (X < 2 || Y < 2) return 0;
  int ans = 0;
  for (int i = 2; i <= min(4, Y); i++) ans += 6 - i;
  ans = add(ans, C1(X, Y));
  ans = add(ans, C2(X, Y));
  ans = add(ans, C2(Y, X));
  return ans;
}
int main() {
  T = read();
  while (T--) {
    int x = read() - 1, y = read() - 1, n = read() - 1, m = read() - 1;
    printf("%d\n",
           dec(add(P(n, m), P(x - 1, y - 1)), add(P(x - 1, m), P(n, y - 1))));
  }
  return 0;
}
