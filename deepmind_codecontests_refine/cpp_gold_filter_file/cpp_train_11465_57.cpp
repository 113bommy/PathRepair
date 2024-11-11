#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0.0);
double inff = 1.0 / 0.0;
long long int x, y, n, i, z, j, k, w, u, q, c, t, m;
double func(double d, double a) { return (a * a - a * d + d); }
void solve() {
  double d;
  cin >> d;
  cout << setprecision(9) << fixed;
  if (d > 0 and d < 4) {
    cout << "N"
         << "\n";
    return;
  }
  cout << "Y ";
  double lo = 0, hi = d, mid;
  while (hi > lo + (1e-14) * lo) {
    mid = (hi + lo) / 2;
    if ((func(d, mid) > 0 and mid < d / 2) or
        (func(d, mid) < 0 and mid >= d / 2))
      lo = mid + (1e-14);
    else
      hi = mid;
  }
  cout << lo << " " << (d - lo) << "\n";
}
int main(void) {
  ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
  ;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
