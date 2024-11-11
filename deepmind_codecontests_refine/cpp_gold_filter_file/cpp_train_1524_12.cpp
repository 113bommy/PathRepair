#include <bits/stdc++.h>
inline int read() {
  char c = getchar();
  int x = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - 48, c = getchar();
  return x;
}
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
int pre[maxn], fac[maxn], ifac[maxn], inv[maxn], f[maxn];
int n, m;
inline int C(int n, int m) {
  if (n < m) return 0;
  return 1ll * fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}
inline int qm(int x) { return x >= mod ? x - mod : x; }
inline int dqm(int x) { return x < 0 ? x + mod : x; }
inline int calc(int l, int r) {
  if (l <= 0) return pre[r];
  return dqm(pre[r] - pre[l - 1]);
}
int main() {
  n = read(), m = read();
  fac[0] = ifac[0] = inv[1] = 1;
  for (register int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (register int i = 2; i <= n; i++)
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  for (register int i = 1; i <= n; i++)
    ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;
  f[0] = 1;
  pre[0] = 1;
  for (register int i = 1; i < n; i++) {
    f[i] = 1ll * calc(i - m, i - 1) * fac[i - 1] % mod;
    pre[i] = qm(pre[i - 1] + 1ll * f[i] * ifac[i] % mod);
  }
  int ans = 0;
  for (register int i = 1; i <= n; i++)
    ans = qm(ans + 1ll * f[i - 1] * C(n - 1, i - 1) % mod * fac[n - i] % mod);
  printf("%d\n", dqm(fac[n] - ans));
  return 0;
}
