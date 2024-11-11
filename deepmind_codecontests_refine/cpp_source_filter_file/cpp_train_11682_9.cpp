#include <bits/stdc++.h>
using namespace std;
long long n, k, l, a[1000005], L, R, MID, ans;
string s;
pair<long long, long long> fun(long long x) {
  vector<pair<long long, long long> > dp(n + 4);
  for (__typeof((n + 4)) i = (0); i < (n + 4); i++) dp[i] = {1000005, 1000005};
  dp[0] = {0, 0};
  for (__typeof((n)) i = (0); i < (n); i++) {
    long long j = min(n, i + l);
    dp[j] = min(dp[j], {dp[i].first + x, dp[i].second + 1});
    dp[i + 1] = min(dp[i + 1], {dp[i].first + (a[i] == 0), dp[i].second});
  }
  return dp[n];
}
void solve() {
  cin >> n >> k >> l >> s;
  for (__typeof((n)) i = (0); i < (n); i++) {
    if (s[i] >= 'A' && s[i] <= 'Z')
      a[i] = 1;
    else
      a[i] = 0;
  }
  if (k * l >= n) {
    cout << 0 << "\n";
    return;
  };
  L = 0, R = n;
  while (R - L > 1) {
    MID = (L + R) / 2;
    pair<long long, long long> p = fun(MID);
    if (fun(MID).second <= k)
      R = MID;
    else
      L = MID;
  }
  ans = fun(R).first - R * k;
  for (__typeof((n)) i = (0); i < (n); i++) a[i] ^= 1;
  L = -1, R = n;
  while (R - L > 1) {
    MID = (L + R) / 2;
    pair<long long, long long> p = fun(MID);
    if (fun(MID).second <= k)
      R = MID;
    else
      L = MID;
  }
  ans = min(ans, fun(R).first - R * k);
  {
    cout << ans << "\n";
    return;
  };
}
void prep() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  prep();
  cout << fixed << setprecision(12);
  while (t--) solve();
  return 0;
}
