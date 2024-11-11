#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar())
    x = (x << 1) + (x << 3) + ch - '0';
  return x * f;
}
const int N = 5e5 + 5;
int dep[N], pre[N], max_dep, max_ver;
vector<int> G[N], ver[N];
bool vis[N];
void dfs(int u) {
  vis[u] = 1;
  ver[dep[u]].push_back(u);
  if (dep[u] > max_dep) {
    max_dep = dep[u];
    max_ver = u;
  }
  for (int v : G[u])
    if (!vis[v]) dep[v] = dep[u] + 1, pre[v] = u, dfs(v);
}
int main() {
  int T = read();
  while (T--) {
    int n = read(), m = read();
    for (int i = 1; i <= m; ++i) {
      int u = read(), v = read();
      G[u].push_back(v);
      G[v].push_back(u);
    }
    max_dep = 0;
    dep[1] = 1;
    dfs(1);
    if (max_dep >= (n + 1) / 2) {
      puts("PATH");
      printf("%d\n", max_dep);
      for (int i = max_ver; i; i = pre[i]) printf("%d ", i);
      puts("");
    } else {
      puts("PARING");
      int ans = 0;
      for (int i = 1; i <= max_dep; ++i) ans += ver[i].size() / 2;
      printf("%d\n", ans);
      for (int i = 1; i <= max_dep; ++i)
        for (int j = 0; j < ver[i].size() - 1; j += 2)
          printf("%d %d\n", ver[i][j], ver[i][j + 1]);
    }
    for (int i = 1; i <= n; ++i) G[i].clear(), ver[i].clear(), vis[i] = 0;
  }
  return 0;
}
