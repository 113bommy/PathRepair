#include <bits/stdc++.h>
using namespace std;
const int N = 250002;
vector<int> G[N], vec;
int dep[N], d1, d2, d3, x, y, u, k, n, m, mx, i, fa[N];
bool leaf[N], vis[N];
void dfs(int u) {
  if (dep[u] > dep[mx]) mx = u;
  vis[u] = leaf[u] = 1;
  for (auto v : G[u])
    if (!vis[v]) {
      leaf[u] = 0, dep[v] = dep[u] + 1, fa[v] = u;
      dfs(v);
    }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (i = 1; i <= m; i++)
    scanf("%d%d", &x, &y), G[x].push_back(y), G[y].push_back(x);
  dep[1] = 1, dfs(1);
  if (dep[mx] > n / k) {
    printf("PATH\n%d\n", dep[mx]);
    for (i = mx; i; i = fa[i]) printf("%d ", i);
  } else {
    puts("CYCLES");
    for (u = 1; u <= n && k; u++)
      if (leaf[u]) {
        k--;
        vec.clear();
        for (auto v : G[u])
          if (v != fa[u]) vec.push_back(v);
        x = vec[0], y = vec[1];
        if (dep[x] > dep[y]) swap(x, y);
        d1 = dep[x], d2 = dep[y], d3 = dep[u];
        if ((d3 - d1 + 1) % 3) {
          printf("%d\n", d3 - d1 + 1);
          for (i = u; i != fa[x]; i = fa[i]) printf("%d ", i);
        } else if ((d3 - d2 + 1) % 3) {
          printf("%d\n", d3 - d2 + 1);
          for (i = u; i != fa[y]; i = fa[i]) printf("%d ", i);
        } else {
          printf("%d\n%d ", d2 - d1 + 2, u);
          for (i = y; i != fa[x]; i = fa[i]) printf("%d ", i);
        }
        puts("");
      }
  }
}
