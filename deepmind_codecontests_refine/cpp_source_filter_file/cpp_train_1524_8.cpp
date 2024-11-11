#include <bits/stdc++.h>
const int mod = 1e9 + 7;
const int N = 1e6 + 50;
int ksm(int u, int v) {
  int res = 1;
  for (; v; v >>= 1, u = 1ll * u * u % mod)
    if (v & 1) res = 1ll * res * u % mod;
  return res;
}
int n, k, f[N], Sum, Ans, fac;
int main() {
  scanf("%d%d", &n, &k);
  f[0] = fac = 1;
  Ans = n;
  for (int i = 1; i <= n; i++) {
    Sum = (Sum + f[i - 1]) % mod;
    if (i > k) Sum = (Sum - f[i - k - 1]) % mod;
    f[i] = 1ll * Sum * ksm(i, mod - 2) % mod;
    Ans = (Ans - f[i - 1] + mod) % mod;
    if (i != 1) fac = 1ll * fac * (i - 1) % mod;
  }
  printf("%d\n", 1ll * fac * Ans % mod);
}
