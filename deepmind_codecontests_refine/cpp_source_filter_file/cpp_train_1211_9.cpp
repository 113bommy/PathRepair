#include <bits/stdc++.h>
using namespace std;
const long long maxn = 110;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
long long n, dp[maxn][maxn][maxn], sz[maxn], d2[maxn], pd[maxn][maxn],
    C[maxn][maxn];
vector<long long> g[maxn];
bool vis[maxn];
long long pw(long long a, long long b) {
  if (b < 0) b += mod - 1;
  long long c = 1;
  while (b) {
    if (b & 1) c = c * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return c;
}
void dfs(long long v) {
  vis[v] = 1;
  sz[v] = 1;
  dp[v][0][1] = 1;
  for (long long u : g[v]) {
    if (vis[u]) continue;
    dfs(u);
    for (long long i2 = 0; i2 < sz[v]; i2++) {
      for (long long j2 = 1; j2 <= sz[v]; j2++) {
        for (long long i = 0; i < sz[u]; i++) {
          for (long long j = 1; j <= sz[u]; j++) {
            pd[i2 + i + 1][j2 + j] = dp[v][i2][j2] * dp[u][i][j];
            pd[i2 + i + 1][j2 + j] %= mod;
            pd[i2 + i][j2] += dp[v][i2][j2] * dp[u][i][j] % mod * j;
            pd[i2 + i][j2] %= mod;
          }
        }
      }
    }
    sz[v] += sz[u];
    for (long long i = 0; i < sz[v]; i++) {
      for (long long j = 1; j <= sz[v]; j++) {
        dp[v][i][j] = pd[i][j];
        pd[i][j] = 0;
      }
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  C[0][0] = 1;
  for (long long i = 1; i < maxn; i++) {
    C[i][0] = 1;
    for (long long j = 1; j < maxn; j++) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
      if (C[i][j] >= mod) C[i][j] -= mod;
    }
  }
  cin >> n;
  for (long long i = 1; i < n; i++) {
    long long v, u;
    cin >> v >> u;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  dfs(1);
  for (long long i = 0; i < n; i++) {
    for (long long j = 1; j <= n; j++) {
      d2[i] = (d2[i] + dp[1][i][j] * pw(n, n - i - 2) % mod * j) % mod;
    }
  }
  for (long long i = n; i--;) {
    for (long long j = i + 1; j < n; j++) {
      d2[i] = (d2[i] - d2[j] * C[j][i]) % mod;
    }
  }
  for (long long i = 0; i < n; i++) {
    cout << (d2[i] + mod) % mod << " ";
  }
  return 0;
}
