#include <bits/stdc++.h>
using namespace std;
const int N = 1000100, P = 998244353;
inline char gc() {
  static char buf[N], *s = buf, *t = buf;
  return s == t && (t = (s = buf) + fread(buf, 1, N, stdin), s == t) ? EOF
                                                                     : *s++;
}
inline int read() {
  int x = 0, f = 0, c = getchar();
  for (; c > '9' || c < '0'; f = c == '-', c = getchar())
    ;
  for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + c - '0';
  return f ? -x : x;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline int ksm(int x, int y) {
  int z = 1;
  for (; y; y >>= 1, x = 1ll * x * x % P)
    if (y & 1) z = 1ll * z * x % P;
  return z;
}
int n, fac[N], inv[N], ans;
inline int C(int n, int m) {
  return 1ll * fac[n] * inv[m] % P * inv[n - m] % P;
}
int main() {
  register int i, k;
  n = read();
  fac[0] = 1;
  ans = ksm(3, 1ll * n * n % (P - 1));
  for (i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % P;
  inv[n] = ksm(fac[n], P - 2);
  for (i = n; i >= 1; i--) inv[i - 1] = 1ll * inv[i] * i % P;
  for (i = 1; i <= n; i++) {
    k = (1ll * (n - i) * n + i) % (P - 1);
    k = ksm(3, k);
    k = (k + k) % P * C(n, i) % P;
    if (i & 1) k = P - k;
    ans = (ans + k) % P;
  }
  for (i = 1; i <= n; i++) {
    k = ksm(3, i - n + P - 1) - 1;
    k = ksm(k, n);
    if (n & 1)
      k = (k + 1) % P;
    else
      k = (k - 1 + P) % P;
    k = 1ll * k * ksm(3, (1ll * (n - i) * n + 1) % (P - 1)) % P * C(n, i) % P;
    if ((n + i) & 1) k = P - k;
    ans = (ans + k) % P;
  }
  ans = ksm(3, 1ll * n * n % (P - 1)) - ans;
  ans = (ans + P) % P;
  printf("%d\n", ans);
  return 0;
}
