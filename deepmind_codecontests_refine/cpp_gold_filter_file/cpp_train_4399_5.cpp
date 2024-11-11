#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
const long long int inf = 8e18;
const long long int N = 1e3 + 5;
long long int dx[4] = {0, 0, -1, 1};
long long int dy[4] = {-1, 1, 0, 0};
long long int a[N][N], dist[N][N];
long long int n, m, t;
bool safe(long long int x, long long int y) {
  if (x >= 1 and x <= n and y >= 1 and y <= m) return true;
  return false;
}
void __solve() {
  cin >> n >> m >> t;
  for (long long int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (long long int j = 1; j <= m; j++) {
      a[i][j] = (s[j - 1] == '1');
      dist[i][j] = inf;
    }
  }
  queue<pair<long long int, long long int> > q;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = 1; j <= m; j++) {
      for (long long int k = 0; k < 4; k++) {
        long long int nx = i + dx[k];
        long long int ny = j + dy[k];
        if (safe(nx, ny) and a[i][j] == a[nx][ny]) {
          dist[i][j] = 0;
          q.push({i, j});
          break;
        }
      }
    }
  }
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    long long int x = u.first, y = u.second;
    for (long long int k = 0; k < 4; k++) {
      long long int nx = x + dx[k];
      long long int ny = y + dy[k];
      if (safe(nx, ny) and a[x][y] != a[nx][ny] and
          dist[nx][ny] > dist[x][y] + 1) {
        dist[nx][ny] = dist[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }
  while (t--) {
    long long int i, j, p;
    cin >> i >> j >> p;
    if (dist[i][j] >= p) {
      cout << a[i][j] << '\n';
    } else {
      cout << (a[i][j] ^ ((p - dist[i][j]) % 2)) << '\n';
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T = 1;
  while (T--) {
    __solve();
    cout << '\n';
  }
}
