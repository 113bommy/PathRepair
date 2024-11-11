#include <bits/stdc++.h>
using namespace std;
const int N = 22, S = 1 << 8, M = N * N * S, INF = 1e9;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
int n, m, g[N][N], sx, sy, val[N];
struct Object {
  int x, y, id;
  Object(int a = 0, int b = 0, int c = 0) : x(a), y(b), id(c) {}
  bool operator<(const Object &r) const { return id < r.id; }
} a[N];
int p, t;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
char s[N];
int d[N][N][S];
struct Grid {
  int x, y, s;
  Grid(int a = 0, int b = 0, int c = 0) : x(a), y(b), s(c) {}
} q[M];
int head, tail, inq[N][N][2];
inline void lop(int &x) {
  if (x == M) x = 1;
}
inline bool isInter(int a, int b, int x1, int y1, int x2, int y2) {
  if (x1 < a && x2 == a && y2 > b) return 1;
  if (x2 < a && x1 == a && y1 > b) return 1;
  return 0;
}
int HandleInter(Grid u, Grid t) {
  int s = u.s;
  for (int i = 0; i < 8; i++)
    s ^= isInter(a[i].x, a[i].y, u.x, u.y, t.x, t.y) << i;
  return s;
}
void spfa() {
  d[sx][sy][0] = 0;
  head = tail = 1;
  q[tail++] = Grid(sx, sy, 0);
  inq[sx][sy][0] = 1;
  while (head != tail) {
    Grid u = q[head++];
    lop(head);
    int x = u.x, y = u.y, s = u.s;
    inq[x][y][s] = 0;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 1 || nx > m || ny < 1 || ny > n || g[nx][ny]) continue;
      Grid t(nx, ny);
      int ns = t.s = HandleInter(u, t);
      if (d[nx][ny][ns] > d[x][y][s] + 1) {
        d[nx][ny][ns] = d[x][y][s] + 1;
        if (!inq[nx][ny][ns]) q[tail++] = t, lop(tail), inq[nx][ny][ns] = 1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < S; i++)
    if (d[sx][sy][i] < INF) {
      int _ = 0, bomb = 0;
      for (int j = 0; j < 8; j++)
        if (i & (1 << j)) {
          if (a[j].id == 10) {
            bomb = 1;
            continue;
          } else
            _ += val[j];
        }
      if (bomb) continue;
      ans = max(ans, _ - d[sx][sy][i]);
    }
  printf("%d", ans);
}
int main() {
  m = read();
  n = read();
  memset(d, 127, sizeof(d));
  for (int i = 1; i <= m; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= n; j++) {
      g[i][j] = (s[j] != '.');
      if (s[j] == 'S')
        g[i][j] = 0, sx = i, sy = j;
      else if (s[j] == 'B')
        a[p++] = Object(i, j, 10);
      else if (s[j] >= '0' && s[j] <= '9')
        a[p++] = Object(i, j, s[j] - '0' - 1), t++;
    }
  }
  sort(a, a + p);
  for (int i = 0; i < t; i++) val[i] = read();
  spfa();
}
