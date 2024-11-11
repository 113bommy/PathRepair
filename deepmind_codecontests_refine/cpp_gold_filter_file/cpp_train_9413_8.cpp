#include <bits/stdc++.h>
using namespace std;
const int N = 50 + 10;
int n, m, d[N][N], g1, g2, s1, s2;
vector<int> dis[N];
long long ans, dp[N][N][N];
inline void calc(int x, int y) {
  if (x == y) return;
  int lbg = dis[x][0], ubb = dis[y][n - 2];
  if (lbg > ubb) return;
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int g = 0; g <= min(i + 1, g2); g++)
      for (int s = 0; s <= min(i + 1 - g, s2); s++) {
        long long &cur = dp[i + 1][g][s];
        cur = 0;
        int b = i + 1 - (g + s);
        if (i == x) {
          if (g) cur += dp[i][g - 1][s];
          continue;
        }
        if (i == y) {
          if (b) cur += dp[i][g][s];
          continue;
        }
        if (g && dis[i][0] < lbg) cur += dp[i][g - 1][s];
        if (b && dis[i][n - 2] > ubb) cur += dp[i][g][s];
        if (s && upper_bound(dis[i].begin(), dis[i].end(), lbg) -
                     lower_bound(dis[i].begin(), dis[i].end(), ubb))
          cur += dp[i][g][s - 1];
      }
  for (int g = g1; g <= g2; g++)
    for (int s = s1; s <= s2; s++) ans += dp[n][g][s];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i != j) d[i][j] = 1e9;
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    x--, y--;
    d[x][y] = d[y][x] = w;
  }
  for (int u = 0; u < n; u++)
    for (int x = 0; x < n; x++)
      for (int y = 0; y < n; y++) d[x][y] = min(d[x][y], d[x][u] + d[u][y]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      if (i != j) dis[i].push_back(10000 * d[i][j] + i);
    sort(dis[i].begin(), dis[i].end());
    cerr << i + 1 << " = ";
    for (auto j : dis[i]) cerr << j / 10000 << ' ';
    cerr << endl;
  }
  cin >> g1 >> g2 >> s1 >> s2;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) calc(i, j);
  cout << ans << endl;
  return 0;
}
