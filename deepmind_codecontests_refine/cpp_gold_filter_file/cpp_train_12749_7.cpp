#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  double i, n, k;
  cin >> n >> k;
  vector<double> v;
  for (i = 0; i < n; i++) {
    double x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  double m = v[n - 1] - v[n - 2];
  for (i = n - 2; i > 0; i--) {
    if (m < (v[i] - v[i - 1])) m = v[i] - v[i - 1];
  }
  double s = max(v[0], m / 2);
  double ans = max((k - v[n - 1]), s);
  cout << fixed << setprecision(11) << ans;
  return 0;
}
