#include <bits/stdc++.h>
using namespace std;
int n, m;
bool vis[55];
vector<long long> base;
long long ans[55];
const long long mod = 998244353LL;
void dfs(long long mask, int d) {
  if (d == base.size()) {
    ++ans[__builtin_popcountll(mask)];
    return;
  }
  dfs(mask, d + 1);
  dfs(mask ^ base[d], d + 1);
}
void solve1() {
  dfs(0LL, 0);
  long long mul = 1;
  for (int i = base.size() + 1; i <= n; ++i) (mul <<= 1) %= mod;
  for (int i = 0; i <= m; ++i)
    printf("%lld%c", ans[i] * mul % mod, " \n"[i == m]);
}
long long dp[36][36][1 << 14];
void solve2() {
  for (long long b : base) {
    for (int i = m - 1; ~i; --i)
      if ((b >> i) & 1) {
        vis[i] = true;
        break;
      }
  }
  vector<int> trans;
  for (int i = 0; i < m; ++i)
    if (!vis[i]) trans.push_back(i);
  for (long long &b : base) {
    for (int i = 0; i < trans.size(); ++i)
      if ((b >> trans[i]) & 1)
        b |= 1LL << i;
      else
        b &= ~(1LL << i);
    b &= (1LL << trans.size()) - 1;
  }
  dp[0][0][0] = 1;
  for (int i = 1; i <= base.size(); ++i)
    for (int mask = 0; mask < (1 << trans.size()); ++mask) {
      dp[i][0][mask] = dp[i - 1][0][mask];
      dp[i][i][mask] = dp[i - 1][i - 1][mask ^ base[i - 1]];
      for (int j = 1; j < i; ++j)
        dp[i][j][mask] =
            (dp[i - 1][j][mask] + dp[i - 1][j - 1][mask ^ base[i - 1]]) % mod;
    }
  for (int mask = 0; mask < (1 << trans.size()); ++mask)
    for (int i = 0; i <= base.size(); ++i)
      (ans[i + __builtin_popcount(mask)] += dp[base.size()][i][mask]) %= mod;
  long long mul = 1;
  for (int i = base.size() + 1; i <= n; ++i) (mul <<= 1) %= mod;
  for (int i = 0; i <= m; ++i)
    printf("%lld%c", ans[i] * mul % mod, " \n"[i == m]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    long long x;
    scanf("%lld", &x);
    for (long long b : base)
      if ((x ^ b) < x) x ^= b;
    if (!x) continue;
    for (long long &b : base)
      if ((x ^ b) < b) b ^= x;
    base.push_back(x);
  }
  if (base.size() <= 20)
    solve1();
  else
    solve2();
  return 0;
}
