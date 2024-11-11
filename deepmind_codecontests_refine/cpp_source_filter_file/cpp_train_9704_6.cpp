#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const long long INF = 8e18;
const int maxn = 1e5 + 5;
long long ans, ans2;
int n;
vector<pair<int, int> > e[maxn];
int sz[maxn];
inline void init(int n) {
  ans = ans2 = 0;
  for (int i = 0; i < n + 5; ++i) {
    e[i].clear();
    sz[i] = 0;
  }
}
inline void dfs(int u, int pre) {
  sz[u] = 1;
  for (auto &x : e[u]) {
    int v = x.first, w = x.second;
    if (v == pre) continue;
    dfs(v, u);
    sz[u] += sz[v];
    if (sz[v] & 1) ans += w;
    ans2 += min(sz[v], n - sz[v]) * w;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    n <<= 1;
    for (int i = 0; i < n - 1; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      e[u].push_back({v, w});
      e[v].push_back({u, w});
    }
    dfs(1, 1);
    cout << ans << ' ' << ans2 << '\n';
    init(n);
  }
  return 0;
}
