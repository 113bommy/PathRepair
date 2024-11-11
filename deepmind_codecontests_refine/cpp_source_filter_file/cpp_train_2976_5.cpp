#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  cout << fixed;
  int n, p;
  cin >> n >> p;
  vector<int> a(n), b(n);
  int slope_sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    slope_sum += a[i];
  }
  if (slope_sum <= p) {
    cout << "-1\n";
    return 0;
  }
  double l = 0, r = 1e14;
  for (int iter = 0; iter < 128; ++iter) {
    double t = (l + r) / 2.0, power = p;
    bool possible = true;
    for (int i = 0; i < n; ++i) {
      power -= max(0.0, t * a[i] - b[i]) / t;
      if (power < 0.0) {
        possible = false;
        break;
      }
    }
    if (possible)
      l = t;
    else
      r = t;
  }
  cout << l << "\n";
  return 0;
}
