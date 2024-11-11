#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
char mp[maxn][maxn];
int col[maxn], row[maxn];
int vis[maxn][maxn];
int dr[][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
int n, m, k;
int T;
bool ok(int x, int y) {
  if (x >= 1 && x <= n && y >= 1 && y <= m) return true;
  return false;
}
void dfs(int x, int y) {
  if (vis[x][y]) return;
  vis[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int xx = x + dr[i][0];
    int yy = y + dr[i][1];
    if (ok(xx, yy) && mp[xx][yy] == '#') dfs(xx, yy);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> (mp[i] + 1);
    for (int j = 1; j <= m; j++)
      if (mp[i][j] == '#') row[i]++, col[j]++;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!row[i] && !col[j]) vis[i][j] = 1;
  bool flag = true;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= m; j++)
      if (vis[i][j]) cnt++;
    cnt += row[i];
    if (!cnt) {
      flag = false;
      break;
    }
    int all = row[i];
    for (int j = 1; j <= m; j++) {
      if (mp[i][j] == '.' && all && all != row[i]) {
        flag = false;
        break;
      }
      if (mp[i][j] == '#') all--;
    }
  }
  for (int j = 1; j <= m; j++) {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
      if (vis[i][j]) cnt++;
    cnt += col[j];
    if (!cnt) {
      flag = false;
      break;
    }
    int all = col[j];
    for (int i = 1; i <= m; i++) {
      if (mp[i][j] == '.' && all && all != col[j]) {
        flag = false;
        break;
      }
      if (mp[i][j] == '#') all--;
    }
  }
  if (!flag) {
    cout << -1 << endl;
    return 0;
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      if (!vis[i][j] && mp[i][j] == '#') {
        res++;
        dfs(i, j);
      }
  }
  cout << res << endl;
}
