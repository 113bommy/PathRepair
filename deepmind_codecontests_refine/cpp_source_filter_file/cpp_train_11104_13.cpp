#include <bits/stdc++.h>
using namespace std;
int n, m, Q, num = 0, top = 0, tot = 0, d[110010], h[110010], fa[110010][20],
             id[110010], cut[110010], dfn[110010], low[110010], vis[110010];
pair<int, int> q[110010 << 1];
struct edge {
  int x, y, next;
} mp[110010 << 1];
inline char gc() {
  static char *S, *T, buf[1 << 16];
  if (T == S) {
    T = (S = buf) + fread(buf, 1, 1 << 16, stdin);
    if (T == S) return EOF;
  }
  return *S++;
}
inline int read() {
  int x = 0, f = 1;
  char ch = gc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = gc();
  }
  while ('0' <= ch && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = gc();
  return x * f;
}
inline void ins(int x, int y) {
  mp[++num].x = x;
  mp[num].y = y;
  mp[num].next = h[x];
  h[x] = num;
  mp[++num].x = y;
  mp[num].y = x;
  mp[num].next = h[y];
  h[y] = num;
}
void dfs1(int x, int f) {
  for (int i = 1; i <= 17; i++) {
    if (!fa[x][i - 1]) break;
    fa[x][i] = fa[fa[x][i - 1]][i - 1];
  }
  id[x] = f;
  for (int i = h[x]; i; i = mp[i].next) {
    int y = mp[i].y;
    if (d[y]) continue;
    d[y] = d[x] + 1;
    fa[y][0] = x;
    dfs1(y, f);
  }
}
void tarjan(int x, int f) {
  dfn[x] = low[x] = ++tot;
  for (int i = h[x]; i; i = mp[i].next) {
    int y = mp[i].y;
    if (y == f || dfn[y] >= dfn[x]) continue;
    q[++top] = make_pair(x, y);
    if (!dfn[y]) {
      tarjan(y, x);
      low[x] = min(low[x], low[y]);
      if (low[y] >= dfn[x]) {
        int tmp = top, u, v, flag = 0;
        do {
          u = q[top].first, v = q[top--].second;
          if ((d[u] & 1) == (d[v] & 1)) {
            flag = 1;
            break;
          }
        } while (!(x == u && y == v));
        if (!flag) continue;
        top = tmp;
        do {
          u = q[tmp].first, v = q[tmp--].second;
          cut[u] = cut[v] = 1;
        } while (!(x == u && y == v));
        cut[x] = 0;
      }
    } else
      low[x] = min(low[x], dfn[y]);
  }
}
inline void dfs(int x) {
  cut[x] += cut[fa[x][0]];
  vis[x] = 1;
  for (int i = h[x]; i; i = mp[i].next) {
    int y = mp[i].y;
    if (vis[y]) continue;
    dfs(y);
  }
}
inline int lca(int x, int y) {
  if (d[x] < d[y]) swap(x, y);
  int len = d[x] - d[y];
  for (int i = 0; i <= 17; i++) {
    if (len & (1 << i)) x = fa[x][i];
  }
  if (x == y) return x;
  for (int i = 17; i >= 0; i--) {
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  }
  return fa[x][0];
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= m; i++) ins(read(), read());
  for (int i = 1; i <= n; i++) {
    if (!d[i]) d[i] = 1, dfs1(i, i), tarjan(i, 0), dfs(i);
  }
  Q = read();
  for (int i = 1; i <= Q; i++) {
    int x = read(), y = read();
    if (id[x] != id[y]) {
      puts("No");
      continue;
    }
    int z = lca(x, y);
    if ((d[x] + d[y] - 2 * d[z]) & 1) {
      puts("Yes");
      continue;
    }
    if (cut[x] + cut[y] - 2 * cut[z] > 0)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
