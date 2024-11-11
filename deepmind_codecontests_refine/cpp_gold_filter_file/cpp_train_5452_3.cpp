#include <bits/stdc++.h>
using namespace std;
int const N = 2e5 + 1;
long double const PI = acosl(-1);
int main() {
  int n;
  scanf("%d", &n);
  vector<long double> v;
  for (int i = 0; i < n; ++i) {
    long double x, y, angle;
    cin >> x >> y;
    angle = atan2l(y, x) * (180 / acosl(-1));
    v.push_back(angle);
  }
  sort(v.begin(), v.end());
  long double mx = 360.0;
  for (int i = 1; i < n; ++i) {
    mx = min(mx, 360 - (v[i] - v[i - 1]));
  }
  mx = min(mx, v[n - 1] - v[0]);
  cout << fixed << setprecision(12) << mx << "\n";
}
