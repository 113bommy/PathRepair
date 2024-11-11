#include <bits/stdc++.h>
#pragma GCC optimize("-Ofast", "-funroll-all-loops")
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 2e5 + 10;
long long n, a[N], dp[N][2], dep[N], ans[N], sz[N], now;
vector<long long> g[N];
inline void add(long long a, long long b) {
  g[a].push_back(b), g[b].push_back(a);
}
void dfs1(long long x, long long fa) {
  dep[x] = dep[fa] + 1;
  dp[x][dep[x] % 2]++;
  sz[x] = 1;
  for (long long to : g[x])
    if (to != fa) {
      dfs1(to, x);
      sz[x] += sz[to];
      dp[x][0] += dp[to][0], dp[x][1] += dp[to][1];
      ans[x] = (ans[x] + dp[to][dep[x] % 2] * (n - sz[to]) % mod) % mod;
      ans[x] = (ans[x] - dp[to][1 ^ (dep[x] % 2)] * (n - sz[to]) % mod) % mod;
    }
}
void dfs2(long long x, long long fa) {
  for (long long to : g[x])
    if (to != fa) {
      ans[to] = (ans[to] +
                 (dp[n][dep[to] % 2] - dp[to][dep[to] % 2]) * sz[to] % mod) %
                mod;
      ans[to] =
          (ans[to] - (dp[n][1 ^ (dep[to] % 2)] - dp[to][1 ^ (dep[to] % 2)]) *
                         sz[to] % mod) %
          mod;
      dfs2(to, x);
    }
}
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (long long i = 1, a, b; i < n; i++) scanf("%lld %lld", &a, &b), add(a, b);
  dfs1(n, 0);
  dfs2(n, 0);
  for (long long i = 1; i <= n; i++) ans[i] = (ans[i] + n - 1) % mod;
  for (long long i = 1; i <= n; i++) now = (now + ans[i] * a[i] % mod) % mod;
  cout << (now + mod) % mod;
  return 0;
}
