#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)3e5 + 7;
const int infint = (int)1e9;
const long long inf = (long long)1e18;
long long n, a[MAXN], par[MAXN][20], h[MAXN], lg[MAXN];
vector<long long> G[MAXN];
void dfs(int u, int p) {
  par[u][0] = p;
  for (auto v : G[u])
    if (v != p) h[v] = h[u] + 1, dfs(v, u);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int root = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] < a[root] || root == 0) root = i;
  memset(par, -1, sizeof par);
  dfs(root, -1);
  long long sm = 0;
  for (int i = 1; i < 20; i++)
    for (int j = 1; j <= n; j++)
      if (par[j][i - 1] != -1) par[j][i] = par[par[j][i - 1]][i - 1];
  lg[1] = 0;
  for (int i = 1; i <= n; i++) lg[i] = lg[(i + 1) / 2] + 1;
  for (int i = 1; i <= n; i++) {
    if (i == root) continue;
    long long mn = inf;
    for (int j = 0; j < 20; j++)
      if (par[i][j] != -1) mn = min(mn, a[i] + a[par[i][j]] + j * a[par[i][j]]);
    mn = min(mn, a[i] + a[root] + lg[h[i]] * a[root]);
    sm += mn;
  }
  cout << sm;
}
