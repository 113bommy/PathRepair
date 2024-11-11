#include <bits/stdc++.h>
using namespace std;
const int MX = 3e5 + 5, MXX = 23;
const long long mod = 998244353, inf = 1e18 + 6;
long long d0[MX], d10[MX], d11[MX];
vector<int> G[MX];
long long multi(long long x, long long y) { return (x * y) % mod; }
void dfs(int u, int par) {
  d0[u] = 1;
  if (G[u].size() - (u > 0)) d10[u] = d11[u] = 1;
  for (auto v : G[u])
    if (v != par) {
      dfs(v, u);
      d11[u] = multi(d11[u], (d11[v] + 2 * d10[v] + 2 * d0[v]) % mod);
      d10[u] = multi(d10[u], (2 * d11[v] + 2 * d10[v] + 3 * d0[v]) % mod);
      d0[u] = multi(d0[u], (d11[v] + d10[v] + d0[u]) % mod);
    }
  if (G[u].size() - (u > 0))
    d10[u] = (d10[u] - d0[u] + mod) % mod,
    d11[u] = (d11[u] - d0[u] + mod) % mod;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(9);
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(0, -1);
  cout << (d0[0] + d11[0] + d10[0] - 1 + mod) % mod << endl;
  return 0;
}
