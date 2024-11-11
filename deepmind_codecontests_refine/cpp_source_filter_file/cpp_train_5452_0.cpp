#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  double mx = 0, mn = 5.00;
  double pi = 3.14159265358979323846;
  vector<double> v;
  while (n--) {
    int x, y;
    cin >> x >> y;
    double t = atan2(y, x);
    v.push_back(t);
  }
  sort(v.begin(), v.end());
  for (int i = 1; i < v.size(); i++) {
    double t = v[i] - v[i - 1];
    mn = min(mn, 2 * pi - t);
  }
  mn = min(mn, v.back() - v[0]);
  double ans = (mn)*180.0 / pi;
  printf("%.9lf\n", ans);
  return 0;
}
