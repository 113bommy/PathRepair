#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, N = 550;
const int MOD = 1e9 + 7;
const double eps = 1e-6;
const double PI = acos(-1);
inline int lowbit(int x) { return x & (-x); }
char g[N][N];
int ans[N][N];
int n, m;
vector<pair<int, int> > v[N][N];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
void dfs(int x, int y, int k) {
  ans[x][y] = k;
  for (auto ite : v[x][y]) {
    int nx = ite.first, ny = ite.second;
    if (!ans[nx][ny]) dfs(nx, ny, 5 - k);
  }
}
inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> (g[i] + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (g[i][j] == '.') continue;
      vector<pair<int, int> > tmp;
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (x < 1 || x > n || y < 1 || y > m || g[x][y] == 'X') continue;
        tmp.emplace_back(x, y);
      }
      ans[i][j] = (int)tmp.size() / 2 * 5;
      if (tmp.empty()) continue;
      if (tmp.size() & 1) {
        cout << "NO" << '\n';
        return;
      }
      if (tmp.size() == 2) {
        int x1 = tmp[0].first, y1 = tmp[0].second;
        int x2 = tmp[1].first, y2 = tmp[1].second;
        v[x1][y1].emplace_back(x2, y2);
        v[x2][y2].emplace_back(x1, y1);
      } else {
        sort(tmp.begin(), tmp.end());
        int x[4], y[4];
        for (int k = 0; k < 4; k++) x[k] = tmp[k].first, y[k] = tmp[k].second;
        v[x[0]][y[0]].emplace_back(x[1], y[1]),
            v[x[1]][y[1]].emplace_back(x[0], y[0]);
        v[x[1]][y[1]].emplace_back(x[3], y[3]),
            v[x[3]][y[3]].emplace_back(x[1], y[1]);
        v[x[3]][y[3]].emplace_back(x[2], y[2]),
            v[x[2]][y[2]].emplace_back(x[3], y[3]);
        v[x[2]][y[2]].emplace_back(x[0], y[0]),
            v[x[0]][y[0]].emplace_back(x[2], y[2]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (g[i][j] == '#') continue;
      if (!ans[i][j]) dfs(i, j, 1);
    }
  }
  cout << "YES" << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << ans[i][j] << ' ';
    cout << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  cout << fixed << setprecision(2);
  solve();
  return 0;
}
