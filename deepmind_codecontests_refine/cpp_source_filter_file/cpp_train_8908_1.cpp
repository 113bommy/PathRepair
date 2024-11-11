#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  double x, v;
  vector<double> myvec, myvec2;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x, myvec.push_back(x);
  for (int i = 1; i <= n; i++) cin >> v, myvec2.push_back(v);
  double lo = 0, hi = 1e9, mid;
  while (abs(hi - lo) > 1e-6) {
    mid = (lo + hi) / 2.0;
    double l = -2e18, r = 2e18;
    for (int i = 0; i <= n - 1; i++) {
      l = max(l, myvec[i] - myvec2[i] * mid);
      r = min(r, myvec[i] + myvec2[i] * mid);
    }
    if (l <= r)
      hi = mid;
    else
      lo = mid;
  }
  cout << setprecision(6) << fixed << hi << "\n";
}
