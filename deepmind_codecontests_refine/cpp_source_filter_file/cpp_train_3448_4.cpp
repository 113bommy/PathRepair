#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 5;
long long ww[300005], f[300005], ans;
int n;
vector<int> g[300005], w[300005];
void dfs(int u, int p) {
  int fir = 0, sec = 0;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (v == p) continue;
    dfs(v, u);
    f[v] -= w[u][i];
    if (f[v] > fir)
      sec = fir, fir = f[v];
    else if (f[v] > sec)
      sec = f[v];
  }
  ans = max(ans, fir + sec + ww[u]);
  f[u] = fir + ww[u];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &ww[i]);
  for (int i = 1; i < n; i++) {
    int u, v, www;
    scanf("%d%d%d", &u, &v, &www);
    g[u].push_back(v);
    g[v].push_back(u);
    w[u].push_back(www);
    w[v].push_back(www);
  }
  dfs(1, 0);
  printf("%lld\n", ans);
}
