#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFLL = 1e18;
const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 5;
vector<pair<int, int> > g[MAXN];
int sz[MAXN];
int k, n, t;
long long G, B;
void dfsSZ(int v, int p = -1) {
  sz[v] = 1;
  for (auto x : g[v])
    if (x.second != p) {
      int u = x.second;
      dfsSZ(u, v);
      sz[v] += sz[u];
      B += 1ll * min(sz[u], n - sz[u]) * x.first;
      G += (sz[u] % 2) * x.first;
    }
}
int main() {
  scanf("%d", &t);
  while (t--) {
    G = B = 0;
    scanf("%d", &k);
    n = 2 * k;
    for (int i = 0; i < (int)n - 1; i++) {
      int u, v, t;
      scanf("%d", &u), scanf("%d", &v);
      scanf("%d", &t);
      u--, v--;
      g[v].push_back({t, u});
      g[u].push_back({t, v});
    }
    for (int i = 0; i < (int)n; i++)
      sort(g[i].begin(), g[i].end(), greater<pair<int, int> >());
    dfsSZ(0);
    printf("%lld %lld\n", G, B);
    for (int i = 0; i < (int)n; i++) g[i].clear();
  }
  return 0;
}
