#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 69;
const int MOD = 1e9 + 7;
int n, ans, par[MAXN], depth[MAXN];
void add(int v) { par[v] = v; }
void find(int v) {
  if (par[v] != v) {
    find(par[v]);
    depth[v] = (depth[v] + depth[par[v]]) % MOD;
    par[v] = par[par[v]];
  }
}
void upd(int v, int u, int x) {
  ans = (ans + (depth[v] + x) % MOD) % MOD;
  depth[par[v]] = (depth[v] + x) % MOD;
  par[par[v]] = u;
}
int main() {
  int k, v, x;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> k, add(i);
    for (int j = 1; j <= k; j++) cin >> v >> x, find(v), upd(v, i, x);
  }
  cout << ans % MOD << "\n";
}
