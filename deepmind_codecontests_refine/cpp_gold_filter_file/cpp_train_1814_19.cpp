#include <bits/stdc++.h>
using namespace std;
const double sqrt3 = sqrt(3);
struct edges {
  int to, pre;
} e[(23 * 23 * 280 * 4)];
int h[23 * 23 * 280], etop, id[23][23][280], d[23 * 23 * 280], a[23][23];
queue<int> q;
inline int add_edge(int u, int v) {
  return e[++etop].to = v, e[etop].pre = h[u], h[u] = etop;
}
struct P {
  int x, y, val;
  P(int _x = 0, int _y = 0, int _v = 0) { x = _x, y = _y, val = _v; }
} p[30];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
inline int bfs(int s, int n) {
  while (!q.empty()) q.pop();
  for (int i = 1; i <= n; i++) d[i] = (INT_MAX / 20 - 10);
  d[s] = 0, q.push(s);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = h[x], y; i; i = e[i].pre)
      if (d[y = e[i].to] == (INT_MAX / 20 - 10)) d[y] = d[x] + 1, q.push(y);
  }
  return 0;
}
struct V {
  double x, y;
  V(double _x = 0, double _y = 0) { x = _x, y = _y; }
};
inline double cross(const V &a, const V &b) { return a.x * b.y + a.y * b.x; }
inline int sgn(double x) { return (x < 0) ? -1 : (x > 0); }
int main() {
  int n, m, ans = 0, sx = 0, sy = 0;
  int nc = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    static char s[23];
    scanf("%s", s + 1);
    for (int j = 1; j <= m; j++)
      if (s[j] == 'S')
        sx = i, sy = j, a[i][j] = 0;
      else if (s[j] == '#')
        a[i][j] = 1;
      else if (s[j] == '.')
        a[i][j] = 0;
      else if (s[j] == 'B')
        a[i][j] = 3;
      else
        p[s[j] - '1'] = P(i, j, 0), nc = max(nc, s[j] - '0'), a[i][j] = 2;
  }
  for (int i = 0; i < nc; i++) scanf("%d", &p[i].val);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j] == 3) p[nc++] = P(i, j, (INT_MIN / 20 + 10));
  int all = (1 << nc) - 1, c = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int s = 0; s <= all; s++) id[i][j][s] = ++c;
  for (int s = 0; s <= all; s++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        for (int k = 0; k <= 3; k++) {
          if (a[i][j]) continue;
          int x = i + dx[k], y = j + dy[k], t = s;
          if (x <= 0 || x > n || y <= 0 || y > m || a[x][y]) continue;
          for (int q = 0; q <= nc - 1; q++) {
            int px = p[q].x, py = p[q].y;
            V v1(px - i, j - py), v2(px - x, y - py), v3(1, sqrt3);
            int s1 = sgn(cross(v3, v1)), s2 = sgn(cross(v3, v2));
            if (s1 != s2 && py <= min(j, y)) t ^= (1 << q);
          }
          add_edge(id[i][j][s], id[x][y][t]);
        }
  bfs(id[sx][sy][0], c);
  for (int s = 0, v; s <= all; ans = max(ans, v - d[id[sx][sy][s]]), s++)
    for (int i = v = 0; i < nc; i++)
      if ((s >> i) & 1) v += p[i].val;
  return !printf("%d\n", ans);
}
