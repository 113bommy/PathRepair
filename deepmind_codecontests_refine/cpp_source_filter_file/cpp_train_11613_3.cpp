#include <bits/stdc++.h>
using namespace std;
int n, m, p, dp[303][303];
vector<pair<int, int> > G[303 * 303];
int main() {
  int x, y, z, i, j, k, px, py;
  scanf("%d%d", &n, &m);
  scanf("%d", &p);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &x);
      dp[i][j] = 2000000010;
      if (x == p) px = i, py = j;
      G[x].push_back(make_pair(i, j));
    }
  }
  for (int i = 1; i <= p; i++) random_shuffle(G[i].begin(), G[i].end());
  for (i = 1; i <= p; i++) {
    for (j = 0; j < (int)(G[i].size()) && j < 300; j++) {
      int nx = G[i][j].first, ny = G[i][j].second;
      if (i == 1) {
        dp[nx][ny] = abs(nx - 1) + abs(ny - 1);
        continue;
      }
      for (k = 0; k < (int)(G[i - 1].size()) && k < 300; k++) {
        int x = G[i - 1][k].first, y = G[i - 1][k].second;
        dp[nx][ny] = min(dp[nx][ny], dp[x][y] + abs(nx - x) + abs(ny - y));
      }
    }
  }
  printf("%d\n", dp[px][py]);
  return 0;
}
