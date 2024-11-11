#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  double a, b, c, d, i, s = 0, t = 0;
  cin >> a >> b >> c >> d;
  double s1 = a / b;
  double s2 = (b - a) / b;
  double z1 = c / d;
  double z2 = (d - c) / d;
  for (i = 0;; i++) {
    s += pow(s2 * z2, i) * s1;
    if (i > 0) t += pow(s2 * z2, i - 1) * s1;
    if ((abs(s - t)) <= 0.000000006) break;
  }
  cout << fixed << setprecision(9) << s;
  return 0;
}
