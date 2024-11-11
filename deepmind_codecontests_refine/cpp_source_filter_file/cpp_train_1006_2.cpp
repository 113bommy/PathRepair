#include <bits/stdc++.h>
using namespace std;
int c[100010], f[100010], h[100010], dp[550][5010];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n * k; i++) {
    int x;
    scanf("%d", &x);
    c[x]++;
  }
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    f[x]++;
  }
  for (int i = 1; i <= k; i++) scanf("%d", &h[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= n * k; j++)
      for (int l = 0; l <= k; l++)
        dp[i][j + l] = max(dp[i][j + l], dp[i - 1][j] + h[l]);
  int ans = 0;
  for (int i = 1; i <= 100000; i++)
    if (f[i] != 0) ans += dp[f[i]][c[i]];
  printf("%d\n", ans);
  return 0;
}
