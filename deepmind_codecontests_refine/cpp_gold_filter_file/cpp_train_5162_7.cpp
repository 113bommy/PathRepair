#include <bits/stdc++.h>
using namespace std;
int64_t n, k;
const int64_t maxn = 2e5 + 42, maxk = 10;
vector<int64_t> g[maxn];
int64_t sz[maxn][maxk];
int64_t up[maxn][maxk];
int64_t ans = 0;
int64_t penalty = 0;
void dfs1(int64_t v = 0, int64_t p = 0) {
  sz[v][0] = 1;
  for (auto u : g[v]) {
    if (u == p) continue;
    dfs1(u, v);
    for (int64_t z = 0; z < k; z++) sz[v][(z + 1) % k] += sz[u][z];
  }
}
void dfs2(int64_t v = 0, int64_t p = 0) {
  for (auto u : g[v]) {
    if (u == p) continue;
    for (int64_t z = 0; z < k; z++)
      up[u][(z + 1) % k] = up[v][z] + sz[v][z] - sz[u][(z + k - 1) % k];
    dfs2(u, v);
  }
  if (v != p) {
    int64_t sm = accumulate(sz[v], sz[v] + k, 0);
    int64_t smu = accumulate(up[v], up[v] + k, 0);
    ans += smu * sz[v][0] + sm * up[v][1 % k];
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int64_t i = 0; i < n - 1; i++) {
    int64_t u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs1();
  dfs2();
  cout << ans / 2 << endl;
}
