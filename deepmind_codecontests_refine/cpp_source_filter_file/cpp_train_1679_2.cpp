#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, LOG = 19;
long long ans;
int a[N], par[N][LOG];
vector<int> g[N];
void dfs(int v) {
  for (int i = 1; i < LOG; i++) par[v][i] = par[par[v][i - 1]][i - 1];
  for (int u : g[v])
    if (par[v][0] != u) par[u][0] = v, dfs(u);
  if (v != par[v][0]) {
    long long mn = 1e18;
    for (int i = 0; i < LOG; i++)
      mn = min(mn, 1ll * a[par[v][i]] * (i + 1) + a[v]);
    ans += mn;
  }
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, root = 1;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i), root = (a[root] < a[i] ? root : i);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v), g[v].push_back(u);
  }
  dfs(par[root][0] = root), printf("%I64d\n", ans);
  return 0;
}
