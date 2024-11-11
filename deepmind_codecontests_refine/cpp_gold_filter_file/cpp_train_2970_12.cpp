#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535897932;
double N, R;
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> N >> R;
  double x = (180 - 360 / N) / 2;
  double h = R * sin(x * pi / 180);
  double s = 2 * R * cos(x * pi / 180);
  double a = 0.5 * s * h;
  double y = x - 90 / N;
  double h2 = s * tan(y * pi / 180) / 2;
  double a2 = 0.5 * s * h2;
  double ans = N * (a - a2);
  cout << setprecision(17) << ans << "\n";
}
