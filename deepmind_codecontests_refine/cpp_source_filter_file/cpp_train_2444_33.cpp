#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 15;
const long long int inf = 1e18;
vector<string> a(100);
long long int n, m;
vector<vector<long long int> > vis(100, vector<long long int>(100));
vector<long long int> dx = {0, -1, 1, 0};
vector<long long int> dy = {1, 0, 0, -1};
void dfs(long long int x, long long int y, long long int px, long long int py,
         char col) {
  for (long long int i = 0; i < 4; i++) {
    long long int nx = x + dx[i];
    long long int ny = y + dy[i];
    if (nx >= 0 and ny >= 0 and nx < n and ny < m) {
      if (a[nx][ny] == col and !(nx == px and ny == py)) {
        if (vis[nx][ny]) {
          cout << "Yes";
          exit(0);
        } else {
          vis[nx][ny] = true;
          dfs(nx, ny, x, y, col);
        }
      }
    }
  }
}
void solve() {
  cin >> n >> m;
  for (long long int i = 0; i < n; i++) cin >> a[i];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      if (!vis[i][j]) {
        vis[i][j] = true;
        dfs(i, i, 0, 0, a[i][j]);
      }
    }
  }
  cout << "No";
}
void debug(long long int tt) {}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
