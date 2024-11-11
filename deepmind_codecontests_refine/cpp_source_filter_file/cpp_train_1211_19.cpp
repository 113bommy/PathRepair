#include <bits/stdc++.h>
using namespace ::std;
const long long maxn = 110;
const long long mod = 1e9 + 7;
const long long inf = 1e9 + 500;
long long dp[maxn][maxn][maxn];
long long dpd[maxn][maxn][maxn];
long long f[maxn];
long long g[maxn];
long long sz[maxn];
vector<long long> ger[maxn];
void dfs(long long v, long long p = -1) {
  sz[v] = 1;
  dp[v][0][1] = 1;
  for (auto u : ger[v]) {
    if (u != p) {
      dfs(u, v);
      for (long long k = 0; k < sz[v]; k++) {
        for (long long s = 1; s <= sz[v]; s++) {
          for (long long i = 0; i < sz[u]; i++) {
            for (long long j = 1; j <= sz[u]; j++) {
              dpd[v][k + i][s] +=
                  (((dp[v][k][s] * dp[u][i][j]) % mod * j) % mod);
              dpd[v][k + i + 1][s + j] += (dp[v][k][s] * dp[u][i][j]) % mod;
            }
          }
        }
      }
      for (long long i = 0; i < maxn; i++) {
        for (long long j = 0; j < maxn; j++) {
          dp[v][i][j] = dpd[v][i][j] % mod;
          dpd[v][i][j] = 0;
        }
      }
      sz[v] += sz[u];
    }
  }
}
long long poww(long long a, long long b) {
  if (b == -1) {
    return poww(a, mod - 2);
  }
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % mod;
    }
    a = (a * a) % mod;
    b /= 2;
  }
  return ans;
}
long long fac[maxn];
long long rfac[maxn];
long long ent(long long n, long long k) {
  if (n < k || k < 0) {
    return 0;
  }
  return (((fac[n] * rfac[k]) % mod) * rfac[n - k]) % mod;
}
int main() {
  fac[0] = 1;
  for (long long i = 1; i < maxn; i++) {
    fac[i] = (fac[i - 1] * i) % mod;
  }
  for (long long i = 0; i < maxn; i++) {
    rfac[i] = poww(fac[i], mod - 2);
  }
  long long n;
  cin >> n;
  for (long long i = 1; i < n; i++) {
    long long v, u;
    cin >> v >> u;
    v--;
    u--;
    ger[u].push_back(v);
    ger[v].push_back(u);
  }
  dfs(0);
  for (long long k = 0; k < n; k++) {
    for (long long s = 1; s <= n; s++) {
      f[k] += (dp[0][k][s] * s) % mod;
    }
    f[k] %= mod;
    f[k] *= poww(n, n - k - 2);
    f[k] %= mod;
  }
  for (long long i = n - 1; i >= 0; i--) {
    g[i] = f[i];
    for (long long j = i + 1; j < n; j++) {
      g[i] -= g[j] * ent(j, i);
    }
    g[i] %= mod;
    g[i] += mod;
    g[i] %= mod;
  }
  for (long long i = 0; i < n; i++) {
    cout << g[i] << ' ';
  }
}
