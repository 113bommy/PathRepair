#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], u[maxn], v[maxn];
int vis[maxn], ans[maxn];
vector<int> G[maxn];
int dfs(int x) {
  vis[x] = 1;
  int ret = a[x];
  for (int i = 0; i < G[x].size(); ++i) {
    int to, d;
    if (u[G[x][i]] == x)
      to = v[G[x][i]], d = -1;
    else
      to = u[G[x][i]], d = 1;
    if (vis[to]) continue;
    int flow = dfs(to);
    ans[G[x][i]] = d * flow;
    ret += flow;
  }
  return ret;
}
int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d", u + i, v + i);
    G[u[i]].push_back(i);
    G[v[i]].push_back(i);
  }
  int ok = 1;
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    if (dfs(i)) ok = 0;
  }
  if (!ok)
    puts("Impossible");
  else {
    puts("Possible");
    for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
  }
  return 0;
}
