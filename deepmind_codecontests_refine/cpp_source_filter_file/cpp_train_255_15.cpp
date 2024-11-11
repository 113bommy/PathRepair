#include <bits/stdc++.h>
using namespace std;
int dp[1 << 21], cost[21][21], n, m, cost2[21][21], id[21][21];
char str[21][21];
int main() {
  int i, j, k, ans, N, lowbit;
  while (scanf("%d%d", &n, &m) != EOF) {
    N = 1 << n;
    memset(cost2, 0, sizeof(cost2));
    memset(id, 0, sizeof(id));
    for (i = 0; i < n; i++) scanf("%s", str[i]);
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) scanf("%d", &cost[i][j]);
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) {
        int mx = 0;
        for (k = 0; k < n; k++)
          if (str[i][j] == str[k][j]) {
            cost2[i][j] += cost[k][j];
            id[i][j] += (1 << k);
            mx = max(mx, cost[k][j]);
          }
        cost2[i][j] -= mx;
      }
    for (i = 1; i < N; i++) {
      dp[i] = 2100000000;
      for (j = 0; j < n; j++)
        if ((1 << j) & i) {
          lowbit = j;
          break;
        }
      for (j = 0; j < m; j++) {
        dp[i] = min(dp[i], dp[i ^ (1 << lowbit) & i] + cost[lowbit][j]);
        dp[i] = min(dp[i], dp[i ^ id[lowbit][j]] + cost2[lowbit][j]);
      }
    }
    printf("%d\n", dp[N - 1]);
  }
  return 0;
}
