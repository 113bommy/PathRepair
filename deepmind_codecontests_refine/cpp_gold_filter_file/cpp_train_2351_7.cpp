#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
vector<int> g[maxn];
int n, m, vis[maxn];
long long x, y;
void dfs(int t) {
  vis[t] = true;
  x += g[t].size();
  y++;
  for (auto v : g[t]) {
    if (vis[v]) continue;
    dfs(v);
  }
}
void solve() {
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    x = y = 0;
    dfs(i);
    if (x != y * (y - 1)) {
      puts("NO");
      return;
    }
  }
  puts("YES");
}
int main() {
  int u, v;
  while (scanf("%d%d", &n, &m) != EOF) {
    for (int i = 1; i <= n; i++) g[i].clear();
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    solve();
  }
  return 0;
}
