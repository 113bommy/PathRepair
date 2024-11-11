#include <bits/stdc++.h>
using namespace std;
const int N = 250005;
int n, kk, P;
using ll = long long;
ll qpow(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % P;
    a = a * a % P;
    b >>= 1;
  }
  return ret;
}
inline int lowbit(int x) { return x & -x; }
ll fac[N], inv[N], dp[26][N];
ll dfs(int cur, int msk) {
  if (dp[cur][msk] != -1) return dp[cur][msk];
  if (!msk) {
    dp[cur][msk] = fac[n];
    for (int i = 1; i <= cur; i++)
      dp[cur][msk] = dp[cur][msk] * (kk - i + 1) % P;
    return dp[cur][msk];
  }
  dp[cur][msk] = 0;
  int tmp = msk - lowbit(msk);
  for (int i = tmp; i > 0; i = (i - 1) & tmp)
    dp[cur][msk] = (dp[cur][msk] + inv[msk - i] * dfs(cur + 1, i)) % P;
  dp[cur][msk] = (dp[cur][msk] + inv[msk] * dfs(cur + 1, 0)) % P;
  return dp[cur][msk];
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> kk >> P;
  ll ans = qpow(kk, n);
  if (n & 2) {
    cout << ans << endl;
    return 0;
  }
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % P;
  inv[n] = qpow(fac[n], P - 2);
  for (int i = n; i > 0; --i) inv[i - 1] = inv[i] * i % P;
  memset(dp, -1, sizeof(dp));
  ans = (ans - dfs(0, n) + P) % P;
  cout << ans << endl;
  return 0;
}
