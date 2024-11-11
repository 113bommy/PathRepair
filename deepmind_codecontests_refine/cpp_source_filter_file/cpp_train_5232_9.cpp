#include <bits/stdc++.h>
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long INF = 1e9 + 228;
const long long INFLL = 1e18;
const long long MOD = 1e9 + 7;
const long double eps = 1e-4;
const long double eps2 = 1e-9;
const long long MOD2 = 998244353;
const long long dosz = 5e5;
const long long SZ = (1 << 18);
const long double PI = atan2l(0, -1);
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> nums(n);
  for (long long &i : nums) cin >> i;
  vector<long long> kek = nums;
  sort(kek.begin(), kek.end());
  long long cnt = 0;
  map<long long, long long> lol;
  for (long long i : kek) {
    lol[i] = cnt++;
  }
  for (long long &i : nums) i = lol[i];
  vector<long long> dp(n, 0);
  dp[0] = 1;
  for (long long i = 1; i < n; i++) {
    for (long long j = 0; j < i; j++) {
      if (nums[i] - nums[j] == 1) {
        dp[i] = max(dp[j] + 1, dp[i]);
      }
    }
  }
  sort(dp.begin(), dp.end());
  cout << n - dp.back() << endl;
}
signed main() {
  fast_io();
  srand(time(NULL));
  cout << fixed << setprecision(12);
  long long q = 1;
  cin >> q;
  while (q--) solve();
}
