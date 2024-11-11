#include <bits/stdc++.h>
using namespace std;
int rd() {
  int ret = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
  return f ? ret : -ret;
}
int Max(int x, int y) { return x > y ? x : y; }
int const xm = (1 << 17) + 5, mod = 1e9 + 7;
int n, p[xm], F[xm], f[20][xm], g[xm], h[xm], t[xm], bin[25], cnt[xm], inv2, lm;
long long pw(long long a, int b) {
  long long ret = 1;
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) ret = ret * a % mod;
  return ret;
}
int upt(int x) {
  while (x >= mod) x -= mod;
  while (x < 0) x += mod;
  return x;
}
int cal(int s) {
  int ret = 0;
  while (s) ret += (s & 1), s >>= 1;
  return ret;
}
int get(int x) {
  int ret = 0;
  while (x) ret++, x >>= 1;
  return ret;
}
void init() {
  F[0] = 0;
  F[1] = 1;
  for (int i = 2; i < bin[lm]; i++) F[i] = upt(F[i - 1] + F[i - 2]);
}
void fmt(int *a, int tp) {
  for (int d = 1; d < bin[lm]; d <<= 1)
    for (int s = 0; s < bin[lm]; s++)
      if (s & d) a[s] = upt(a[s] + a[s ^ d] * tp);
}
void fwt1(int *a, int tp) {
  for (int mid = 1; mid < bin[lm]; mid <<= 1)
    for (int j = 0, len = (mid << 1); j < bin[lm]; j += len)
      for (int k = 0; k < mid; k++)
        a[j + k] = upt(a[j + k] + a[j + mid + k] * tp);
}
void fwt2(int *a, int tp) {
  for (int mid = 1; mid < bin[lm]; mid <<= 1)
    for (int j = 0, len = (mid << 1); j < bin[lm]; j += len)
      for (int k = 0; k < mid; k++) {
        int x = a[j + k], y = a[j + mid + k];
        a[j + k] = upt(x + y);
        a[j + mid + k] = upt(x - y);
        if (tp == -1)
          a[j + k] = (long long)a[j + k] * inv2 % mod,
                a[j + mid + k] = (long long)a[j + mid + k] * inv2 % mod;
      }
}
int main() {
  n = rd();
  lm = 18;
  bin[0] = 1;
  for (int i = 1; i <= lm; i++) bin[i] = bin[i - 1] * 2;
  for (int s = 0; s < bin[lm]; s++) cnt[s] = cal(s);
  int mx = 0;
  for (int i = 1, x; i <= n; i++) x = rd(), p[x]++, mx = Max(mx, x);
  lm = get(mx) + 1;
  init();
  for (int s = 0; s < bin[lm]; s++) f[cnt[s]][s] = p[s];
  for (int i = 0; i < lm; i++) fmt(f[i], 1);
  for (int i = 1; i < lm; i++) {
    memset(t, 0, sizeof t);
    for (int j = 0; j <= i; j++)
      for (int s = 0; s < bin[lm]; s++)
        t[s] = (t[s] + (long long)f[j][s] * f[i - j][s]) % mod;
    fmt(t, -1);
    for (int s = 0; s < bin[lm]; s++)
      if (cnt[s] == i) g[s] = upt(g[s] + t[s]);
  }
  for (int s = 0; s < bin[lm]; s++) h[s] = p[s];
  inv2 = pw(2, mod - 2);
  fwt2(h, 1);
  for (int s = 0; s < bin[lm]; s++) h[s] = (long long)h[s] * h[s] % mod;
  fwt2(h, -1);
  for (int s = 0; s < bin[lm]; s++) g[s] = (long long)g[s] * F[s] % mod;
  for (int s = 0; s < bin[lm]; s++) h[s] = (long long)h[s] * F[s] % mod;
  for (int s = 0; s < bin[lm]; s++) p[s] = (long long)p[s] * F[s] % mod;
  fwt1(g, 1);
  fwt1(h, 1);
  fwt1(p, 1);
  for (int s = 0; s < bin[lm]; s++)
    g[s] = (long long)g[s] * h[s] % mod * p[s] % mod;
  fwt1(g, -1);
  int ans = 0;
  for (int i = 0; i < lm; i++) ans = upt(ans + g[bin[i]]);
  printf("%d\n", ans);
  return 0;
}
