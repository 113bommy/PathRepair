#include <bits/stdc++.h>
using namespace std;
const long long N = 3005;
const long long mod = 1e9 + 7;
void add(long long &a, long long b) {
  a += b;
  if (a < 0) a += mod;
  if (a > mod) a -= mod;
}
long long qpow(long long a, long long e) {
  long long ans = 1;
  while (e) {
    if (e & 1) ans = ans * a % mod;
    a = a * a % mod;
    e >>= 1;
  }
  return ans;
}
vector<long long> g[N];
long long n, D, f[N][N];
void dfs(long long u) {
  for (long long i = 1; i < N; ++i) f[u][i] = 1;
  for (long long v : g[u]) {
    dfs(v);
    for (long long i = 2; i < N; ++i) f[u][i] = f[u][i] * f[v][i] % mod;
  }
  for (long long i = 1; i < N; ++i) add(f[u][i], f[u][i - 1]);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> D;
  for (long long i = 2; i <= n; ++i) {
    long long p;
    cin >> p;
    g[p].push_back(i);
  }
  dfs(1);
  if (D < N) return cout << f[1][D], 0;
  long long nume = 1, deno = 1;
  for (long long i = 2; i < N; ++i)
    nume = nume * (D - i) % mod, deno = deno * (1 - i) % mod;
  long long ans = f[1][1] * nume % mod;
  ans = ans * qpow(deno, mod - 2) % mod;
  for (long long i = 2; i < N; ++i) {
    nume = nume * (D - i + 1) % mod;
    nume = nume * qpow(D - i, mod - 2) % mod;
    deno = deno * (i - 1) % mod;
    deno = deno * qpow(i - N, mod - 2) % mod;
    long long res = f[1][i] * nume % mod;
    res = res * qpow(deno, mod - 2) % mod;
    add(ans, res);
  }
  cout << ans << endl;
}
