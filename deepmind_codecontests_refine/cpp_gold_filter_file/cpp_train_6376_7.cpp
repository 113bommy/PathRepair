#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
int dblcmp(double d) {
  if (fabs(d) < eps) return 0;
  return d > eps ? 1 : -1;
}
int dx[] = {-1, 0, 0, 1, -1, 1, -1, 1};
int dy[] = {0, 1, -1, 0, -1, -1, 1, 1};
const int maxn = 1111;
char s[maxn][maxn];
int a[maxn][maxn], v[maxn][maxn], d[maxn][maxn], n, m, cas = 0;
int idx[maxn][maxn];
int fa[maxn * maxn];
int f(int x) { return fa[x] == x ? x : fa[x] = f(fa[x]); }
void u(int x, int y) {
  x = f(x);
  y = f(y);
  if (x != y) fa[x] = y;
}
int bfs(int sx, int sy) {
  int i, j, k;
  ++cas;
  queue<pair<int, int> > q;
  q.push(make_pair(sx, sy));
  v[sx][sy] = 1;
  vector<pair<int, int> > o;
  while (!q.empty()) {
    pair<int, int> t = q.front();
    q.pop();
    int x = t.first, y = t.second;
    for (i = 0; i < 8; i++) {
      int tx = x + dx[i];
      int ty = y + dy[i];
      if (tx < 0 || tx > n || ty < 0 || ty > m) {
        return -1;
      }
      {
        if (!a[tx][ty] && !v[tx][ty]) {
          v[tx][ty] = 1;
          q.push(make_pair(tx, ty));
        }
      }
    }
    for (i = 0; i < 8; i++) {
      int tx = x + dx[i];
      int ty = y + dy[i];
      if (tx >= 0 && ty >= 0 && tx < n && ty < m && a[tx][ty]) {
        if (d[tx][ty] < cas) o.push_back(make_pair(tx, ty));
        d[tx][ty] = cas;
      }
    }
  }
  int rt = -1;
  for (i = 0; i < (int)((o).size()); i++) {
    int x = o[i].first, y = o[i].second, c = 0;
    if (rt == -1)
      rt = f(idx[x][y]);
    else if (rt != f(idx[x][y]))
      return -1;
    for (j = 0; j < 4; j++) {
      int tx = x + dx[j], ty = y + dy[j];
      if (tx < 0 || tx > n || ty < 0 || ty > m) continue;
      c += (d[tx][ty] == cas);
    }
    if (c != 2) return -1;
  }
  return (int)((o).size());
}
int main() {
  int i, j, k;
  scanf("%d%d", &n, &m);
  for (i = 0; i < n; i++) scanf("%s", s[i]);
  memset((a), 0, sizeof(a));
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) a[i][j] = (s[i][j] == '1');
  }
  int ans = 0, cnt = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]) ans = 4;
      idx[i][j] = cnt++;
    }
  }
  for (i = 0; i < 1111111; i++) fa[i] = i;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
      if (a[i][j]) {
        if (i - 1 >= 0 && a[i - 1][j]) u(idx[i][j], idx[i - 1][j]);
        if (j - 1 >= 0 && a[i][j - 1]) u(idx[i][j], idx[i][j - 1]);
      }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
      if (!a[i][j] && !v[i][j]) {
        ans = max(ans, bfs(i, j));
      }
  }
  printf("%d\n", ans);
  return 0;
}
