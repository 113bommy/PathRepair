#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  double m;
  cin >> n >> m;
  double a[n], b[n];
  int flag = 1;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  double s = 0, e = 1e9, mid, ans = -1;
  for (int j = 1; j <= 100; j++) {
    mid = s + (e - s) / 2.0;
    double fuel = mid;
    int flag = 1;
    for (int i = 0; i < n; i++) {
      double fuel_needed = (m + fuel) / a[i];
      fuel -= fuel_needed;
      if (fuel < 0) {
        flag = 0;
        break;
      }
      fuel_needed = (m + fuel) / b[(i + 1) % n];
      fuel -= fuel_needed;
      if (fuel < 0) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) {
      ans = mid;
      e = mid;
    } else {
      s = mid;
    }
  }
  if (ans == -1)
    cout << -1 << endl;
  else
    cout << fixed << setprecision(8) << ans << endl;
  return 0;
}
