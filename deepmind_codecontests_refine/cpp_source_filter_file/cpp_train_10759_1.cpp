#include <bits/stdc++.h>
using namespace std;
vector<int> deg(16);
vector<vector<int>> dist(16, vector<int>(16, 100000000));
vector<int> temp(16);
int timer = 1;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int x, y, w;
  long long res = 0;
  for (int i = 1; i <= n; i += 1) {
    dist[i][i] = 0;
  }
  for (int i = 1; i <= m; i += 1) {
    cin >> x >> y >> w;
    res += w;
    deg[x] += 1;
    deg[y] += 1;
    dist[x][y] = dist[y][x] = min(dist[x][y], w);
  }
  for (int k = 1; k <= n; k += 1) {
    for (int i = 1; i <= n; i += 1) {
      for (int j = 1; j <= n; j += 1) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
  for (int i = 2; i <= n; i += 1) {
    if (deg[i] && dist[1][i] == 1000000000) {
      cout << -1;
      return 0;
    }
  }
  for (int i = 1; i <= n; i += 1) {
    if (deg[i] & 1) {
      temp[timer++] = i;
    }
  }
  timer -= 1;
  vector<int> dp((1 << timer), 1000000000);
  dp[0] = 0;
  for (int mask = 0; mask < (1 << timer); mask += 1) {
    for (int i = 1; i <= timer; i += 1) {
      for (int j = 1; j <= timer; j += 1) {
        if (i == j || ((1 << (i - 1)) | mask) == mask ||
            ((1 << (j - 1)) | mask) == mask) {
          continue;
        }
        dp[mask | (1 << (i - 1)) | (1 << (j - 1))] =
            min(dp[mask | (1 << (i - 1)) | (1 << (j - 1))],
                dp[mask] + dist[temp[i]][temp[j]]);
      }
    }
  }
  cout << res + dp[(1 << timer) - 1];
}
