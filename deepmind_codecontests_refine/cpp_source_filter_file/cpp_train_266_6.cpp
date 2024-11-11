#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")
const int maxn = 1e4 + 10, maxm = 1e6 + 10, lg = 22, mod = 998244353,
          inf = 1e18;
int n, k, l, dis[maxn], dd[lg][lg], dp[(1 << lg)];
bool b[maxn];
vector<int> g[maxn];
void bfs(int src) {
  memset(dis, 69, sizeof(dis));
  dis[src] = 0;
  queue<int> q;
  q.push(src);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto u : g[v])
      if (dis[u] >= maxn) dis[u] = dis[v] + 1, q.push(u);
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k >> l;
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    b[x - 1] ^= 1;
    b[x] ^= 1;
  }
  for (int i = 1; i <= l; i++) {
    int x;
    cin >> x;
    for (int j = 0; j + x <= n; j++)
      g[j].push_back(j + x), g[j + x].push_back(j);
  }
  vector<int> o;
  for (int i = 0; i <= n; i++)
    if (b[i]) o.push_back(i);
  for (int i = 0; i < (int)(o.size()); i++) {
    bfs(o[i]);
    for (int j = 0; j < (int)(o.size()); j++) dd[i][j] = dis[o[j]];
  }
  memset(dp, 69, sizeof(dp));
  dp[0] = 0;
  for (int msk = 1; msk < (1 << (int)(o.size())); msk++)
    if ((__builtin_popcount(msk)) % 2 == 0) {
      int fur = -1;
      for (int i = 0; i < (int)(o.size()); i++)
        if (msk >> i & 1) {
          if (fur == -1) {
            fur = i;
            continue;
          }
          if (dd[fur][i])
            dp[msk] =
                min(dp[msk], dp[msk ^ (1 << fur) ^ (1 << i)] + dd[fur][i]);
        }
    }
  if (dp[(1 << (int)(o.size())) - 1] >= mod)
    cout << -1;
  else
    cout << dp[(1 << (int)(o.size())) - 1];
  return 0;
}
