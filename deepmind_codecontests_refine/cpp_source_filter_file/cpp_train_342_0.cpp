#include <bits/stdc++.h>
using namespace std;
int const lim = 220;
int mn[lim + 3][lim + 3], mid[lim + 3][lim + 3];
int inf = INT_MAX / 2;
int dp[(1 << 8)][lim + 3], inp[lim + 3], from[(1 << 8)][lim + 3], m;
bool is[(1 << 8)][lim + 3];
bool out[lim + 3];
void shortest(int u, int v) {
  out[u] = out[v] = true;
  int ind = mid[u][v];
  if (ind == -1) return;
  shortest(u, ind);
  shortest(ind, v);
}
void solve(int mask, int u) {
  out[u] = true;
  int v = from[mask][u];
  if (v == -1) return;
  if (is[mask][u])
    shortest(u, v), solve(mask, v);
  else
    solve(mask ^ v, u), solve(v, u);
}
int main() {
  memset(mid, -1, sizeof mid);
  memset(from, -1, sizeof from);
  int n, m, kk;
  cin >> n >> m >> kk;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &inp[i * m + j]);
  for (int i = 0; i < n * m; i++)
    for (int j = 0; j < n * m; j++) mn[i][j] = inf;
  for (int i = 0; i < (1 << kk); i++)
    for (int j = 0; j < n * m; j++) dp[i][j] = inf;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (i) mn[i * m + j][(i - 1) * m + j] = inp[(i - 1) * m + j];
      if (j) mn[i * m + j][i * m + j - 1] = inp[i * m + j - 1];
      if (i < n - 1) mn[i * m + j][(i + 1) * m + j] = inp[(i + 1) * m + j];
      if (j < m - 1) mn[i * m + j][i * m + j + 1] = inp[i * m + j + 1];
    }
  for (int k = 0; k < n * m; k++)
    for (int i = 0; i < n * m; i++)
      for (int j = 0; j < n * m; j++)
        if (mn[i][k] + mn[k][j] < mn[i][j])
          mn[i][j] = mn[i][k] + mn[k][j], mid[i][j] = k;
  for (int i = 0; i < kk; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    dp[(1 << i)][x * m + y] = inp[x * m + y];
    for (int j = 0; j < n * m; j++)
      if (inp[x * m + y] + mn[x * m + y][j] < dp[(1 << i)][j])
        dp[(1 << i)][j] = inp[x * m + y] + mn[x * m + y][j],
                 from[(1 << i)][j] = x * m + y, is[(1 << i)][j] = true;
  }
  int ans = inf, ind = -1;
  for (int i = 2; i < (1 << kk); i++) {
    for (int k = 0; k < n * m; k++) {
      for (int j = 1; j < (1 << kk); j++) {
        if (((~i) & j) > 0) continue;
        if (dp[j][k] + dp[i ^ j][k] - inp[k] < dp[i][k])
          dp[i][k] = dp[j][k] + dp[i ^ j][k] - inp[k], from[i][k] = j,
          is[i][k] = false;
      }
      for (int j = 0; j < n * m; j++)
        if (dp[i][k] + mn[k][j] < dp[i][j])
          dp[i][j] = dp[i][k] + mn[k][j], from[i][j] = k, is[i][j] = true;
      if (i == (1 << kk) - 1 && dp[i][k] < ans)
        ans = min(ans, dp[i][k]), ind = k;
    }
  }
  solve((1 << kk) - 1, ind);
  cout << ans << endl;
  for (int i = 0; i < n; i++, puts(""))
    for (int j = 0; j < m; j++)
      if (out[i * m + j])
        printf("X");
      else
        printf(".");
}
