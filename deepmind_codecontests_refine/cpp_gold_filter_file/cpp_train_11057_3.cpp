#include <bits/stdc++.h>
using namespace std;
long long G;
long long B;
int n;
vector<pair<int, int> > adj[200005];
int dfs(int u, int p) {
  int rt = 1;
  for (auto v : adj[u])
    if (v.first != p) {
      int sz = dfs(v.first, u);
      rt += sz;
      G += (sz & 1) * v.second;
      B += 1ll * min(sz, n - sz) * v.second;
    }
  return rt;
}
int main() {
  int t;
  for (scanf("%d", &t); t--;) {
    scanf("%d", &n);
    n *= 2;
    for (int i = 1, u, v, w; i < n; ++i) {
      scanf("%d%d%d", &u, &v, &w);
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }
    G = 0;
    B = 0;
    dfs(1, 1);
    printf("%lld %lld\n", G, B);
    for (int i = 1; i <= n; ++i) adj[i].clear();
  }
}
