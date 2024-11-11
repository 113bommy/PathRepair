#include <bits/stdc++.h>
int t[25], g[25];
long long f[1000005][25], ans, mo = 1000000007;
int main() {
  int n, T;
  scanf("%d%d", &n, &T);
  for (int i = 1; i <= n; i++) scanf("%d%d", &t[i], &g[i]);
  for (int i = 0; i < n; i++) f[1 << i][i] = 1;
  for (int i = 0; i < 1 << n; i++) {
    int sum = 0;
    for (int j = 1; j <= n; j++)
      if (i & (1 << j - 1)) {
        int pre = i ^ (1 << j - 1);
        for (int k = 1; k <= n; k++)
          if (pre & (1 << k - 1) && j != k && g[j] != g[k])
            f[i][j - 1] = (f[i][j - 1] + f[pre][k - 1]) % mo;
        sum += t[j];
      }
    if (sum == T)
      for (int j = 1; j <= n; j++)
        if (i & (1 << j - 1)) ans = (ans + f[i][j - 1]) % mo;
  }
  printf("%lld\n", ans);
}
