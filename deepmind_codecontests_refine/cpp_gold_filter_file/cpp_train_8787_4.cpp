#include <bits/stdc++.h>
using namespace std;
const int MAXN = 60;
const int vx[4] = {0, 1, 0, -1};
const int vy[4] = {1, 0, -1, 0};
struct Point {
  int x, y;
  Point(int _x = 0, int _y = 0) { x = _x, y = _y; }
};
int n, m, A[MAXN][MAXN], dis[MAXN][MAXN];
bool inq[MAXN][MAXN];
queue<Point> Q;
void lucky() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      char c;
      scanf(" %c ", &c);
      A[i][j] = (c == 'B');
    }
}
bool upd(int& a, int b) { return (a > b) ? a = b, 1 : 0; }
int SSSP(Point o) {
  memset(dis, 0x3f, sizeof(dis));
  Q.push(o), inq[o.x][o.y] = 1;
  dis[o.x][o.y] = 0;
  while (!Q.empty()) {
    o = Q.front(), Q.pop(), inq[o.x][o.y] = 0;
    for (int i = 0; i < 4; i++) {
      int nx = o.x + vx[i], ny = o.y + vy[i];
      if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
      if (upd(dis[nx][ny], dis[o.x][o.y] + (A[o.x][o.y] != A[nx][ny])))
        if (!inq[nx][ny]) {
          Q.push(Point(nx, ny));
          inq[nx][ny] = 1;
        }
    }
  }
  int res = -1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (A[i][j]) res = max(res, dis[i][j]);
  return res;
}
int main() {
  lucky();
  int ans = 1 << 30;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) ans = min(ans, SSSP(Point(i, j)));
  printf("%d\n", ans + 1);
  return 0;
}
