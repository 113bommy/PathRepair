#include <bits/stdc++.h>
using namespace std;
bool f[1005][1005][4];
int vis[1005][1005][4];
char s[1005][1005];
int n, m;
int xt, yt, xm, ym;
struct Node {
  int x, y, F;
  Node() {}
  Node(int _x, int _y, int _F) { x = _x, y = _y, F = _F; }
};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int bfs() {
  Node S;
  S.x = xt, S.y = yt, S.F = 0;
  queue<Node> que;
  que.push(S);
  vis[xt][yt][0] = 1;
  while (que.size()) {
    S = que.front();
    que.pop();
    if (S.x == xm && S.y == ym) return vis[S.x][S.y][S.F] - 1;
    if (!vis[S.x][S.y][(S.F + 1) % 4]) {
      vis[S.x][S.y][(S.F + 1) % 4] = vis[S.x][S.y][S.F] + 1;
      que.push(Node(S.x, S.y, (S.F + 1) % 4));
    }
    for (int i = 0; i < 4; i++) {
      int nx = S.x + dx[i], ny = S.y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] == '*') continue;
      if (!vis[nx][ny][S.F] && f[S.x][S.y][(i + S.F) % 4] &&
          f[nx][ny][(i + 2 + S.F) % 4]) {
        vis[nx][ny][S.F] = vis[S.x][S.y][S.F] + 1;
        que.push(Node(nx, ny, S.F));
      }
    }
  }
  return -1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '+' || s[i][j] == '|' || s[i][j] == '^' ||
          s[i][j] == 'L' || s[i][j] == 'R' || s[i][j] == 'D')
        f[i][j][0] = 1;
      if (s[i][j] == '+' || s[i][j] == '|' || s[i][j] == 'v' ||
          s[i][j] == 'L' || s[i][j] == 'R' || s[i][j] == 'U')
        f[i][j][2] = 1;
      if (s[i][j] == '+' || s[i][j] == '-' || s[i][j] == '>' ||
          s[i][j] == 'U' || s[i][j] == 'L' || s[i][j] == 'D')
        f[i][j][1] = 1;
      if (s[i][j] == '+' || s[i][j] == '-' || s[i][j] == '<' ||
          s[i][j] == 'U' || s[i][j] == 'R' || s[i][j] == 'D')
        f[i][j][3] = 1;
    }
  scanf("%d%d%d%d", &xm, &ym, &xt, &yt);
  xt--, yt--, xm--, ym--;
  printf("%d\n", bfs());
  return 0;
}
