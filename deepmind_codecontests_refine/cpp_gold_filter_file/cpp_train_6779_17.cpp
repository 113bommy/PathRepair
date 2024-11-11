#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const long long N = 3e5 + 10;
const long long mod = 998244353;
long long read() {
  long long MisakaMkikotoIsMyWife;
  scanf("%lld", &MisakaMkikotoIsMyWife);
  return MisakaMkikotoIsMyWife;
}
vector<long long> G[N];
long long n, g[3], f[N][3];
void dfs(long long u, long long fa) {
  long long siz = G[u].size();
  f[u][0] = 1;
  for (long long i = 0; i < siz; i++) {
    long long v = G[u][i];
    if (v == fa) continue;
    dfs(v, u);
    g[0] = 1ll * f[u][0] * (f[v][0] + f[v][2]) % mod;
    g[1] = (f[u][1] * (f[v][2] * 2 + f[v][0]) % mod + f[u][0] * f[v][2] % mod) %
           mod;
    g[2] = (f[u][0] * (f[v][1] + f[v][0]) % mod +
            f[u][1] * (f[v][1] + f[v][0]) % mod +
            f[u][2] * (f[v][2] * 2 + f[v][0]) % mod) %
           mod;
    swap(f[u], g);
  }
}
int main() {
  n = read();
  for (long long i = 1; i < n; i++) {
    long long u = read(), v = read();
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 0);
  cout << (f[1][0] + f[1][2]) % mod;
}
