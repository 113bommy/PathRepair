#include <bits/stdc++.h>
using namespace std;
int t, m, n, a[1005][1005];
vector<int> v[1005];
queue<pair<pair<int, int>, int> > q;
int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int vis[1005][1005];
long long f[1005][1005];
bool check(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int nx = x + pos[i][0], ny = y + pos[i][1];
    if (a[nx][ny] == a[x][y]) return 1;
  }
  return 0;
}
void add(int x, int y, int val) {
  for (int i = 0; i < 4; i++) {
    int nx = x + pos[i][0], ny = y + pos[i][1];
    if (!vis[nx][ny]) {
      vis[nx][ny] = 1;
      f[nx][ny] = val;
      q.push({{nx, ny}, val});
    }
  }
}
void BFS() {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (check(i, j)) {
        vis[i][j] = 1;
        f[i][j] = 0;
        q.push({{i, j}, 0});
      }
  while (q.size()) {
    pair<pair<int, int>, int> x = q.front();
    q.pop();
    int w = x.second;
    int u = x.first.first;
    int v = x.first.second;
    add(u, v, f[u][v] + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  if (fopen(""
            ".inp",
            "r")) {
    freopen(
        ""
        ".inp",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  }
  cin >> n >> m >> t;
  memset(a, 2, sizeof(a));
  memset(vis, 1, sizeof(vis));
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; ++j)
      a[i][j] = s[j - 1] - '0', vis[i][j] = 0, f[i][j] = 2e18;
  }
  BFS();
  while (t--) {
    int u, v;
    long long p;
    cin >> u >> v >> p;
    p -= f[u][v];
    if (p < 0) {
      cout << a[u][v] << '\n';
      continue;
    }
    cout << (a[u][v] ^ (p & 1)) << '\n';
  }
  return 0;
}
