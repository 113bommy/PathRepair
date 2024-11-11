#include <bits/stdc++.h>
using namespace std;
struct edge {
  long long to, dis, id, next;
} e[504032 << 1];
inline long long read() {
  long long x = 0, w = 0;
  char ch = getchar();
  while (!isdigit(ch)) w |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  return w ? -x : x;
}
long long n, m, cnt, head[504032], fa[504032][21], dep[504032], top[504032],
    ef[504032], f[504032];
long long find(long long k) { return f[k] == k ? k : f[k] = find(f[k]); }
void add(long long u, long long v, long long d, long long id) {
  e[++cnt].to = v;
  e[cnt].dis = d;
  e[cnt].id = id;
  e[cnt].next = head[u];
  head[u] = cnt;
}
void dfs(long long u, long long id) {
  for (long long j = 1; j <= 20; ++j) fa[u][j] = fa[fa[u][j - 1]][j - 1];
  for (long long i = head[u]; i; i = e[i].next) {
    long long v = e[i].to;
    if (v == fa[u][0]) continue;
    if (e[i].dis == e[id].dis && e[i].dis == 1)
      f[find(e[i].id)] = find(e[id].id);
    dep[v] = dep[u] + 1;
    fa[v][0] = u;
    ef[v] = e[i].id;
    top[e[i].id] = u;
    dfs(v, i);
  }
}
long long LCA(long long x, long long y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (long long i = 20; i >= 0; --i)
    if ((1 << i) <= dep[x] - dep[y]) x = fa[x][i];
  if (x == y) return x;
  for (long long i = 20; i >= 0; --i)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
signed main() {
  n = read(), m = read();
  for (long long i = 1; i <= n; ++i) f[i] = i;
  for (long long i = 1; i < n; ++i) {
    long long u = read(), v = read(), d = read();
    add(u, v, d, i);
    add(v, u, d, i);
  }
  dfs(1, 0);
  while (m--) {
    long long op = read();
    if (op == 1) {
      long long x = read(), y = read(), v = read();
      long long lca = LCA(x, y);
      while (v && dep[x] > dep[lca]) {
        v /= e[ef[x] << 1].dis;
        x = top[find(ef[x])];
      }
      while (v && dep[y] > dep[lca]) {
        v /= e[ef[y] << 1].dis;
        y = top[find(ef[y])];
      }
      printf("%d\n", v);
    } else {
      long long p = read(), v = read(), x = e[p << 1].to, y = e[p * 2 - 1].to;
      if (dep[x] < dep[y]) swap(x, y);
      e[(p - 1) << 1 | 1].dis = e[p << 1].dis = v;
      if (v == 1) {
        for (long long i = head[x]; i; i = e[i].next) {
          long long v = e[i].to;
          if (e[i].id != p && e[i].dis == 1) f[find(e[i].id)] = p, top[p] = y;
        }
        for (long long i = head[y]; i; i = e[i].next) {
          long long v = e[i].to;
          if (e[i].id != p && e[i].dis == 1) f[p] = find(e[i].id);
        }
      }
    }
  }
  return 0;
}
