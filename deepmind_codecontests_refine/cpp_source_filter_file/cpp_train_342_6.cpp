#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 200;
int n;
int m;
int k;
int a[200];
int c[200];
int d[200][200];
int p[200][200];
int dp[128][200];
char ans[200][200];
void drawPath(int u, int v) {
  for (; v != u; v = p[u][v]) {
    ans[v / m][v % m] = 'X';
  }
}
void drawPicture(int mask, int v) {
  int minRem = INF;
  int u;
  for (int i = 0; i < n * m; i++) {
    if (dp[mask][v] == dp[mask][i] + d[i][v] && dp[mask][i] < minRem) {
      minRem = dp[mask][i];
      u = i;
    }
  }
  drawPath(u, v);
  if (c[u] >= 0 && (1 << c[u]) == mask) {
    ans[u / m][u % m] = 'X';
    return;
  }
  for (int submask = (mask - 1) & mask; submask;
       submask = (submask - 1) & submask) {
    if (dp[mask][u] == dp[submask][u] + dp[mask ^ submask][u] - a[u]) {
      drawPicture(submask, u);
      drawPicture(mask ^ submask, u);
      return;
    }
  }
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i * m + j];
      ans[i][j] = '.';
    }
  }
  memset(p, -1, sizeof(p));
  for (int i = 0; i < n * m; i++) {
    for (int j = 0; j < n * m; j++) {
      if (i == j) {
        d[i][j] = 0;
        continue;
      }
      if (abs(i / m - j / m) + abs(i % m - j % m) == 1) {
        d[i][j] = a[j];
        p[i][j] = i;
        continue;
      }
      d[i][j] = INF;
    }
  }
  for (int l = 0; l < n * m; l++) {
    for (int i = 0; i < n * m; i++) {
      for (int j = 0; j < n * m; j++) {
        if (d[i][j] > d[i][l] + d[l][j]) {
          d[i][j] = d[i][l] + d[l][j];
          p[i][j] = p[l][j];
        }
      }
    }
  }
  int x;
  int y;
  memset(c, -1, sizeof(c));
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    c[--x * m + --y] = i;
  }
  for (int mask = 1; mask < (1 << k); mask++) {
    for (int i = 0; i < n * m; i++) {
      if (c[i] >= 0 && (1 << c[i]) == mask)
        dp[mask][i] = a[i];
      else
        dp[mask][i] = INF;
      for (int submask = (mask - 1) & mask; submask;
           submask = (submask - 1) & submask) {
        dp[mask][i] =
            min(dp[mask][i], dp[submask][i] + dp[mask ^ submask][i] - a[i]);
      }
    }
    for (int i = 0; i < n * m; i++) {
      for (int j = 0; j < n * m; j++) {
        dp[mask][i] = min(dp[mask][i], dp[mask][j] + d[j][i]);
      }
    }
  }
  int minCost = INF;
  int keyPoint;
  for (int i = 0; i < n * m; i++) {
    if (minCost > dp[(1 << k) - 1][i]) {
      minCost = dp[(1 << k) - 1][i];
      keyPoint = i;
    }
  }
  drawPicture((1 << k) - 1, keyPoint);
  cout << minCost << endl;
  for (int i = 0; i < n; i++) cout << ans[i] << endl;
  return 0;
}
