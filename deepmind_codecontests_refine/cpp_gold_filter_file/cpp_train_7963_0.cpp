#include <bits/stdc++.h>
using namespace std;
const long long N = 1005;
char a[N][N];
long long n, m;
long long d[4][N][N], cod[4][4];
const long long adi[4] = {0, 0, -1, 1};
const long long adj[4] = {1, -1, 0, 0};
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) cin >> a[i] + 1;
  memset(d, 0x1f, sizeof d);
  memset(cod, 0x1f, sizeof cod);
  for (long long t = 1; t <= 3; t++) {
    queue<pair<long long, long long>> que;
    for (long long i = 1; i <= n; i++)
      for (long long j = 1; j <= m; j++)
        if (a[i][j] == ('0' + t)) que.push({i, j}), d[t][i][j] = 0;
    while (que.size()) {
      auto [i, j] = que.front();
      que.pop();
      for (long long dir = 0; dir < 4; dir++) {
        long long di = adi[dir];
        long long dj = adj[dir];
        long long ni = di + i;
        long long nj = dj + j;
        if (ni > 0 && nj > 0 && ni <= n && nj <= m &&
            d[t][i][j] + 1 < d[t][ni][nj] && a[ni][nj] != '#') {
          d[t][ni][nj] = d[t][i][j] + 1;
          que.push({ni, nj});
        }
      }
    }
  }
  for (long long x = 1; x <= 3; x++) {
    for (long long y = 1; y <= 3; y++) {
      if (x != y) {
        for (long long i = 1; i <= n; i++) {
          for (long long j = 1; j <= m; j++) {
            if (a[i][j] == ('0' + y)) cod[x][y] = min(cod[x][y], d[x][i][j]);
          }
        }
      }
    }
  }
  long long ans = 1e18;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      ans = min(ans, d[1][i][j] + d[2][i][j] + d[3][i][j] - 2);
    }
  }
  ans = min(ans, cod[1][2] + cod[2][3] - 2);
  ans = min(ans, cod[2][1] + cod[1][3] - 2);
  ans = min(ans, cod[1][3] + cod[3][2] - 2);
  if (ans < 1e12)
    cout << ans << endl;
  else
    cout << -1;
}
