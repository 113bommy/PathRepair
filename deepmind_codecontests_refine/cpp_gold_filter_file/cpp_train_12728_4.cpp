#include <bits/stdc++.h>
using namespace std;
const long long base = 211, mod = 1e9 + 7;
const int maxn = 2e5 + 100;
int p[30];
vector<pair<int, int> > g[maxn];
vector<int> e[maxn];
long long res[30][30];
int n, m, k;
int ans = 0;
long long sum = 0, val[maxn];
void dfs(int pos) {
  if (pos > k) {
    long long sumP = 0;
    for (int i = 1; i <= k; i++) sumP = (sumP + res[i][p[i]]) % mod;
    if (sumP == sum) {
      ans++;
    }
    return;
  }
  for (p[pos] = 1; p[pos] <= pos; p[pos]++) dfs(pos + 1);
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[w].push_back({u, v});
  }
  for (int i = 1; i <= m; i++) {
    for (auto eg : g[i]) {
      int u = eg.first;
      int v = eg.second;
      e[u].push_back(v);
    }
  }
  val[0] = 1;
  for (int i = 1; i <= n; i++) {
    val[i] = (val[i - 1] * base) % mod;
    sum += val[i];
    sum %= mod;
  }
  for (int u = 1; u <= n; u++) {
    for (int j = 0; j < e[u].size(); j++) {
      int v = e[u][j];
      res[e[u].size()][j + 1] = (res[e[u].size()][j + 1] + val[v]) % mod;
    }
  }
  dfs(1);
  cout << ans;
  return 0;
}
