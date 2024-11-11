#include <bits/stdc++.h>
const int N = 1005, M = 200005;
struct qry {
  int r, s, t, id;
};
std::vector<qry> q[M];
int n, m, Q, ans[N], l, r, s, t, ex[M], ey[M];
int dis[N][N];
void Min(int &x, int y) {
  if (y < x) x = y;
}
int main() {
  scanf("%d%d%d", &n, &m, &Q);
  for (int i = 1; i <= m; i++) scanf("%d%d", &ex[i], &ey[i]);
  for (int i = 1; i <= Q; i++) {
    scanf("%d%d%d%d", &l, &r, &s, &t);
    q[l].push_back({r, s, t, i});
  }
  memset(dis, 0x3f, sizeof(dis));
  for (int i = m; i >= 1; i--) {
    int x = ex[i], y = ey[i];
    dis[x][y] = dis[y][x] = i;
    for (int j = 1; j <= n; j++)
      Min(dis[x][j], dis[y][j]), Min(dis[y][j], dis[x][j]);
    for (qry j : q[i])
      if (dis[j.s][j.t] <= j.r) ans[j.id] = 1;
  }
  for (int i = 1; i <= Q; i++) puts(ans[i] ? "YES" : "NO");
}
