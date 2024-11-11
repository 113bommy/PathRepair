#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 500;
vector<int> g[N];
int n, k, U[N], up[N][20], tin[N], tout[N], t, deep[N], untin[2 * N];
void dfs(int u, int par) {
  tin[u] = ++t;
  untin[t] = u;
  up[u][0] = par;
  for (int i = 1; i < 20; i++) {
    up[u][i] = up[up[u][i - 1]][i - 1];
  }
  for (auto v : g[u]) {
    if (v == par) continue;
    deep[v] = deep[u] + 1;
    dfs(v, u);
  }
  tout[u] = ++t;
}
bool upper(int u, int v) {
  if (tin[u] <= tin[v] && tout[u] >= tout[v]) return 1;
  return 0;
}
int lca(int u, int v) {
  if (upper(u, v)) return u;
  if (upper(v, u)) return v;
  for (int i = 19; i >= 0; i--) {
    if (!upper(up[u][i], v)) {
      u = up[u][i];
    }
  }
  return up[u][0];
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= 2 * k; i++) scanf("%d", U + i);
  for (int i = 0, u, v; i < n - 1; i++)
    scanf("%d%d", &u, &v), g[v].push_back(u), g[u].push_back(v);
  deep[1] = 0;
  dfs(1, 1);
  vector<int> v;
  for (int i = 1; i <= 2 * k; i++) v.push_back(tin[U[i]]);
  sort((v).begin(), (v).end());
  for (int i = 0; i < 2 * k; i++) v[i] = untin[v[i]];
  long long res = 0;
  for (int i = 0; i < k; i++) {
    res += deep[v[i]] + deep[v[i + k]] - 2LL * deep[lca(v[i], v[i + k])];
  }
  printf("%lld\n", res);
}
