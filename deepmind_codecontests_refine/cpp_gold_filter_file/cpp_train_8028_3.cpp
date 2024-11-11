#include <bits/stdc++.h>
long long res, ans;
std::vector<long long> a, sum;
std::vector<std::vector<int>> g;
void dfs(int v, int p = -1, int h = 0) {
  res += 1LL * h * a[v];
  sum[v] = a[v];
  for (size_t i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (to == p) continue;
    dfs(to, v, h + 1);
    sum[v] += sum[to];
  }
}
void dfs2(int v, int p = -1) {
  ans = std::max(ans, res);
  for (size_t i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (to == p) continue;
    res -= sum[to];
    sum[v] -= sum[to];
    res += sum[v];
    sum[to] += sum[v];
    dfs2(to, v);
    sum[to] -= sum[v];
    res -= sum[v];
    sum[v] += sum[to];
    res += sum[to];
  }
}
int main() {
  int n;
  scanf("%d", &n);
  a.resize(n);
  g.resize(n);
  sum.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }
  dfs(0);
  dfs2(0);
  printf("%lld\n", ans);
  return 0;
}
