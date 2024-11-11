#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, lt;
  long long v;
} e[200100];
struct node {
  int x;
  long long dis;
  node() {}
  node(int _x, long long _dis) { x = _x, dis = _dis; }
};
struct point {
  int x, y;
  long long v, dx, dy;
} p[2100];
bool operator<(node a, node b) { return a.dis > b.dis; }
priority_queue<node> que;
bool vis[2100];
long long f[2][2100][2100];
int in[2100], cnt, n, m;
map<long long, int> mx, my;
int cnx, cny;
long long dis[2100];
void add(int x, int y, long long v) {
  e[++cnt].to = y;
  e[cnt].lt = in[x];
  e[cnt].v = v;
  in[x] = cnt;
  e[++cnt].to = x;
  e[cnt].lt = in[y];
  e[cnt].v = v;
  in[y] = cnt;
}
void dij(int s) {
  memset(dis, 63, sizeof(dis));
  memset(vis, 0, sizeof(vis));
  dis[s] = 0;
  que.push(node(s, dis[s]));
  while (!que.empty()) {
    node cur = que.top();
    que.pop();
    if (vis[cur.x]) continue;
    vis[cur.x] = 1;
    long long tmp = cur.dis;
    for (int i = in [cur.x]; i; i = e[i].lt) {
      int y = e[i].to;
      if (dis[y] > tmp + e[i].v)
        dis[y] = tmp + e[i].v, que.push(node(y, dis[y]));
    }
  }
}
long long mp[2100][2100], sz[2100][2100];
void sum() {
  for (int i = 1; i <= cnx + 1; i++)
    for (int j = 1; j <= cny + 1; j++) {
      mp[i][j] = mp[i][j] + mp[i - 1][j] + mp[i][j - 1] - mp[i - 1][j - 1];
      sz[i][j] = sz[i][j] + sz[i - 1][j] + sz[i][j - 1] - sz[i - 1][j - 1];
    }
}
long long get(int x1, int y1, int x2, int y2) {
  return mp[x2][y2] - mp[x1 - 1][y2] - mp[x2][y1 - 1] + mp[x1 - 1][y1 - 1];
}
long long size(int x1, int y1, int x2, int y2) {
  if (y2 < y1 || x2 < x1) return 0;
  return sz[x2][y2] - sz[x1 - 1][y2] - sz[x2][y1 - 1] + sz[x1 - 1][y1 - 1];
}
int main() {
  int s, t, x, y;
  long long v;
  scanf("%d%d", &n, &m);
  scanf("%d%d", &s, &t);
  for (int i = 1; i <= n; i++) scanf("%I64d", &p[i].v);
  for (int i = 1; i <= m; i++) scanf("%d%d%I64d", &x, &y, &v), add(x, y, v);
  dij(s);
  for (int i = 1; i <= n; i++) p[i].dx = dis[i];
  sort(dis + 1, dis + n + 1);
  for (int i = 1; i <= n; i++)
    if (!mx[dis[i]]) mx[dis[i]] = ++cnx;
  for (int i = 1; i <= n; i++) p[i].x = mx[p[i].dx];
  dij(t);
  for (int i = 1; i <= n; i++) p[i].dy = dis[i];
  sort(dis + 1, dis + n + 1);
  for (int i = 1; i <= n; i++)
    if (!my[dis[i]]) my[dis[i]] = ++cny;
  for (int i = 1; i <= n; i++)
    p[i].y = my[p[i].dy], mp[p[i].x][p[i].y] += p[i].v, sz[p[i].x][p[i].y]++;
  sum();
  for (int i = cnx + 1; i; i--) {
    for (int j = cny + 1; j; j--) {
      if (size(i, j, i, cny))
        f[0][i][j] = max(f[0][i + 1][j], f[1][i + 1][j]) + get(i, j, i, cny);
      else
        f[0][i][j] = f[0][i + 1][j];
      if (size(i, j, cnx, j))
        f[1][i][j] = min(f[0][i][j + 1], f[1][i][j + 1]) - get(i, j, cnx, j);
      else
        f[1][i][j] = f[1][i][j + 1];
    }
  }
  if (f[0][1][1] > 0) printf("Break a heart\n");
  if (f[0][1][1] == 0) printf("Flowers\n");
  if (f[0][1][1] < 0) printf("Cry\n");
  return 0;
}
