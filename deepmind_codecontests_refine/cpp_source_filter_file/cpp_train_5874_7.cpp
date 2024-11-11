#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
const int MOD = 1e9 + 7;
const long long oo = 1e9 + 7;
long long GCD(long long a, long long b) { return !b ? a : GCD(b, a % b); }
int n, m;
int dp[1234][1234];
vector<string> grid;
bool vis[1234][1234];
char nxt[100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool valid(int x, int y) { return x > -1 && y > -1 && x < n && y < m; }
int bt(int x, int y, char cur) {
  int& ret = dp[x][y];
  if (ret != -1) return ret;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (valid(nx, ny) && grid[nx][ny] == nxt[cur]) {
      if (vis[nx][ny]) return ret = oo;
      vis[x][y] = 1;
      ret = max(ret, bt(nx, ny, nxt[cur]) + (nxt[cur] == 'A'));
      vis[x][y] = 0;
    }
  }
  if (ret == -1 && cur == 'A') ret = 0;
  return ret;
}
int main() {
  cin >> n >> m;
  grid.resize(n);
  for (int i = 0; i < n; i++) cin >> grid[i];
  nxt['D'] = 'I';
  nxt['I'] = 'M';
  nxt['M'] = 'A';
  nxt['A'] = 'D';
  memset(dp, -1, sizeof dp);
  int ans = -1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (grid[i][j] == 'D') ans = max(ans, bt(i, j, 'D'));
  if (ans == oo)
    puts("Poor Inna!");
  else if (ans == -1)
    puts("Poor Dima!");
  else
    cout << ans << '\n';
  return 0;
}
