#include <bits/stdc++.h>
using namespace std;
void solve() {
  int d;
  cin >> d;
  if (d == 0) {
    cout << 'Y' << ' ' << 0.0 << ' ' << 0.0 << endl;
    return;
  }
  if (d < 4) {
    cout << 'N' << endl;
    return;
  }
  double bound = 0.0000001;
  double l = 2.0;
  double r = d - 1;
  while (r - l > bound) {
    double mid = (r + l) / 2;
    if (mid * (d - mid) > d) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << 'Y' << ' ' << l << ' ' << d - l << endl;
}
int main() {
  cout << setprecision(15) << fixed;
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
