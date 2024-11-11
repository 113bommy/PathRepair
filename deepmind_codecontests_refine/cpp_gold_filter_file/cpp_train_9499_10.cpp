#include <bits/stdc++.h>
int const mod = 998244353;
int E[5010][5010], C[5010][5010], fac[5010];
int n;
int main() {
  scanf("%d", &n);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (int i = 0; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  }
  for (int i = 0; i <= n; i++) {
    E[i][0] = 1;
    for (int j = 1; j < i; j++)
      E[i][j] =
          (1ll * (j + 1) * E[i - 1][j] + 1ll * (i - j) * E[i - 1][j - 1]) % mod;
  }
  for (int i = 1; i <= n; i++) {
    int ans = 0;
    for (int j = 1; j <= n; j++)
      ans = (ans + 1ll * E[j][i - 1] * C[n][j] % mod * fac[n - j]) % mod;
    printf("%d ", ans);
  }
  return 0;
}
