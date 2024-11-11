#include <bits/stdc++.h>
using namespace std;
int n, a[1111];
double lleft;
inline int can(double v) {
  double lft = v;
  for (int(i) = 0; (i) < (n); ++(i))
    if (lft >= 10. * (a[i] - a[i - 1]) && lft < 10. * (a[i] - a[i - 1] + 1))
      lft = lft + v - 10. * (a[i] - a[i - 1]);
    else if (lft < 10. * (a[i] - a[i - 1]))
      return -1;
    else
      return 1;
  lleft = lft;
  return 0;
}
int main() {
  cin >> n;
  for (int(i) = 0; (i) < (n); ++(i)) cin >> a[i];
  int cnt = 0;
  double high, low;
  high = 1e+9, low = 10;
  while (high - low > 1e-9 && ++cnt < 1000) {
    double mid = (high + low) / 2;
    if (can(mid) != -1)
      high = mid;
    else
      low = mid;
  }
  double rlow = high;
  high = 1e+9, low = 10;
  cnt = 0;
  while (high - low > 1e-9 && ++cnt < 1000) {
    double mid = (high + low) / 2;
    if (can(mid) != 1)
      low = mid;
    else
      high = mid;
  }
  double rhigh = low;
  can(rlow);
  double l1 = lleft;
  can(rhigh);
  double l2 = lleft;
  int ans1 = (int)((double)a[n - 1] + floor(l1 / 10.));
  int ans2 = (int)((double)a[n - 1] + floor(l2 / 10.));
  if (ans1 == ans2) {
    cout << "unique\n";
    cout << ans1 << endl;
  } else
    cout << "not unique\n";
}
