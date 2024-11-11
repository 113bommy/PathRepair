#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lb = 100000000;
void vrikodara(long long n = 12) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(n) << fixed;
}
long long n;
vector<long long> v(105);
long long dp[105][105][105][2];
long long solve_dp(long long i, long long o, long long e, long long p) {
  lb--;
  if (lb < 0) {
    cout << "exit";
    exit(0);
  };
  if (o < 0 || e < 0) return INT_MAX;
  if (i > n) return 0;
  if (dp[i][o][e][p % 2] != -1) return dp[i][o][e][p % 2];
  if (v[i] != 0) {
    long long res = solve_dp(i + 1, o, e, v[i]) + (v[i] % 2 != p % 2);
    return dp[i][o][e][p % 2] = res;
  }
  long long res = INT_MAX;
  if (o > 0) {
    res = min(res, solve_dp(i + 1, o - 1, e, 1) + (p % 2 == 0));
  }
  if (e > 0) {
    res = min(res, solve_dp(i + 1, o, e - 1, 0) + (p % 2 == 1));
  }
  return dp[i][o][e][p % 2] = res;
}
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> v[i];
  long long o = (n + 1) / 2, e = n / 2;
  for (long long i = 1; i <= n; i++) {
    if (!v[i]) continue;
    if (v[i] & 1)
      o--;
    else
      e--;
  }
  memset(dp, -1, sizeof(dp));
  long long ans = min(solve_dp(1, o, e, 1), solve_dp(1, o, e, 0));
  cout << ans;
}
int32_t main() {
  vrikodara();
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
