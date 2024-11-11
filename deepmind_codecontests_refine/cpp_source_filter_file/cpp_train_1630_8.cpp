#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(15);
  double k, d, t;
  double ans = 0;
  cin >> k >> d >> t;
  if (d == k) {
    ans = t;
    cout << ans;
    return 0;
  }
  if (d > k) {
    double p = k + 0.5 * (d - k);
    double tmp = trunc(t / p);
    ans += tmp * d;
    t -= tmp * p;
    if (t <= k) {
      ans += t;
    } else {
      ans += k;
      ans += (t - k) * 2;
    }
    cout << ans;
    return 0;
  }
  if (d < k) {
    double p = trunc(k / d);
    p *= d;
    if (p < k) p += d;
    double tmp1 = k + 0.5 * (p - k);
    double x = trunc(t / tmp1);
    ans += x * p;
    t -= x * tmp1;
    if (t <= k) {
      ans += t;
    } else {
      ans += k;
      ans += (t - k) * 0.5;
    }
    cout << ans;
    return 0;
  }
  return 0;
}
