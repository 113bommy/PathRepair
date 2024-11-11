#include <bits/stdc++.h>
const int N = 1000005;
long long d, x, y, n, lcm, ans, a[N], r[N];
inline long long mul(long long x, long long l, long long p) {
  if (l < 0) x = -x, l = -l;
  long long now = 1;
  while (l) {
    if (l & 1) now = (now + x) % p;
    l >>= 1, x = (x + x) % p;
  }
  return now;
}
inline void exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    d = a, x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x), y -= a / b * x;
}
inline void gcd(long long a, long long b) {
  if (!b) {
    d = a;
    return;
  }
  gcd(b, a % b);
}
inline void china() {
  long long m = a[1], ys = r[1];
  for (register int i = 2; i <= n; ++i) {
    long long A = m, b = a[i], c = r[i] - ys, X, Y;
    exgcd(A, b, X, Y);
    if (c % d) {
      ans = -1;
      return;
    }
    A /= d, b /= d, c /= d, X = (mul(X, c, b) + b) % b;
    ys += X * m, m *= a[i] / d, ys = (ys + m) % m;
  }
  ys = (ys + m - 1) % m + 1;
  if (ys < 1 || ys + n - 1 > y) {
    ans = -1;
    return;
  }
  ans = ys;
}
inline void fr(long long &num) {
  num = 0;
  char c = getchar();
  int p = 1;
  while (c < '0' || c > '9') c == '-' ? p = -1, c = getchar() : c = getchar();
  while (c >= '0' && c <= '9') num = num * 10 + c - '0', c = getchar();
  num *= p;
}
int main() {
  fr(x), fr(y), fr(n);
  lcm = 1;
  for (register int i = 1; i <= n; ++i) {
    fr(a[i]), gcd(a[i], lcm), lcm = lcm / d * a[i];
    if (lcm > x) return puts("NO"), 0;
    r[i] = ((a[i] - i + 1) % a[i] + a[i]) % a[i];
  }
  china();
  if (ans == -1) return puts("NO"), 0;
  for (register int i = 1; i <= n; ++i) {
    gcd(lcm, ans + i - 1);
    if (d != a[i]) return puts("NO"), 0;
  }
  puts("YES");
  return 0;
}
