#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1010];
int dp[1010];
int po[6][1010];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    po[1][a[i]] = i;
  }
  for (int i = 2; i <= m; i++)
    for (int j = 1; j <= n; j++) {
      int x;
      scanf("%d", &x);
      po[i][x] = j;
    }
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++) {
      bool ok = 1;
      for (int k = 1; k <= m; k++)
        if (po[k][a[i]] < po[k][a[j]]) {
          ok = 0;
          break;
        }
      if (ok) dp[i] = max(dp[j] + 1, dp[i]);
    }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
  printf("%d\n", ans);
  return 0;
}
