#include <bits/stdc++.h>
long long ans, c[2005][2005];
int n, m, k;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) c[i][0] = c[i][i] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 998244353;
  ans = c[n - 1][k] * m % 998244353;
  for (int i = 2; i <= k; i++) ans = ans * (m - 1) % 998244353;
  printf("%I64d\n", ans);
}
