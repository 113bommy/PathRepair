#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct P {
  int x, y;
  bool used;
};
P st[1000006];
int tp;
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> mz(n + 1);
  mz[0] = string(m, '#');
  for (int i = 1; i <= n; i++) {
    cin >> mz[i];
    mz[i] = "#" + mz[i];
  }
  vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i == 1 && j == 1) continue;
      if (mz[i - 1][j] == '#' && mz[i][j - 1] == '#') mz[i][j] = '#';
    }
  }
  if (mz[n][m] == '#') {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (mz[i][1] == '#')
      st[tp++] = {i, 1, false};
    else if (i > 1)
      st[tp++] = {i, 1, true};
  }
  for (int i = 1; i <= m; i++) {
    if (mz[n][i] == '#')
      st[tp++] = {n, i, false};
    else if (i < m)
      st[tp++] = {n, i, true};
  }
  int ans = 2;
  if (n == 1 || m == 1) ans = 1;
  for (int i = 0; i < tp; i++) {
    queue<P> q;
    while (!q.empty()) q.pop();
    q.push(st[i]);
    while (!q.empty()) {
      int x = q.front().x, y = q.front().y;
      bool used = q.front().used;
      q.pop();
      if (x == 1 || y == m) {
        if (used)
          ans = ((ans) < (1) ? (ans) : (1));
        else
          ans = 0;
        continue;
      }
      for (int i = 0; i < 8; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx == 1 && yy == 1) continue;
        if (xx == n && yy == m) continue;
        if (xx > n || yy < 1) continue;
        if (mz[xx][yy] == '.' && !used && !vis[xx][yy]) {
          vis[xx][yy] = 1;
          q.push({xx, yy, true});
        } else if (mz[xx][yy] == '#' && used && !vis[xx][yy]) {
          vis[xx][yy] = 1;
          q.push({xx, yy, true});
        } else if (mz[xx][yy] == '#' && !used && vis[xx][yy] < 2) {
          vis[xx][yy] = 2;
          q.push({xx, yy, false});
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
