#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
using namespace std;
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
const int maxn = 3000 + 5;
const long long inf = 9223372036854775807;
const long long mod = 1e9 + 7;
long long n, mark[maxn], par[maxn], ps[maxn], dp[maxn][maxn], f[maxn],
    inv[maxn], c[maxn], d, finv[maxn];
vector<int> adj[maxn];
void dfs(int v) {
  mark[v] = 1;
  for (auto u : adj[v]) {
    if (!mark[u]) {
      par[u] = v;
      dfs(u);
    }
  }
  for (auto u : adj[v]) {
    if (u != par[v]) {
      for (int i = 1; i <= n; i++) {
        dp[v][i] = (dp[v][i] * dp[u][i]) % mod;
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    dp[v][i] = (dp[v][i] + dp[v][i - 1]) % mod;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> d;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) dp[i][j] = 1;
  f[0] = f[1] = inv[1] = finv[1] = 1;
  finv[0] = 1;
  for (long long i = 2; i <= n; i++) {
    f[i] = f[i - 1] * i % mod;
    inv[i] = poww(i, mod - 2, mod);
    finv[i] = poww(f[i], mod - 2, mod);
    int x;
    cin >> x;
    adj[x].push_back(i);
    adj[i].push_back(x);
  }
  c[0] = 1;
  for (long long i = 0; i < n; i++) {
    c[i + 1] = c[i] * (d - i) % mod * inv[i + 1] % mod;
  }
  dfs(1);
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      long long x = (f[i] * inv[j] % mod * inv[i - j] % mod);
      dp[1][i] = (dp[1][i] - x * dp[1][j] % mod + mod) % mod;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + c[i] * dp[1][i] % mod) % mod;
  }
  cout << ans;
}
