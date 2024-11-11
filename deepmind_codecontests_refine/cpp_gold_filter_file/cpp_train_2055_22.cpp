#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long double eps = 1e-7;
const int inf = 1000000010;
const long long INF = 10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 3010, LOG = 20;
long long n, D, k, u, v, x, y, t, a, b, ans;
long long dp[MAXN][MAXN];
long long F[MAXN], I[MAXN];
long long f[MAXN];
vector<int> G[MAXN];
long long powmod(long long a, long long b) {
  if (!b) return 1;
  if (b & 1) return a * powmod(a * a % mod, b >> 1) % mod;
  return powmod(a * a % mod, b >> 1);
}
long long C(long long n, long long r) {
  if (r < 0 || r > n) return 0;
  if (n < MAXN) return (F[n] * I[r] % mod) * I[n - r] % mod;
  long long res = I[r];
  for (int i = n; i > n - r; i--) res = res * i % mod;
  return res;
}
void dfs(int node) {
  for (int i = 1; i <= n; i++) dp[node][i] = 1;
  for (int v : G[node]) {
    dfs(v);
    for (int i = 1; i <= n; i++) dp[node][i] = dp[node][i] * dp[v][i] % mod;
  }
  for (int i = 2; i <= n; i++)
    dp[node][i] = (dp[node][i] + dp[node][i - 1]) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  F[0] = 1;
  for (int i = 1; i < MAXN; i++) F[i] = F[i - 1] * i % mod;
  I[MAXN - 1] = powmod(F[MAXN - 1], mod - 2);
  for (int i = MAXN - 1; i; i--) I[i - 1] = I[i] * i % mod;
  cin >> n >> D;
  for (int i = 2; i <= n; i++) cin >> x, G[x].push_back(i);
  dfs(1);
  for (int i = 1; i <= n; i++) f[i] = dp[1][i];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < i; j++) f[i] = (f[i] - C(i, j) * f[j]) % mod;
  for (int i = 1; i <= n; i++) ans += f[i] * C(D, i) % mod;
  ans %= mod;
  if (ans < 0) ans += mod;
  cout << ans << '\n';
  return 0;
}
