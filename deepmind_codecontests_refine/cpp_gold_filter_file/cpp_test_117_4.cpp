#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n, m, lx, ly, val[maxn];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
vector<string> a;
bool inside(int x, int y) { return x >= 0 && x < n && y >= 0 && y < m; }
void dfs(int u) {
  int i = u / m, j = u % m, w = 0, can = 0;
  for (int d = 0; d < (int)(4); ++d) {
    int x = i + dx[d], y = j + dy[d];
    if (!inside(x, y) || a[x][y] == '#') continue;
    int v = x * m + y;
    w++;
    can += val[v];
  }
  val[u] = (can && w - can <= 1) || (i == lx && j == ly);
  if (!val[u]) return;
  for (int d = 0; d < (int)(4); ++d) {
    int x = i + dx[d], y = j + dy[d];
    if (!inside(x, y) || a[x][y] == '#') continue;
    int v = x * m + y;
    if (!val[v]) dfs(v);
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < (int)(n); ++i) {
      cin >> a[i];
      for (int j = 0; j < (int)(m); ++j) {
        if (a[i][j] == 'L') lx = i, ly = j;
        val[i * m + j] = 0;
      }
    }
    dfs(lx * m + ly);
    for (int i = 0; i < (int)(n); ++i) {
      for (int j = 0; j < (int)(m); ++j) {
        if (a[i][j] == 'L' || !val[i * m + j])
          cout << a[i][j];
        else
          cout << '+';
      }
      cout << '\n';
    }
  }
  return 0;
}
