#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
long long dp[maxn], pd[maxn], h[maxn], sz[maxn];
int par[maxn][35], n, q;
vector<int> adj[maxn];
void dfs_dn(int x, int PAR) {
  for (auto child : adj[x]) {
    if (child == PAR) continue;
    par[child][0] = x;
    h[child] = h[x] + 1;
    dfs_dn(child, x);
    sz[x] += sz[child];
    dp[x] += dp[child] + sz[child];
  }
}
void dfs_up(int x, int PAR) {
  for (auto child : adj[x]) {
    if (child == PAR) continue;
    pd[child] = pd[x] + dp[x] - dp[child] - 2 * sz[child] + n;
    dfs_up(child, x);
  }
}
inline int UP(int v, int H) {
  for (int i = 30; i >= 0; i--)
    if (H & (1 << i)) v = par[v][i];
  return v;
}
inline int LCA(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  u = UP(u, h[u] - h[v]);
  if (u == v) return u;
  for (int i = 30; i > 0; i--)
    if (par[v][i] != par[u][i]) v = par[v][i], u = par[u][i];
  return par[u][0];
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout.precision(10);
  cin >> n >> q;
  for (int i = 0; i < n - 1; i++) {
    int fi, se;
    cin >> fi >> se;
    fi--, se--;
    adj[fi].push_back(se);
    adj[se].push_back(fi);
  }
  for (int i = 0; i < n; i++) sz[i] = 1;
  memset(par, -1, sizeof par);
  dfs_dn(0, -1);
  dfs_up(0, -1);
  for (int j = 1; j <= 30; j++)
    for (int i = 0; i <= 30; i++)
      par[i][j] = (par[i][j - 1] == -1) ? -1 : par[par[i][j - 1]][j - 1];
  while (q--) {
    int v, u;
    cin >> v >> u;
    v--, u--;
    if (h[u] < h[v]) swap(u, v);
    int PAR = LCA(u, v), len = h[v] + h[u] - 2 * h[PAR];
    if (PAR != v)
      cout << fixed
           << (dp[v] / (long double)sz[v]) + (dp[u] / (long double)sz[u]) +
                  (long double)len + 1;
    else {
      int x = UP(u, h[u] - h[v] - 1);
      cout << fixed
           << (dp[u] / (long double)sz[u]) +
                  (pd[x] - n + sz[x]) / (long double)(n - sz[x]) +
                  (long double)len + 1;
    }
    cout << endl;
  }
  return 0;
}
