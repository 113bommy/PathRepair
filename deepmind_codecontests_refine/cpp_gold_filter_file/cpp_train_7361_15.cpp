#include <bits/stdc++.h>
using namespace std;
long long a, b, l;
const double pi = acos(-1);
const double delta = 0.000001;
double d(double theta) {
  return (a + b * tan(theta) - l * sin(theta)) * cos(theta);
}
double solve() {
  double theta = delta;
  double D = 1e18;
  while (theta < pi / 2) {
    D = min(D, d(theta));
    theta += delta;
  }
  return D;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  cin >> a >> b >> l;
  double ans;
  if (l <= b)
    ans = min(l, a);
  else if (l <= a)
    ans = min(l, b);
  else {
    ans = solve();
    if (ans < 0) return cout << "My poor head =(", 0;
  }
  cout << ans;
}
