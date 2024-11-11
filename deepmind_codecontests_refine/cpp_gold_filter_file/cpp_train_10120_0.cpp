#include <bits/stdc++.h>
std::pair<int, int> e[500010];
std::vector<std::pair<int, int>> g[500010];
int cnt, n, m, ff[500010], ct, cr[1000010], fa[500010], dfn[500010],
    low[500010], p[500010], f[500010], dp[500010];
void work() {
  for (int i = 0; i < ct; i++) cr[i + ct] = cr[i];
  int x = std::max_element(cr, cr + ct) - cr;
  int y = std::min_element(cr, cr + ct) - cr;
  int a, b;
  if (y < x)
    a = x, b = y + ct;
  else
    a = x, b = y;
  p[cr[y]] = cr[x];
  for (int i = a; i < b; i++)
    if (cr[i] < cr[i + 1]) {
      p[cr[y]] = 0;
      break;
    }
  if (y < x)
    a = x, b = y;
  else
    a = x + ct, b = y;
  for (int i = a; i > b; i--)
    if (cr[i] < cr[i - 1]) {
      p[cr[y]] = 0;
      break;
    }
}
void dfs(int x, int ba) {
  dfn[x] = low[x] = ++cnt;
  ff[x] = ba;
  for (auto u : g[x])
    if (u.second != ba) {
      if (!dfn[u.first])
        fa[u.first] = x, dfs(u.first, u.second),
        low[x] = std::min(low[x], low[u.first]);
      else {
        if (~dfn[u.first])
          low[x] = std::min(low[x], dfn[u.first]);
        else {
          ct = 0;
          cr[ct++] = u.second;
          int t = u.first;
          while (t != x) {
            cr[ct++] = ff[t];
            t = fa[t];
          }
          work();
        }
      }
    }
  dfn[x] = -1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, x, y, z; i <= m; i++) {
    scanf("%d%d", &x, &y);
    g[x].emplace_back(y, i);
    g[y].emplace_back(x, i);
    e[i] = std::make_pair(x, y);
  }
  for (int i = 1; i <= n; i++) dp[i] = 1;
  dfs(1, 0);
  for (int i = m; i; i--) {
    int x = e[i].first, y = e[i].second;
    f[i] = dp[x] + dp[y] - f[p[i]];
    dp[x] = dp[y] = f[i];
  }
  for (int i = 1; i <= n; i++) printf("%d ", dp[i] - 1);
  puts("");
  return 0;
}
