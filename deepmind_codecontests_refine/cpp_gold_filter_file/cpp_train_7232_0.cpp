#include <bits/stdc++.h>
const int mod = 1e9 + 7, maxn = 500100;
inline int ksm(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = 1ll * a * a % mod)
    if (b & 1) res = 1ll * res * a % mod;
  return res;
}
int fac[maxn], invfac[maxn], f[maxn];
inline int C(int n, int m) {
  return (n < 0 || n < m)
             ? 0
             : 1ll * fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}
char s[maxn];
int n, k;
int main() {
  for (int i = fac[0] = 1; i < maxn; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  invfac[maxn - 1] = ksm(fac[maxn - 1], mod - 2);
  for (int i = maxn - 2; i >= 0; i--)
    invfac[i] = 1ll * invfac[i + 1] * (i + 1) % mod;
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  int ans = 0;
  for (int i = n - 1; i; i--)
    f[i] = (f[i + 1] + 1ll * ksm(10, n - i - 1) * C(i - 1, k - 1) % mod) % mod;
  for (int i = 1; i <= n; i++)
    f[i] = (f[i] + 1ll * ksm(10, n - i) * C(i - 1, k) % mod) % mod;
  for (int i = 1; i <= n; i++)
    ans = (ans + 1ll * f[i] * (s[i] - '0') % mod) % mod;
  printf("%d\n", ans);
  return 0;
}
