#include <bits/stdc++.h>
namespace IO {
char ibuf[(1 << 21) + 1], *iS, *iT;
char Get() {
  return (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, (1 << 21) + 1, stdin),
                      (iS == iT ? EOF : *iS++))
                   : *iS++);
}
int read() {
  int x = 0, c = Get();
  while (!isdigit(c)) c = Get();
  while (isdigit(c)) x = x * 10 + c - 48, c = Get();
  return x;
}
}  // namespace IO
using IO::read;
const int N = 100007;
std::vector<int> e[N];
int t, cnt, top, dep[N], fa[N][17], root[N], sum[N], dfn[N], low[N], stk[N],
    ins[N], bel[N], is[N];
void dfs(int u) {
  for (int i = 1; i <= 16; ++i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int v : e[u])
    if (!dep[v]) fa[v][0] = u, dep[v] = dep[u] + 1, root[v] = root[u], dfs(v);
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) std::swap(u, v);
  for (int i = 16; ~i; --i)
    if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
  for (int i = 16; ~i; --i)
    if (fa[u][i] ^ fa[v][i]) u = fa[u][i], v = fa[v][i];
  return u ^ v ? fa[0][u] : u;
}
void dfs2(int u) {
  for (int v : e[u])
    if (fa[v][0] == u) sum[v] += sum[u], dfs2(v);
}
void tarjan(int u, int fa) {
  dfn[u] = low[u] = ++t, stk[++top] = u, ins[u] = 1;
  for (int v : e[u])
    if (v ^ fa)
      !dfn[v] ? (tarjan(v, u), low[u] = std::min(low[u], low[v]))
              : low[u] = std::min(low[u], dfn[v]);
  if (dfn[u] == low[u])
    for (++cnt; stk[top + 1] ^ u;) ins[stk[top]] = 0, bel[stk[top--]] = cnt;
}
int main() {
  int n = read(), m = read();
  for (int i = 1, u, v; i <= m; ++i)
    u = read(), v = read(), e[u].push_back(v), e[v].push_back(u);
  for (int u = 1; u <= n; ++u)
    if (!dep[u]) dep[u] = 1, dfs(root[u] = u);
  for (int u = 1; u <= n; ++u)
    if (dep[u] == 1) tarjan(u, 0);
  for (int u = 1; u <= n; ++u)
    if (!is[bel[u]])
      for (int v : e[u])
        if (!((dep[u] + dep[v]) & 1) && bel[u] == bel[v]) {
          is[bel[u]] = 1;
          break;
        }
  for (int u = 1; u <= n; ++u)
    if (fa[u][0] && bel[u] == bel[fa[u][0]] && is[bel[u]]) ++sum[u];
  for (int u = 1; u <= n; ++u)
    if (dep[u] == 1) dfs2(u);
  for (int q = read(), u, v; q; --q)
    u = read(), v = read(),
    puts(root[u] ^ root[v] || u == v ||
                 (!((dep[u] + dep[v]) & 1) &&
                  sum[u] + sum[v] == 2 * sum[lca(u, v)])
             ? "No"
             : "Yes");
}
