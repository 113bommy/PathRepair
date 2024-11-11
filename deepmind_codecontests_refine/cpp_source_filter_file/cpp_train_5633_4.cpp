#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
const long long INF = LONG_LONG_MAX, MOD = 1e9 + 7;
using namespace std;
string Num;
long long dp[18][2][4], len;
long long noNumbers(long long idx, long long tight, long long cntNonZero) {
  if (cntNonZero > 3) return 0;
  if (idx == len) {
    if (cntNonZero <= 3)
      return 1;
    else
      return 0;
  }
  if (dp[idx][tight][cntNonZero] != -1) {
    ;
    return dp[idx][tight][cntNonZero];
  }
  long long lim;
  if (tight == 1)
    lim = Num[idx] - '0';
  else
    lim = 9;
  long long ans = 0, newTight;
  ;
  for (long long digit = 0; digit <= lim; ++digit) {
    newTight = (tight == 1 && digit == lim);
    if (digit == 0)
      ans = (ans + noNumbers(idx + 1, newTight, cntNonZero)) % MOD;
    else
      ans = (ans + noNumbers(idx + 1, newTight, cntNonZero + 1)) % MOD;
    ;
  };
  return dp[idx][tight][cntNonZero] = ans % MOD;
};
void solve() {
  long long n, i, j, nl, nr;
  cin >> nl >> nr;
  --nl;
  string l = to_string(nl), r = to_string(nr);
  memset(dp, -1LL, sizeof(dp));
  ;
  Num = l;
  len = Num.length();
  ;
  long long ansl = 0;
  ansl = noNumbers(0, 1, 0);
  ;
  Num = r;
  len = Num.length();
  long long ansr = 0;
  memset(dp, -1LL, sizeof(dp));
  ;
  ansr = noNumbers(0, 1, 0);
  ;
  ;
  ansr = (ansr - ansl + MOD) % MOD;
  cout << ansr;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(11);
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
