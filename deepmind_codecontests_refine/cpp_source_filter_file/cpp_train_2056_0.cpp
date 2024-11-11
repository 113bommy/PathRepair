#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long maxn = 3e3 + 100;
const long long mod = 1e9 + 7;
const long double PI = acos((long double)-1);
long long pw(long long a, long long b, long long md = mod) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (a * res) % md;
    }
    a = (a * a) % md;
    b >>= 1;
  }
  return (res);
}
long long n;
long long d;
vector<long long> adj[maxn];
long long inv[maxn];
long long x;
long long dp[maxn][maxn];
long long Dp[maxn];
long long fact[maxn][2];
void dfs(long long v = 1) {
  for (auto u : adj[v]) dfs(u);
  for (long long i = 1; i <= x; i++) {
    long long res = 1;
    for (auto u : adj[v]) res = (res * dp[u][i]) % mod;
    dp[v][i] = (dp[v][i - 1] + res) % mod;
  }
  if (adj[v].size() == 0)
    for (long long i = 1; i <= x; i++) dp[v][i] = i;
}
long long c(long long r, long long n) {
  return ((fact[n][0] * (fact[r][1] * fact[n - r][1]) % mod) % mod);
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> d;
  fact[0][0] = fact[0][1] = 1;
  for (long long i = 1; i < maxn; i++)
    fact[i][0] = (fact[i - 1][0] * i) % mod,
    fact[i][1] = pw(fact[i][0], mod - 2);
  for (long long i = 2; i <= n; i++) {
    long long par;
    cin >> par;
    adj[par].push_back(i);
  }
  x = min((long long)n, d);
  for (long long i = 1; i <= x; i++) {
    inv[i] = ((d - i + 1) * 1LL * pw(i, mod - 2)) % mod;
    if (i > 1) inv[i] = (inv[i - 1] * inv[i]) % mod;
  }
  dfs();
  long long ans = 0;
  for (long long i = 1; i <= x; i++) {
    Dp[i] = dp[1][i];
    for (long long j = 1; j < i; j++)
      Dp[i] = (Dp[i] - (Dp[j] * c(j, i)) % mod + mod) % mod;
    ans = (ans + (Dp[i] * inv[i]) % mod) % mod;
  }
  cout << ans;
  return (0);
}
