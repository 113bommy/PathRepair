#include <bits/stdc++.h>
int read() {
  int r = 0, t = 1, c = getchar();
  while (c < '0' || c > '9') {
    t = c == '-' ? -1 : 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    r = (r << 3) + (r << 1) + (c ^ 48);
    c = getchar();
  }
  return r * t;
}
const int N = 1 << 21 | 10;
long long n, a[N], f[N], m = 6, p[N] = {0, 1, 10, 100, 1000, 10000, 100000};
inline void Max(long long &a, long long b) {
  if (a < b) a = b;
}
void solve(int n, int i) {
  for (int I = (0), end_I = (30); I <= end_I; I++)
    if (n >> I) {
      long long d = p[i] << I;
      long long D = a[i] << I;
      for (int j = (333333), end_j = (d); j >= end_j; j--)
        Max(f[j], f[j - d] + D);
      n -= 1ll << I;
    }
  for (int I = (0), end_I = (30); I <= end_I; I++)
    if ((n >> I) & 1) {
      long long d = p[i] << I;
      long long D = a[i] << I;
      for (int j = (333333), end_j = (d); j >= end_j; j--)
        Max(f[j], f[j - d] + D);
    }
}
long long calc(long long a, long long b) {
  if (b == 7) return 0;
  return calc(a / 10, b + 1) + (a % 10 % 3 == 0 ? a % 10 / 3 * ::a[b] : 0);
}
int main() {
  n = (read() - 1) * 3;
  for (int i = (1), end_i = (m); i <= end_i; i++) a[i] = read();
  for (int i = (1), end_i = (333333); i <= end_i; i++) f[i] = -1ll << 60;
  f[0] = 0;
  for (int i = (1), end_i = (6); i <= end_i; i++)
    solve(std::min(n, 333333 / p[i]), i);
  for (int i = (1), end_i = (read()); i <= end_i; i++) {
    int p = read();
    long long ans = 0;
    for (int j = (0), end_j = (p); j <= end_j; j++)
      if ((p - j) % 3 == 0) ans = std::max(ans, calc(j, 1) + f[(p - j) / 3]);
    printf("%I64d\n", ans);
  }
  return 0;
}
