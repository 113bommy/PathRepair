#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int sum[N], n, k, m, q, l, r, dfs_id, vis[N];
vector<int> g[N];
bool tag[N];
void dfs(int u) {
  vis[u] = ++dfs_id;
  for (int v : g[u]) {
    if (!vis[v]) dfs(v);
  }
}
int check(int u) {
  if (tag[u]) return 0;
  for (int v : g[u]) {
    if (v < l || v > r) continue;
    if (vis[v] < vis[u]) return 0;
  }
  return 1;
}
int main() {
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1];
    if (!vis[i]) {
      dfs(i);
      tag[i] = true;
      ++sum[i];
    }
  }
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d", &l, &r);
    int ret = sum[r] - sum[l - 1];
    for (int i = l; i <= min(r, l + k - 1); ++i) ret += check(i);
    for (int i = max(l + k, r - k + 1); i <= r; ++i) ret += check(i);
    printf("%d\n", ret);
  }
  return 0;
}
