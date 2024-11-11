#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
int match[maxn], p[maxn], c[maxn], k[maxn], ans[maxn], n, m, d;
bool vis[maxn], book[maxn];
std::vector<int> G[maxn];
bool dfs(int u) {
  if (vis[u]) return false;
  vis[u] = true;
  for (auto &v : G[u]) {
    if (match[v] == -1 || dfs(match[v])) {
      match[v] = u;
      return true;
    }
  }
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  memset(match, -1, sizeof match);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
  scanf("%d", &d);
  for (int i = 1; i <= d; i++) {
    scanf("%d", &k[i]);
    book[k[i]] = 1;
  }
  for (int i = 1; i <= n; i++)
    if (!book[i]) G[p[i]].emplace_back(c[i]);
  for (int i = d; i >= 1; i--) {
    ans[i] = ans[i + 1];
    while (1) {
      memset(vis, false, sizeof vis);
      if (dfs(ans[i]))
        ans[i]++;
      else
        break;
    }
    G[p[k[i]]].emplace_back(c[k[i]]);
  }
  for (int i = 1; i <= d; i++) printf("%d\n", ans[i]);
  return 0;
}
