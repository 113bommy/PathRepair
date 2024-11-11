#include <bits/stdc++.h>
using namespace std;
struct UF {
  vector<int> e;
  UF(int n) : e(n, -1) {}
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};
char s[300030];
pair<int, int> a[300030];
vector<pair<int, int>> g[300030];
int t, n, k, m, x, d[300030], cnt[3][300030], ans;
void dfs(int v, int p, int s) {
  if (s)
    d[v] = d[p];
  else
    d[v] = 3 - d[p];
  for (auto u : g[v])
    if (!d[u.first]) dfs(u.first, v, u.second);
}
int main() {
  scanf("%d%d%s", &n, &k, s + 1);
  UF uf(k + 1);
  d[k + 1] = 2;
  for (int i = 1; i <= n; i++) s[i] -= '0';
  for (int i = 1; i <= k; i++)
    for (int j = !scanf("%d", &m); j < m; j++)
      if (scanf("%d", &x), a[x].first) {
        a[x].second = i;
        g[a[x].first].emplace_back(i, s[x]);
        g[i].emplace_back(a[x].first, s[x]);
      } else
        a[x].first = i;
  for (int i = 1; i <= n; i++)
    if (a[i].first && a[i].second == 0) g[0].emplace_back(a[i].first, s[i]);
  for (int i = 0; i <= k; i++)
    if (!d[i]) dfs(i, k + 1, 0);
  for (int i = 1; i <= k; i++) cnt[d[i]][i] = 1;
  cnt[1][0] = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++) {
    int u = uf.find(a[i].first), v = uf.find(a[i].second);
    if (uf.join(u, v)) {
      ans -= min(cnt[1][u], cnt[2][u]);
      ans -= min(cnt[1][v], cnt[2][v]);
      for (int j = 1; j <= 2; j++)
        cnt[j][u] = cnt[j][v] = cnt[j][u] + cnt[j][v];
      ans += min(cnt[1][u], cnt[2][u]);
    }
    printf("%d\n", ans);
  }
}
