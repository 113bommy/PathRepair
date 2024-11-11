#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const int inf = 1 << 28;
int dp[N][N][N], vis[N][N][N];
int dis[N][N];
int solve(int l, int r, int k) {
  if (k == 0) return 0;
  if (vis[l][r][k]) return dp[l][r][k];
  vis[l][r][k] = 1;
  dp[l][r][k] = inf;
  int L = min(l, r), R = max(l, r);
  for (int i = L + 1; i < R; i++) {
    if (dis[l][i] != inf)
      dp[l][r][k] = min(
          dp[l][r][k], min(solve(i, l, k - 1), solve(i, r, k - 1)) + dis[l][i]);
  }
  return dp[l][r][k];
}
int main() {
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);
  ;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dis[i][j] = inf;
    }
  }
  int m;
  scanf("%d", &m);
  ;
  while (m--) {
    int u, v, dif;
    scanf("%d", &u);
    scanf("%d", &v);
    scanf("%d", &dif);
    ;
    dis[u][v] = min(dif, dis[u][v]);
  }
  int ans = solve(0, n + 1, k);
  printf("%d ", ans == inf ? -1 : ans);
  ;
  printf("\n");
  ;
  return 0;
}
