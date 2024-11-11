#include <bits/stdc++.h>
using namespace std;
const int N = 1510;
struct node {
  int x, y, px, py;
};
char G[N][N];
int ppx[N][N], ppy[N][N];
int n, m, x, y, nx, ny, px, py;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<node> Q;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", G[i]);
    for (int j = 0; j < m; j++)
      if (G[i][j] == 'S') {
        x = i;
        y = j;
        G[i][j] = '.';
      }
  }
  memset(ppx, 127, sizeof(ppx));
  memset(ppy, 127, sizeof(ppy));
  ppx[x][y] = ppy[x][y] = 0;
  Q.push((node){x, y, 0, 0});
  node cur;
  while (!Q.empty()) {
    cur = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++) {
      nx = cur.x + dx[i];
      ny = cur.y + dy[i];
      px = cur.px;
      py = cur.py;
      if (nx < 0) {
        nx = n - 1;
        px--;
      } else if (nx >= n) {
        nx = 0;
        px++;
      }
      if (ny < 0) {
        ny = m - 1;
        py--;
      } else if (ny >= m) {
        ny = 0;
        py++;
      }
      if (G[nx][ny] == '.') {
        if (ppx[nx][ny] == ppx[1500][1500]) {
          ppx[nx][ny] = px;
          ppy[nx][ny] = py;
          Q.push((node){nx, ny, px, py});
        } else if (ppx[nx][ny] != px || ppx[nx][ny] != py) {
          puts("Yes");
          return 0;
        }
      }
    }
  }
  puts("No");
  return 0;
}
