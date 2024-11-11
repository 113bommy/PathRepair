#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC("unroll-loops")
const long long mod = 1e9 + 7;
const int64_t INF = 2e18;
const long long MAX = 1e9 + 100;
const long long N = 2e5 + 5;
const long long ep = 1e-9;
void io() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
void solve() {
  long long m;
  cin >> m;
  long long arr[2][m];
  long long sum_a = 0, sum_b = 0, t_sum = 0;
  vector<long long> coins;
  for (long long i = 0; i < m; i++) {
    cin >> arr[0][i];
    sum_a += arr[0][i];
  }
  for (long long i = 0; i < m; i++) {
    cin >> arr[1][i];
    sum_b += arr[1][i];
  }
  t_sum = sum_a + sum_b;
  long long prefix_a[m + 1];
  long long prefix_b[m + 1];
  prefix_a[0] = 0;
  prefix_b[0] = 0;
  for (long long i = 1; i <= m; i++) {
    prefix_a[i] = prefix_a[i - 1] + arr[0][i - 1];
  }
  for (long long i = 1; i <= m; i++) {
    prefix_b[i] = prefix_b[i - 1] + arr[1][i - 1];
  }
  long long ans = INT_MAX;
  for (long long i = 0; i < m; i++) {
    ans = min(ans, max(prefix_a[m] - prefix_a[i + 1], prefix_b[i]));
  }
  cout << ans;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
