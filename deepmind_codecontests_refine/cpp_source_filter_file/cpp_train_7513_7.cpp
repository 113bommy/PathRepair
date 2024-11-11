#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 20;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
const double RATE = 0.995;
const double eps = 1e-15;
int to[4][2] = {1, 0, 0, 1};
string g[MAXN];
vector<bool> used[MAXN];
int n, m;
bool dfs(int x, int y) {
  if (x == n - 1 && y == m - 1) {
    return true;
  }
  for (int i = 0; i < 2; ++i) {
    int nx = x + to[i][0];
    int ny = y + to[i][1];
    if (nx < n && nx >= 0 && ny < m && ny >= 0 && g[nx][ny] == '.' &&
        !used[nx][ny]) {
      used[nx][ny] = true;
      if (dfs(nx, ny)) {
        g[x][y] = '#';
        return true;
      }
    }
  }
  return false;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> g[i];
    for (int j = 0; j < m; ++j) {
      used[i].push_back(false);
    }
  }
  if (!dfs(1, 1)) {
    puts("0");
    return 0;
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) used[i][j] = false;
  if (!dfs(1, 1)) {
    puts("1");
  } else
    puts("2");
  return 0;
}
