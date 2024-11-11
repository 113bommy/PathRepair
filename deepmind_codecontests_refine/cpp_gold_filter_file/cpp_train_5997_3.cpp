#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> g[N];
int n, m, k, q, x, y, id;
int vis[N], root[N], l[N], r[N];
void dfs(int u, int p) {
  l[u] = ++id;
  for (auto v : g[u])
    if (v != p) dfs(v, u);
  r[u] = id;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &q);
  while (k--) {
    scanf("%d %d", &x, &y);
    if (vis[y]) root[x] = vis[y];
    vis[y] = x;
  }
  for (int i = 1; i <= n; i++) g[root[i]].push_back(i);
  for (int i = 1; i <= n; i++)
    if (!l[i]) dfs(i, 0);
  while (q--) {
    scanf("%d%d", &x, &y);
    y = vis[y];
    if (l[x] <= l[y] && r[x] >= l[y])
      printf("%d\n", r[x] - l[x] + 1);
    else
      puts("0");
  }
  return 0;
}
