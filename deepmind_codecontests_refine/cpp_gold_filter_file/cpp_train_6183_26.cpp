#include <bits/stdc++.h>
using namespace std;
int main() {
  double l, d, v, g, r;
  cin >> l >> d >> v >> g >> r;
  double t = 0;
  t += d / v;
  double s = 0;
  while (s < t) {
    s += (g + r);
  }
  if ((t - s + g + r) >= g) t += (s - t);
  t += (l - d) / v;
  cout << fixed << setprecision(8) << t;
  return 0;
}
