#include <bits/stdc++.h>
using namespace std;
const int dx[9] = {0, 1, 0, -1, 0, -1, -1, 1, 1};
const int dy[9] = {0, 0, -1, 0, 1, -1, 1, -1, 1};
const double pi = acos(-1.0);
const int N = 100;
const int INF = 0x3f3f3f3f;
int n, k, m, f[N][N][N][2], ans = INF;
vector<pair<int, int> > G[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> k;
  cin >> m;
  if (k == 1) return cout << 0 << endl, 0;
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    G[x].push_back(make_pair(y, z));
  }
  for (int i = 1; i <= k - 1; i++) {
    for (int l = n; l >= 1; l--)
      for (int r = l + 1; r <= n; r++) {
        f[i][l][r][0] = INF;
        for (pair<int, int> temp : G[l]) {
          int y = temp.first, cost = temp.second;
          if (l < y && y < r) {
            f[i][l][r][0] = min(f[i][l][r][0], f[i - 1][y][r][0] + cost);
            f[i][l][r][0] = min(f[i][l][r][0], f[i - 1][l][y][1] + cost);
          }
        }
        f[i][l][r][1] = INF;
        for (pair<int, int> temp : G[r]) {
          int y = temp.first, cost = temp.second;
          if (l < y && y < r) {
            f[i][l][r][1] = min(f[i][l][r][1], f[i - 1][l][y][1] + cost);
            f[i][l][r][1] = min(f[i][l][r][1], f[i - 1][y][r][0] + cost);
          }
        }
        if (i == k - 1) {
          ans = min(ans, f[i][l][r][1]);
          ans = min(ans, f[i][l][r][0]);
        }
      }
  }
  if (ans >= INF)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
