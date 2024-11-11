#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long n;
vector<long long> r(N), h(N);
vector<double> bit(N);
vector<pair<double, long long>> arr(N);
void update(long long idx, double val) {
  while (idx > 0) {
    bit[idx] = max(bit[idx], val);
    idx -= idx & (-idx);
  }
}
double query(long long idx) {
  double res = 0;
  while (idx < N) {
    res = max(res, bit[idx]);
    idx += idx & (-idx);
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> r[i] >> h[i];
    arr[i].first = r[i] * r[i] * h[i];
    arr[i].second = i;
  }
  vector<double> dp(n + 1);
  double ans = 0;
  sort(arr.begin() + 1, arr.begin() + n + 1);
  for (long long i = n; i >= 1;) {
    long long j = i;
    do {
      long long idx = arr[j].second;
      dp[idx] = query(idx + 1) + arr[j].first;
      ans = max(ans, dp[idx]);
      j--;
    } while (j >= 1 && arr[j].first == arr[i].first);
    for (long long k = j + 1; k <= i; k++)
      update(arr[k].second, dp[arr[k].second]);
    i = j;
  }
  ans *= (3.141592653589793238);
  cout << fixed << setprecision(12) << ans << endl;
  return 0;
}
