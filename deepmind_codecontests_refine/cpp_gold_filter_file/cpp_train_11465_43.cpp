#include <bits/stdc++.h>
using namespace std;
double m = 0.000000001;
double bin_sear(double n, double s, double e, double prev) {
  if (s <= e) {
    double mid = (s + e) / 2;
    if (abs(mid - prev) <= m) return mid;
    prev = mid;
    double a = n - mid;
    if (a * mid == n) return mid;
    if (a * mid <= n) return bin_sear(n, s, mid, prev);
    return bin_sear(n, mid, e, prev);
  }
}
signed main() {
  long long t, i, j;
  cin >> t;
  double n;
  while (t--) {
    cin >> n;
    double ans = bin_sear(n, 0, n, -1);
    if (n <= 3 && n >= 1)
      cout << "N\n";
    else
      cout << "Y " << fixed << setprecision(10) << ans << " " << fixed
           << setprecision(10) << n - ans << "\n";
  }
  return 0;
}
