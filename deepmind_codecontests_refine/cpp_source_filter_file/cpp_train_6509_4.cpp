#include <bits/stdc++.h>
using namespace std;
long double dp[(int)2e5 + 5][55];
long double inv[(int)2e5 + 5];
long long sums[(int)2e5 + 5];
long double a[(int)2e5 + 5];
void dp1(int lo, int hi, int k_lo, int k_hi, int k) {
  if (lo > hi || k_lo > k_hi) return;
  int mid = (lo + hi) / 2;
  int i = k_lo;
  for (int x = k_lo; x <= min(mid, k_hi); x++) {
    long double ans = (x ? dp[x - 1][k - 1] : 0) + a[mid] - (x ? a[x - 1] : 0) -
                      (x ? sums[x - 1] : 0) * (inv[mid] - (x ? inv[x - 1] : 0));
    if (dp[mid][k] > ans) {
      dp[mid][k] = ans;
      i = x;
    }
  }
  dp1(lo, mid - 1, k_lo, i, k);
  dp1(mid + 1, hi, i, k_hi, k);
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int x = 0; x < n; x++) {
    cin >> v[x];
    sums[x] += v[x] + (x ? sums[x - 1] : 0);
    inv[x] += 1.0 / v[x] + (x ? inv[x - 1] : 0);
    a[x] += (sums[x] + .0) / v[x] + (x ? a[x - 1] : 0);
    dp[x][0] = a[x];
    for (int y = 1; y <= k; y++) dp[x][y] = 2e9;
  }
  for (int x = 1; x < k; x++) dp1(0, n, 0, n, x);
  cout << setprecision(20) << fixed << dp[n - 1][k - 1];
}
