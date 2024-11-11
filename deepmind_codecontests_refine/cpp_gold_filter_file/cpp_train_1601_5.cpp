#include <bits/stdc++.h>
const long long N = 1e5 + 100, MOD = 1e18 + 7;
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
long long n, m, t, a, b, c, dis[306][306];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  t = 1;
  for (int i = 1; i <= t; ++i) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        cin >> dis[i][j];
      }
    }
    cin >> m;
    while (m--) {
      long long ans = 0;
      cin >> a >> b >> c;
      dis[a][b] = dis[b][a] = min(c, dis[a][b]);
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
          dis[i][j] = min(dis[i][j], dis[i][a] + dis[a][j]);
      }
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
          dis[i][j] = min(dis[i][j], dis[i][b] + dis[b][j]);
      }
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          ans += dis[i][j];
        }
      }
      cout << ans / 2 << ' ';
    }
  }
  return 0;
}
