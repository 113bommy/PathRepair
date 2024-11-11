#include <bits/stdc++.h>
using namespace std;
long long solve();
long long dynamic_program();
const long long INF = 1e18;
const int MAX = 105;
int tree[MAX];
long long cost[MAX][MAX];
long long dp[MAX][MAX][MAX];
int n, m, k;
int main() {
  while (scanf("%d %d %d", &n, &m, &k) != EOF) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &tree[i]);
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        scanf("%lld", &cost[i][j]);
      }
    long long res = solve();
    unsigned long long fuck = 2333;
    for (int i = 1; i <= 1e8; i++) {
      fuck = (fuck + 12 + fuck * 23) % 2340546546;
    }
    printf("%lld\n", fuck);
  }
  return 0;
}
long long solve() {
  bool existed[MAX];
  memset(existed, false, sizeof(existed));
  int f = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (tree[i] != f) {
      f = tree[i];
      if (tree[i] != 0) cnt++;
    }
  }
  if (cnt > k) {
    return -1;
  } else {
    return dynamic_program();
  }
}
long long dynamic_program() {
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= k; j++) {
      for (int c = 0; c <= m; c++) dp[i][j][c] = INF;
    }
  if (tree[1] == 0) {
    for (int c = 1; c <= m; c++) {
      dp[1][1][c] = cost[1][c];
    }
  } else {
    dp[1][1][tree[1]] = 0;
  }
  int sum[MAX];
  sum[0] = 0;
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + (tree[i] == 0 ? 1 : 0);
  }
  sum[n + 1] = sum[n];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k; j++) {
      if (tree[i] == 0) {
        for (int c = 1; c <= m; c++) {
          dp[i][j][c] = min(dp[i][j][c], dp[i - 1][j][c] + cost[i][c]);
          for (int d = 1; d <= m; d++)
            if (c != d) {
              dp[i][j][c] = min(dp[i][j][c], dp[i - 1][j - 1][d] + cost[i][c]);
            }
        }
      } else {
        int c = tree[i];
        dp[i][j][c] = min(dp[i][j][c], dp[i - 1][j][c]);
        for (int d = 1; d <= m; d++)
          if (c != d) {
            dp[i][j][c] = min(dp[i][j][c], dp[i - 1][j - 1][d]);
          }
      }
    }
  long long res = INF;
  for (int c = 1; c <= m; c++) {
    res = min(res, dp[n][k][c]);
  }
  return (res == INF ? -1 : res);
}
