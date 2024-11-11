#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int mod = 998244353;
int sz[N];
vector<int> E[N];
long long fac[N], inv[N], inv_f[N];
long long base, ans;
int dfs(int u, int par) {
  sz[u] = 1;
  for (auto v : E[u]) {
    if (v != par) {
      sz[u]++;
      dfs(v, u);
    }
  }
  if (u != 1)
    base = base * fac[sz[u]] % mod;
  else
    base = base * fac[sz[u] - 1] % mod;
  return sz[u];
}
void solve(int u, int par) {
  ans = (ans + base) % mod;
  for (auto v : E[u]) {
    if (v != par) {
      base = base * inv_f[sz[v]] % mod * inv_f[sz[u] - 1] % mod;
      sz[v]++;
      sz[u]--;
      base = base * fac[sz[v] - 1] % mod * fac[sz[u]] % mod;
      solve(v, u);
      base = base * inv_f[sz[v] - 1] % mod * inv_f[sz[u]] % mod;
      sz[v]--;
      sz[u]++;
      base = base * fac[sz[v]] % mod * fac[sz[u] - 1] % mod;
    }
  }
}
void pre_calc(int lim, int m) {
  fac[0] = fac[1] = 1;
  inv[1] = inv[0] = 1;
  inv_f[0] = inv_f[1] = 1;
  for (int i = 2; i <= lim; i++) {
    fac[i] = fac[i - 1] * i % m;
  }
  for (int i = 2; i <= lim; i++) {
    inv[i] = (m - m / i) * inv[m % i] % m;
    inv_f[i] = inv_f[i - 1] * inv[i] % m;
  }
}
int main(void) {
  int n;
  scanf("%d", &n);
  pre_calc(n, mod);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    E[u].push_back(v);
    E[v].push_back(u);
  }
  base = 1;
  dfs(1, 1);
  solve(1, 1);
  printf("%lld\n", ans);
}
