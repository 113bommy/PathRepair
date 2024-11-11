#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rnd64(
    chrono::high_resolution_clock::now().time_since_epoch().count());
long long power(long long a, long long m, long long mod) {
  long long ans = 1;
  while (m) {
    if (m % 2) ans *= a, ans %= (mod);
    a = (a * a) % mod;
    m >>= 1;
  }
  return ans;
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
  size_t operator()(pair<int64_t, int64_t> Y) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
  }
};
const long long inf = 1e18;
const long long M = 1000000007;
vector<long long> adj[3101];
long long dp[3101][3101];
long long n, d;
long long vis[3101];
void dfs(long long node, long long par) {
  long long j;
  vis[node] = 1;
  for (j = 1; j < n + 11; j++) dp[node][j] = 1;
  for (auto i : adj[node]) {
    if (!vis[i]) dfs(i, node);
  }
  for (j = 2; j < n + 11; j++) dp[node][j] += dp[node][j - 1], dp[node][j] %= M;
  if (par != -1)
    for (j = 1; j < n + 11; j++) dp[par][j] *= dp[node][j], dp[par][j] %= M;
}
void solve() {
  long long i, j, _;
  cin >> n >> d;
  for (i = 0; i < n - 1; i++) {
    cin >> j;
    adj[j].push_back(i + 2);
  }
  dfs(1, -1);
  long long ans = 0;
  n += 10;
  for (i = 1; i <= n; i++) {
    long long p = 1, p1 = 1;
    for (j = 1; j <= n; j++) {
      if (i != j) {
        p = p * ((d - j + M) % M) % M;
        p1 = p1 * (i - j + M) % M;
      }
    }
    p *= power(p1, M - 2, M);
    p %= M;
    ans = ans + (p * dp[1][i] % M);
    ans %= M;
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
