#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * power(a * a % md, b / 2, md) % md
                      : power(a * a % md, b / 2, md) % md));
}
const int xn = 1e6 + 10;
const int xm = 20;
const int sq = 320;
const int inf = 1e9 + 10;
const long long INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;
int n, k, dp[xn], par[xm][xn], c, ptr, col[xn];
pair<int, int> E[xn + xn];
vector<int> adj[2][xn], G[xn], topo;
bool mark[xn], leaf[xn];
void add_edge(int v, int u) {
  adj[0][v].push_back(u);
  adj[1][u].push_back(v);
  E[ptr++] = {v, u};
}
void DFS(int v) {
  mark[v] = true;
  for (int u : adj[0][v])
    if (!mark[u]) DFS(u);
  topo.push_back(v);
}
void SFD(int v, int x) {
  mark[v] = true;
  col[v] = x;
  dp[x] += leaf[v];
  for (int u : adj[1][v])
    if (!mark[u]) SFD(u, x);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> k;
  memset(leaf, true, sizeof leaf);
  for (int i = 2; i <= n; ++i) {
    cin >> par[0][i];
    add_edge(par[0][i], i);
    leaf[par[0][i]] = false;
  }
  par[0][1] = 1;
  for (int i = 1; i < xm; ++i)
    for (int v = 1; v <= n; ++v) par[i][v] = par[i - 1][par[i - 1][v]];
  for (int i = 1; i <= n; ++i) {
    if (!leaf[i]) continue;
    int v = i, d = k;
    for (int i = xm - 1; i >= 0; --i)
      if ((1 << i) <= d) v = par[i][v], d -= (1 << i);
    add_edge(i, v);
  }
  for (int i = 1; i <= n; ++i)
    if (!mark[i]) DFS(i);
  memset(mark, false, sizeof mark);
  reverse(topo.begin(), topo.end());
  for (int v : topo)
    if (!mark[v]) SFD(v, ++c);
  for (int i = 0; i < ptr; ++i) {
    int v = E[i].first, u = E[i].second;
    if (col[v] != col[u]) G[col[v]].push_back(col[u]);
  }
  for (int v = c; v >= 1; --v) {
    int mx = 0;
    for (int u : G[v]) mx = max(mx, dp[u]);
    dp[v] += mx;
  }
  cout << dp[col[1]] << '\n';
  return 0;
}
