#include <bits/stdc++.h>
using namespace std;
int a[5005];
long long dp[5005][5005], cost[5005];
pair<int, int> p[5005];
void dfs(int i, int s, int e, int optl, int optr) {
  if (s > e) return;
  int mid = (s + e) / 2;
  int opt = optl;
  dp[i][mid] = 1e18;
  for (int k = optl; k <= min(mid, optr); k++) {
    if (mid - k + 1 > p[i].second) continue;
    long long val = dp[i - 1][k - 1] + (cost[mid] - cost[k - 1]);
    if (dp[i][mid] >= val) {
      dp[i][mid] = val;
      opt = k;
    }
  }
  dfs(i, s, mid - 1, optl, opt);
  dfs(i, mid + 1, e, opt, optr);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++) dp[i][j] = 1e18;
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &p[i].first, &p[i].second);
  }
  sort(a + 1, a + 1 + n);
  sort(p + 1, p + 1 + m);
  long long ans = 1e18;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cost[j] = cost[j - 1] + abs(a[j] - p[i].first);
    }
    dfs(i, 1, n, 1, n);
    for (int j = 0; j <= n; j++) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
    ans = min(ans, dp[i][n]);
  }
  if (ans == 1e18) ans = -1;
  printf("%lld\n", ans);
}
