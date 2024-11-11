#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
const int inf = 1 << 30;
const int mod = 998244353;
struct point {
  int x, y, flag;
  bool operator<(const point &a) const { return a.flag < flag; }
} s, q;
priority_queue<point> qwe;
int n, m, k;
char a[maxn][maxn];
int vis[maxn][maxn];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int Bfs(int x, int y, int ex, int ey) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      vis[i][j] = inf;
    }
  }
  s.x = x, s.y = y, s.flag = 0;
  qwe.push(s);
  while (!qwe.empty()) {
    s = qwe.top();
    qwe.pop();
    if (s.x == ex && s.y == ey) return s.flag;
    for (int i = 0; i < 4; i++) {
      for (int j = 1; j <= k; j++) {
        int xx = s.x + dx[i] * j;
        int yy = s.y + dy[i] * j;
        if (xx < 1 || yy < 1 || xx > n || yy > m) break;
        if (a[xx][yy] == '#') break;
        if (s.flag + 1 >= vis[xx][yy]) continue;
        vis[xx][yy] = s.flag + 1;
        q.x = xx, q.y = yy, q.flag = s.flag + 1;
        if (q.x == ex && q.y == ey) return q.flag;
        qwe.push(q);
      }
    }
  }
  return -1;
}
int main() {
  int sx, sy, ex, ey;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf(" %s", a[i] + 1);
  scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
  int ans = Bfs(sx, sy, ex, ey);
  printf("%d\n", ans);
  return 0;
}
