#include <bits/stdc++.h>
using namespace std;
bool is(double mid, long long a[], long long b[], long long n, long long p) {
  double ans = 0;
  for (long long i = 0; i < n; i++) {
    double reff = b[i] - a[i] * mid;
    reff = min(reff, 0.0);
    ans += reff;
  }
  double have = mid * p;
  if (have + ans < 0) return false;
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, p;
  cin >> n >> p;
  long long arr[n];
  long long f = 0;
  long long b[n];
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    cin >> b[i];
    f += arr[i];
  }
  if (p >= f) {
    cout << -1 << "\n";
    return 0;
  }
  double l = 0, r = pow(10, 19) / p;
  double ans = 0;
  while (l <= r) {
    double mid = (l + r) / 2;
    if (is(mid, arr, b, n, p)) {
      l = mid + .000001;
      ans = max(ans, mid);
    } else {
      r = mid - 0.000001;
    }
  }
  cout << fixed << setprecision(10) << ans << "\n";
  return 0;
}
