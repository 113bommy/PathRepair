#include <bits/stdc++.h>
using namespace std;
double cost[10][200], dp[200][10], beat[200][200];
int vis[10][200];
double dfs(int k, int p) {
  double ret;
  int i, x, kk, base, pos;
  if (k == 0) return 0.0;
  if (vis[k][p]) return cost[k][p];
  vis[k][p] = 1;
  x = p;
  ret = 0;
  dfs(k - 1, p);
  kk = (1 << k);
  if (p % kk == 0)
    pos = p / kk;
  else
    pos = p / kk + 1;
  base = (pos - 1) * kk;
  if (x <= (1 << (k - 1)) + base) {
    for (i = 1 + (1 << (k - 1)) + base; i <= base + (1 << k); i++) {
      ret = max(ret, dfs(k - 1, i));
    }
  } else {
    for (i = 1 + base; i <= (1 << (k - 1)) + base; i++) {
      ret = max(ret, dfs(k - 1, i));
    }
  }
  cost[k][p] = cost[k - 1][p] + ret + (1 << (k - 1)) * dp[p][k];
  return cost[k][p];
}
int main() {
  int i, j, n, k, kk, pos, base;
  double ans;
  scanf("%d", &n);
  for (i = 1; i <= (1 << n); i++) {
    for (j = 1; j <= (1 << n); j++) {
      scanf("%lf", &beat[i][j]);
      beat[i][j] /= 100.0;
    }
  }
  for (i = 1; i <= (1 << n); i++) {
    dp[i][0] = 1.0;
  }
  for (j = 1; j <= n; j++) {
    kk = (1 << j);
    for (i = 1; i <= (1 << n); i++) {
      int x = i;
      if (i % kk == 0)
        pos = i / kk;
      else
        pos = i / kk + 1;
      base = (pos - 1) * kk;
      if (x <= (1 << (j - 1)) + base) {
        for (k = 1 + (1 << (j - 1)) + base; k <= base + (1 << j); k++) {
          dp[i][j] += dp[i][j - 1] * dp[k][j - 1] * beat[i][k];
        }
      } else {
        for (k = 1 + base; k <= base + (1 << (j - 1)); k++) {
          dp[i][j] += dp[i][j - 1] * dp[k][j - 1] * beat[i][k];
        }
      }
    }
  }
  memset(vis, 0, sizeof(vis));
  ans = 0;
  for (i = 1; i <= (1 << n); i++) {
    ans = max(ans, dfs(n, i));
  }
  printf("%.12lf\n", ans);
  return 0;
}
