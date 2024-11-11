#include <bits/stdc++.h>
using namespace std;
int n, k, a[100009], s;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s += a[i];
  }
  cout << fixed << setprecision(10);
  double hi = 1009.0, lo = 0.0, mid, ans = 0.0;
  while (hi - lo > 1e-9) {
    mid = (hi + lo) / 2;
    double lost = s - n * mid, t = 0;
    for (int i = 1; i <= n; i++) t += max(0.0, a[i] - mid);
    if (t - 0.0 < 1e-9 || lost < 0 || lost * 100 / t < k) {
      hi = mid - 1e-9;
      ans = mid;
    } else
      lo = mid + 1e-9;
  }
  cout << ans;
  return 0;
}
