#include <bits/stdc++.h>
using namespace std;
const int N = 52;
int n, m, dis[N][N], g1, g2, s1, s2;
vector<int> vd[N];
long long ans = 0, dp[N][N][N];
int main() {
  scanf("%d%d", &n, &m);
  memset(dis, 63, sizeof dis);
  for (int i = 1; i <= n; i++) dis[i][i] = 0;
  int u, v, c;
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &u, &v, &c);
    dis[u][v] = dis[v][u] = c;
  }
  scanf("%d%d%d%d", &g1, &g2, &s1, &s2);
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (dis[i][j] > dis[i][k] + dis[k][j])
          dis[i][j] = dis[i][k] + dis[k][j];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      if (i != j) vd[i].push_back(dis[i][j] * 10000 + i);
    sort((vd[i]).begin(), (vd[i]).end());
  }
  for (int gcity = 1; gcity <= n; gcity++)
    for (int bcity = 1; bcity <= n; bcity++) {
      if (gcity == bcity) continue;
      if (vd[bcity][n - 2] < vd[gcity][0]) continue;
      int hig = vd[gcity][0], lowb = vd[bcity][n - 2];
      dp[0][0][0] = 1;
      for (int i = 1; i <= n; i++)
        for (int g = 0; g <= g2; g++)
          for (int b = 0; b <= n - g; b++) {
            dp[i][g][b] = 0;
            if (i == gcity) {
              if (g) dp[i][g][b] += dp[i - 1][g - 1][b];
              continue;
            } else if (i == bcity) {
              if (b) dp[i][g][b] += dp[i - 1][g][b - 1];
              continue;
            }
            if (g && vd[i][0] < hig) dp[i][g][b] += dp[i - 1][g - 1][b];
            if (b && vd[i][n - 2] > lowb) dp[i][g][b] += dp[i - 1][g][b - 1];
            if (vd[i][n - 2] > hig &&
                *upper_bound((vd[i]).begin(), (vd[i]).end(), hig) < lowb)
              dp[i][g][b] += dp[i - 1][g][b];
          }
      for (int cntg = g1; cntg <= g2; cntg++)
        for (int cnts = s1; cnts <= s2; cnts++)
          ans += dp[n][cntg][n - cntg - cnts];
    }
  printf("%I64d\n", ans);
  return 0;
}
