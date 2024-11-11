#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const int mod = 998244353;
long long qpow(long long a, long long b) {
  long long ans = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
  }
  return ans;
}
long long gcd(long long a, long long b) { return b > 0 ? gcd(b, a % b) : a; }
int n, m, T;
long long dp[maxn][10];
vector<pair<int, int> > g[maxn];
void dfs(int u, int fa) {
  sort((g[u]).begin(), (g[u]).end());
  for (auto v : g[u]) {
    if (v.second == fa) continue;
    dfs(v.second, u);
  }
  long long x = 1, y = 1, tempy, d = g[u].size();
  for (int i = 0; i < g[u].size(); i++) {
    if (fa == g[u][i].second) {
      d = i;
      continue;
    }
    y = y * (dp[g[u][i].second][0] + dp[g[u][i].second][2]) % mod;
  }
  x = 1, tempy = y;
  for (int i = 0; i < d; i++) {
    int to = g[u][i].second;
    tempy = tempy * qpow((dp[to][0] + dp[to][2]) % mod, mod - 2) % mod;
    dp[u][0] = (dp[u][0] + tempy * x % mod * dp[to][2] % mod) % mod;
    x = x * (dp[to][0] + dp[to][1]) % mod;
  }
  dp[u][1] = x * tempy % mod;
  for (int i = d + 1; i < g[u].size(); i++) {
    int to = g[u][i].second;
    tempy = tempy * qpow((dp[to][0] + dp[to][2]) % mod, mod - 2) % mod;
    dp[u][2] = (dp[u][2] + tempy * x % mod * dp[to][2] % mod) % mod;
    x = x * (dp[to][0] + dp[to][1]) % mod;
  }
  dp[u][2] = (dp[u][2] + x) % mod;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int uu, vv;
    cin >> uu >> vv;
    g[uu].push_back({i, vv});
    g[vv].push_back({i, uu});
  }
  dfs(1, 1);
  long long ans = (dp[1][0] + dp[1][2]) % mod;
  cout << ans << endl;
  return 0;
}
