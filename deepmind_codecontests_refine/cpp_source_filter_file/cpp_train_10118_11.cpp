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
  Edge(int next = 0, int to = 0) : next(next), to(to){};
} edge[N << 1];
int tot, head[N];
void add(int x, int y) { edge[++tot] = Edge(head[x], y), head[x] = tot; }
int n, fa[N], dfn[N], t, f[N], to[N], d[N], ans;
void dfs(int x) {
  dfn[++t] = x;
  for (int i = head[x]; i; i = edge[i].next) {
    int y = edge[i].to;
    if (y == to[x]) continue;
    dfs(y);
  }
  if (to[x]) dfs(to[x]);
}
int main() {
  n = read();
  for (int i = 2; i <= n; ++i) add(fa[i] = read() + 1, i), d[i] = d[fa[i]] + 1;
  for (int i = n; i > 1; --i)
    f[fa[i]] = max(f[fa[i]], f[i] + 1),
    to[fa[i]] = f[i] >= f[to[fa[i]]] ? i : to[fa[i]];
  dfs(1);
  for (int i = 1; i <= n; ++i) printf("%d ", dfn[i] - 1);
  puts("");
  for (int i = n; i > 1; --i) ans += d[dfn[i - 1]] - d[fa[dfn[i]]];
  printf("%d\n", ans);
  for (int i = n; i > 1; --i)
    for (int j = 1; j <= d[dfn[i - 1]] - d[fa[dfn[i]]]; ++j)
      printf("%d ", dfn[i] - 1);
  puts("");
  return 0;
}
