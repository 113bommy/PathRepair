#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char mat[55][55];
int d[55][55];
int n, m;
int bfs(int sx, int sy) {
  queue<pair<int, int> > q;
  q.push(make_pair(sx, sy));
  memset(d, 63, sizeof(d));
  d[sx][sy] = 0;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for (int k = 0; k < 4; k++) {
      int x = cur.first + dx[k], y = cur.second + dy[k];
      if (x >= 1 && x <= n && y >= 1 && y <= m) {
        int t = (mat[cur.first][cur.second] != mat[x][y]);
        if (d[cur.first][cur.second] + t < d[x][y]) {
          d[x][y] = d[cur.first][cur.second] + t;
          q.push(make_pair(x, y));
        }
      }
    }
  }
  int ret = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (mat[i][j] == 'B') ret = max(ret, d[i][j]);
    }
  return ret;
}
int main(int argc, char const *argv[]) {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%s", mat[i] + 1);
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cnt += mat[i][j] == 'B';
  if (!cnt) {
    cout << 0 << endl;
    return 0;
  }
  int ret = 1 << 30;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int tmp = bfs(i, j);
      ret = min(ret, tmp + 1);
    }
  }
  cout << ret << endl;
  return 0;
}
