#include <bits/stdc++.h>
using namespace std;
int dis[20][20], du[20];
int dp[1 << 16], ans;
void floyd(int n) {
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
}
int solve(int n) {
  for (int i = 1; i < n; i++) {
    if (du[i] && dis[0][i] == 0x3f3f3f3f) return -1;
  }
  int tmp = 1 << n, i, j, k;
  memset(dp, 0x3f3f3f3f, sizeof(dp));
  dp[0] = 0;
  for (i = 0; i < tmp; i++) {
    for (j = 0; j < n; j++) {
      if ((du[j] & 1) && (i & (1 << j))) break;
    }
    if (j == n) dp[i] = 0;
    for (j = 0; j < n; j++) {
      if (!(i & (1 << j)) && (du[j] & 1)) {
        for (k = j + 1; k < n; k++) {
          if (!(i & (1 << k)) && (du[j] & 1) && dis[j][k] < 0x3f3f3f3f) {
            dp[i | (1 << j) | (1 << k)] =
                min(dp[i | (1 << j) | (1 << k)], dp[i] + dis[j][k]);
          }
        }
      }
    }
  }
  if (dp[tmp - 1] >= 0x3f3f3f3f) return -1;
  return ans + dp[tmp - 1];
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  memset(dis, 0x3f3f3f3f, sizeof(dis));
  ans = 0;
  for (int i = 0; i <= n; i++) dis[i][i] = 0;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    u--, v--;
    dis[u][v] = dis[v][u] = min(dis[u][v], w);
    du[u]++, du[v]++;
    ans += w;
  }
  floyd(n);
  printf("%d\n", solve(n));
  return 0;
}
