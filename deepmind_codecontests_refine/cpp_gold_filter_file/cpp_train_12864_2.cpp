#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long dp[N];
long long ans[N];
vector<long long int> a(N, 0);
int solve() {
  long long n;
  cin >> n;
  for (long long int i = 1; i < n + 1; i++) cin >> a[i];
  ans[0] = dp[0] = 0;
  for (long long int i = 1; i < n + 1; i++) {
    long long tc = (long long)1e18;
    if (i - 1 >= 0) tc = min(dp[i - 1] + 20, tc);
    long long idx1 =
        (lower_bound(a.begin() + 1, a.begin() + i + 1, (a[i] - 90 + 1)) -
         a.begin());
    idx1--;
    if (idx1 >= 0) tc = min(dp[idx1] + 50, tc);
    long long idx2 =
        (lower_bound(a.begin() + 1, a.begin() + i + 1, (a[i] - 1440 + 1)) -
         a.begin());
    idx2--;
    if (idx2 >= 0) tc = min(tc, dp[idx2] + 120);
    ans[i] = tc - dp[i - 1];
    dp[i] = tc;
  }
  for (long long int i = 1; i < n + 1; i++) cout << ans[i] << "\n";
  return 0;
}
int main() {
  auto start = chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long test_cases = 1;
  while (test_cases--) solve();
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
}
