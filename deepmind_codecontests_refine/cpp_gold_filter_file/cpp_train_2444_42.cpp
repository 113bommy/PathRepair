#include <bits/stdc++.h>
using namespace std;
const long long hell = 1000000007;
const long long mod = 1000000007;
char c[51][51];
long long vis[51][51];
long long edges, vertex;
long long n, m;
void dfs(long long x, long long y, char color) {
  vis[x][y] = 1;
  vertex++;
  if (x > 0 and c[x - 1][y] == color) {
    if (!vis[x - 1][y]) dfs(x - 1, y, color);
    edges++;
  }
  if (x < n - 1 and c[x + 1][y] == color) {
    if (!vis[x + 1][y]) dfs(x + 1, y, color);
    edges++;
  }
  if (y > 0 and c[x][y - 1] == color) {
    if (!vis[x][y - 1]) dfs(x, y - 1, color);
    edges++;
  }
  if (y < n - 1 and c[x][y + 1] == color) {
    if (!vis[x][y + 1]) dfs(x, y + 1, color);
    edges++;
  }
}
long long solve() {
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> c[i][j];
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (!vis[i][j]) {
        edges = 0, vertex = 0;
        dfs(i, j, c[i][j]);
        if ((edges / 2) >= vertex) {
          cout << "Yes";
          return 0;
        }
      }
    }
  }
  cout << "No";
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
