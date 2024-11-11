#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int MX = 3e5 + 5;
long long n, l, r, mod3[3], MOD = 1e9 + 7, dp[MX][3];
long long f(long long idx, long long rem) {
  if (idx == n) return (rem % 3 == 0);
  if (dp[idx][rem] != -1) return dp[idx][rem];
  long long ret = 0;
  for (int i = 0; i <= 2; i++) {
    ret += (mod3[i] % MOD * f(idx + 1, (rem + i) % 3) % MOD) % MOD;
    ret %= MOD;
  }
  return dp[idx][rem] = ret;
}
void solve() {
  cin >> n >> l >> r;
  for (int i = 0; i <= 2; i++) {
    mod3[i] = (r + i) / 3 - ((l + i - 1) / 3);
  }
  memset(dp, -1, sizeof(dp));
  cout << f(0, 0) << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
