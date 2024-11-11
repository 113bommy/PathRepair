#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const double eps = 1e-10;
const long long linf = 1e18 + 7;
const long long hh = 523;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
int G[57][57];
int mn[57], mx[57];
long long dp[57][57][57];
bool cang[57], cans[57], canb[57];
long long ans = 0;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      G[i][j] = inf;
    }
  }
  for (int i = 0; i < m; i++) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    x--;
    y--;
    G[x][y] = min(G[x][y], w);
    G[y][x] = min(G[y][x], w);
  }
  for (int i = 0; i < n; i++) {
    G[i][i] = 0;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    mn[i] = inf;
    for (int j = 0; j < n; j++) {
      if (j == i) {
        continue;
      }
      G[i][j] = G[i][j] * 100 + i;
      mn[i] = min(mn[i], G[i][j]);
      mx[i] = max(mx[i], G[i][j]);
    }
  }
  int g1, g2, s1, s2;
  scanf("%d%d%d%d", &g1, &g2, &s1, &s2);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int best = mn[i];
      int worst = mx[j];
      if (i == j || best > worst) {
        continue;
      }
      for (int k = 0; k < n; k++) {
        cang[k] = mn[k] <= best;
        canb[k] = mx[k] >= worst;
        cans[k] = false;
        for (int z = 0; z < n; z++) {
          if (z == k) {
            continue;
          }
          if (G[k][z] < worst && G[k][z] > best) {
            cans[k] = true;
          }
        }
      }
      cans[i] = false;
      canb[i] = false;
      cans[j] = false;
      cang[j] = false;
      memset(dp, 0, sizeof(dp));
      dp[0][0][0] = 1;
      for (int k = 0; k < n; k++) {
        for (int ii = 0; ii < n; ii++) {
          for (int jj = 0; jj < n; jj++) {
            if (cang[k]) {
              dp[k + 1][ii + 1][jj] += dp[k][ii][jj];
            }
            if (cans[k]) {
              dp[k + 1][ii][jj + 1] += dp[k][ii][jj];
            }
            if (canb[k]) {
              dp[k + 1][ii][jj] += dp[k][ii][jj];
            }
          }
        }
      }
      for (int ii = g1; ii <= g2; ii++) {
        for (int jj = s1; jj <= s2; jj++) {
          ans += dp[n][ii][jj];
        }
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
