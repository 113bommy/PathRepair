#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
int n, m;
void accell() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
}
const int N = 1005;
const int mod = 1e9 + 7;
vector<pair<int, int> > g[50];
bool used[N][N];
int d[N][N][41];
bool hv[50];
int a[N][N];
void bfs(int c) {
  queue<pair<int, int> > q;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) used[i][j] = false;
  for (int i = 0; i < 50; ++i) hv[i] = false;
  hv[c] = true;
  for (auto it : g[c]) {
    q.push(it);
    used[it.first][it.second] = true;
    d[it.first][it.second][c] = 0;
  }
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if (!hv[a[x][y]]) {
      for (auto to : g[a[x][y]]) {
        if (!used[to.first][to.second]) {
          used[to.first][to.second] = true;
          d[to.first][to.second][c] = d[x][y][c] + 1;
          q.push(to);
        }
      }
      hv[a[x][y]] = true;
    }
    for (int i = -1; i <= 1; ++i) {
      for (int j = -1; j <= 1; ++j) {
        if (abs(i) ^ abs(j)) {
          int tx = x + i;
          int ty = y + j;
          if (tx >= 0 && tx < n && ty >= 0 && ty < m && !used[tx][ty]) {
            q.push({tx, ty});
            d[tx][ty][c] = d[x][y][c] + 1;
            used[tx][ty] = true;
          }
        }
      }
    }
  }
}
signed main() {
  accell();
  int k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      for (int t = 1; t <= k; ++t) d[i][j][t] = 1e9;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      g[a[i][j]].push_back({i, j});
    }
  }
  for (int i = 1; i <= k; ++i) bfs(i);
  int q;
  cin >> q;
  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    --x1, --y1, --x2, --y2;
    int ans = abs(x1 - x2) + abs(y2 - y1);
    for (int i = 1; i <= k; ++i) {
      ans = min(ans, d[x1][y1][i] + d[x2][y2][i] + 1);
    }
    cout << ans << '\n';
  }
  return 0;
}
