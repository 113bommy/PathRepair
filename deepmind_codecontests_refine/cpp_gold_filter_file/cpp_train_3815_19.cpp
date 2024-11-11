#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, mod = 1e9 + 9;
int par[maxn];
int parent(int u) {
  if (par[u] == u) return u;
  return par[u] = parent(par[u]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int ans = 1;
  for (int i = 1; i <= n; i++) par[i] = i;
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (parent(u) == parent(v))
      ans = (ans * 2ll) % mod;
    else
      par[parent(u)] = parent(v);
    cout << (ans - 1 + mod) % mod << "\n";
  }
  return 0;
}
