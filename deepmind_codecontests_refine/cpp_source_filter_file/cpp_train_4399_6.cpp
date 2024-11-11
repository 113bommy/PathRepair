#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 7;
const long long max_n = 1e3 + 5;
long long xr[]{-1, 1, 0, 0}, yr[]{0, 0, -1, 1};
long long n, m;
bool check(long long x, long long y) {
  return x >= 0 && y >= 0 && x < n && y < m;
}
void solve() {
  long long t;
  cin >> n >> m >> t;
  string a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<vector<long long>> dist(n, vector<long long>(m, inf));
  deque<pair<long long, long long>> bfs;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      bool good = false;
      for (long long it = 0; it < 4; it++) {
        long long to_x = i + xr[it];
        long long to_y = j + yr[it];
        if (check(to_x, to_y) && a[to_x][to_y] == a[i][j]) good = true;
      }
      if (good) {
        dist[i][j] = 0;
        bfs.emplace_back(i, j);
      }
    }
  }
  while (!bfs.empty()) {
    pair<long long, long long> v = bfs.front();
    bfs.pop_front();
    for (long long it = 0; it < 4; it++) {
      long long x = v.first + xr[it];
      long long y = v.second + yr[it];
      if (check(x, y) && dist[x][y] == inf) {
        dist[x][y] = dist[v.first][v.second] + 1;
        bfs.emplace_back(x, y);
      }
    }
  }
  while (t--) {
    long long x, y, p;
    cin >> x >> y >> p;
    x--;
    y--;
    if (p < dist[x][y])
      cout << a[x][y] << endl;
    else {
      p -= dist[x][y];
      long long v = a[x][y] - '0';
      if (p % 2 == 0)
        cout << v << endl;
      else
        cout << 1 - v << endl;
    }
  }
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  solve();
}
