#include <bits/stdc++.h>
using namespace std;
const int a1[4] = {0, 0, 1, -1}, a2[4] = {1, -1, 0, 0};
struct ww {
  int x, y, t;
  inline void read() { scanf("%d%d%d", &x, &y, &t); }
} d1[2000], d2[2000], O;
int i, j, k, n, m, n1, n2, s, num, S, T, t;
int dis[30][30][30][30];
char p[30][30];
pair<int, int> e[2000];
map<pair<int, int>, int> d;
int bi[600000], liu[600000], ne[600000], he[2000], g[2000], F[2000], gg[2000];
inline void add(int x, int y, int z) {
  bi[++t] = y, liu[t] = z, ne[t] = he[x], he[x] = t;
  bi[++t] = x, liu[t] = 0, ne[t] = he[y], he[y] = t;
}
inline bool bfs() {
  int l, r, v;
  g[l = r = 1] = S;
  gg[S] = 0;
  F[S] = ++num;
  for (; l <= r; l++) {
    int A = g[l];
    for (v = he[A]; v; v = ne[v])
      if (liu[v] && F[bi[v]] != num) {
        F[bi[v]] = num, g[++r] = bi[v], gg[bi[v]] = gg[A] + 1;
        if (bi[v] == T) return 1;
      }
  }
  return 0;
}
int dfs(int x, int y) {
  if (x == T) return y;
  int w = 0, v, re;
  for (v = he[x]; v && w < y; v = ne[v]) {
    int A = bi[v];
    if (liu[v] && F[A] == num && gg[A] == gg[x] + 1 &&
        (re = dfs(A, min(y - w, liu[v]))))
      liu[v] -= re, liu[v ^ 1] += re, w += re;
  }
  if (!w) gg[x] = 0;
  return w;
}
inline void fail() {
  printf("-1\n");
  exit(0);
}
inline void bfs(int x, int y) {
  int l, r, i;
  d.clear();
  e[l = r = 1] = make_pair(x, y);
  d[make_pair(x, y)] = 0;
  for (; l <= r; l++) {
    pair<int, int> A = e[l];
    dis[x][y][A.first][A.second] = d[A];
    for (i = 0; i <= 3; i++) {
      int x = A.first + a1[i], y = A.second + a2[i];
      if (x && y && x <= n && y <= m && p[x][y] == '.' &&
          !d.count(make_pair(x, y))) {
        e[++r] = make_pair(x, y);
        d[make_pair(x, y)] = d[A] + 1;
      }
    }
  }
}
inline int C(int x, int y, int z) { return z * n * m + (x - 1) * m + y - 1; }
inline bool ju(long long ti) {
  int i, j, u, r, an = 0;
  S = n * m * 4 + 1, T = S + 1, t = 1;
  for (i = 0; i <= T; i++) he[i] = 0;
  for (i = 1; i <= n1; i++) {
    add(S, i - 1, 1);
    long long ci = ti / d1[i].t;
    for (u = 1; u <= n; u++)
      for (r = 1; r <= m; r++) {
        int A = dis[d1[i].x][d1[i].y][u][r];
        if (A < 0 || A > ci) continue;
        add(i - 1, C(u, r, 1), 1);
      }
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) add(C(i, j, 1), C(i, j, 2), 1);
  for (i = 1; i <= n2; i++) {
    add(n * m * 3 + i - 1, T, 1);
    long long ci = ti / d2[i].t;
    for (u = 1; u <= n; u++)
      for (r = 1; r <= m; r++) {
        int A = dis[d2[i].x][d2[i].y][u][r];
        if (A < 0 || A > ci) continue;
        add(C(u, r, 2), n * m * 3 + i - 1, 1);
      }
  }
  for (; bfs(); an += dfs(S, 2000))
    ;
  return an == n1;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &n1, &n2);
  if ((n1 + n2) % 2 == 0) fail();
  for (i = 1; i <= n; i++) {
    scanf("%s", p[i] + 1);
    for (j = 1; j <= m; j++) s += p[i][j] == '.';
  }
  O.read();
  for (i = 1; i <= n1; i++) d1[i].read();
  for (i = 1; i <= n2; i++) d2[i].read();
  if (n1 > n2) {
    for (i = 1; i <= n1; i++) swap(d1[i], d2[i]);
    swap(n1, n2);
  }
  if (n1 + 1 != n2 || s < n2) fail();
  d1[++n1] = O;
  memset(dis, 255, sizeof(dis));
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (p[i][j] == '.') bfs(i, j);
  long long l = 0, r = (long long)1e15, mid;
  for (; l <= r;) {
    mid = (l + r) / 2;
    if (ju(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%I64d\n", r > 1e10 ? -1 : r + 1);
  return 0;
}
