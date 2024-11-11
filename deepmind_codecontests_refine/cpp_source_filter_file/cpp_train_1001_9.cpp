#include <bits/stdc++.h>
using namespace std;
inline int read(int f = 1, int x = 0, char ch = ' ') {
  while (!isdigit(ch = getchar()))
    if (ch == '-') f = -1;
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
const int N = 1e5 + 5;
struct Edge {
  int next, to;
  long long w;
  Edge(int next = 0, int to = 0, long long w = 0) : next(next), to(to), w(w){};
} edge[N << 1];
int tot = 1, head[N];
void _add(int x, int y) { edge[++tot] = Edge(head[x], y), head[x] = tot; }
void add(int x, int y) { _add(x, y), _add(y, x); }
int n, m, f[N], g[N], d[N], vis[N], e[N], t;
long long c[N], w[N];
int dfs(int x, int fi) {
  vis[x] = 1, f[x] = fi;
  for (int i = head[x]; i; i = edge[i].next)
    if (i != fi) {
      int y = edge[i].to;
      if (vis[y] && ((d[y] ^ d[x] ^ 1) & 1))
        g[x] = i;
      else if (!vis[y])
        vis[y] = 1, d[y] = d[x] + 1, c[x] -= dfs(y, i ^ 1);
    }
  return edge[fi].w = edge[fi ^ 1].w = c[x];
}
void print() {
  puts("YES");
  for (int i = 1; i <= m; ++i) printf("%I64d\n", edge[i << 1].w);
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; ++i) c[i] = read();
  for (int i = 1; i <= m; ++i) {
    int x = read(), y = read();
    add(x, y);
  }
  d[1] = 1, dfs(1, 0);
  if (c[1] == 0) return print(), 0;
  if (~c[1] & 1)
    for (int o = 1; o <= n; ++o)
      if (g[o]) {
        if (d[o] & 1)
          edge[g[o]].w = edge[g[o] ^ 1].w += c[1] >> 1;
        else
          edge[g[o]].w = edge[g[o] ^ 1].w -= c[1] >> 1;
        for (int i = f[edge[g[o]].to], j = d[edge[g[o]].to] - 1; j;
             i = f[edge[i].to], --j)
          if (j & 1)
            edge[i].w = edge[i ^ 1].w += c[1] >> 1;
          else
            edge[i].w = edge[i ^ 1].w -= c[1] >> 1;
        for (int i = f[o], j = d[o] - 1; j; i = f[edge[i].to], --j)
          if (j & 1)
            edge[i].w = edge[i ^ 1].w += c[1] >> 1;
          else
            edge[i].w = edge[i ^ 1].w -= c[1] >> 1;
        return print(), 0;
      }
  puts("NO");
  return 0;
}
