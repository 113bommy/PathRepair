#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[2012][2012];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int deg[2012][2012];
pair<int, int> bfs[2012 * 2012];
int q = 0, top = 0, bot = 0;
char fl[2][8] = {"^<v>", "v>^<"};
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> s[i + 1] + 1;
  for (int i = 1; i < n + 1; ++i) {
    for (int j = 1; j < m + 1; ++j) {
      for (int k = 0; k < 4; ++k) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (s[nx][ny] == '.') deg[i][j]++;
      }
      if (s[i][j] == '.') {
        q++;
        if (deg[i][j] == 1) bfs[top++] = pair<int, int>(i, j);
      }
    }
  }
  while (bot < top) {
    int x = bfs[bot].first;
    int y = bfs[bot].second;
    if (s[x][y] == '.') {
      int nx, ny, id = -1;
      bool kt = false;
      for (int k = 0; k < 4; ++k) {
        nx = x + dx[k];
        ny = y + dy[k];
        id = k;
        if (s[nx][ny] == '.') {
          kt = true;
          break;
        }
      }
      if (kt == false) {
        cout << "Not unique";
        return 0;
      }
      s[x][y] = fl[0][id];
      s[nx][ny] = fl[1][id];
      deg[x][y] = deg[nx][ny] = 0;
      for (int k = 0; k < 4; ++k) {
        int nnx = nx + dx[k];
        int nny = ny + dy[k];
        deg[nnx][nny]--;
        if (deg[nnx][nny] == 1) {
          bfs[top++] = pair<int, int>(nnx, nny);
        }
      }
    }
    bot++;
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (s[i + 1][j + 1] == '.') {
        cout << "Not unique";
        return 0;
      }
  for (int i = 0; i < n; ++i) {
    cout << s[i + 1] + 1;
    cout << '\n';
  }
  return 0;
}
