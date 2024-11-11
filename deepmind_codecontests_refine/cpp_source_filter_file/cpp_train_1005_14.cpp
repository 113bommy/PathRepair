#include <bits/stdc++.h>
using namespace std;
int a[10000], sum, L[10000], apr[100100], tot[10000], dp[5002][502], v[510];
int main() {
  int n, m, i, j, k;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n * m; i++) scanf("%d", &a[i]);
  for (i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (!apr[x]) {
      sum++;
      apr[x] = sum;
    }
    v[apr[x]]++;
  }
  for (i = 1; i <= m; i++) scanf("%d", &L[i]);
  for (i = 1; i <= n * m; i++)
    if (apr[a[i]]) tot[apr[a[i]]]++;
  int ans = 0;
  for (int _ = 1; _ <= sum; _++) {
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = 0;
    int t = v[_];
    for (i = 1; i <= t; i++)
      for (j = 0; j <= min(tot[_], i * m); j++)
        for (k = 0; k <= min(j, m); k++)
          dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + L[k]);
    ans += dp[t][min(tot[_], t * m)];
  }
  printf("%d\n", ans);
  return 0;
}
