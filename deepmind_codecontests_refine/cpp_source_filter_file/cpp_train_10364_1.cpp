#include <bits/stdc++.h>
using namespace std;
double n, l, k, v1, v2;
inline double transp_time(double x) {
  static double mult = (v2 * (2 * ceil(n / k) - 1) + v1) / (v2 * v2 - v1 * v1);
  return x * mult;
}
inline double rem_time(double x) { return (l - x - v1 * transp_time(x)) / v1; }
int main() {
  cin >> n >> l >> v1 >> v2 >> k;
  double left = 0, right = l;
  while (right - left > 1e-7) {
    double m = (left + right) / 2;
    if (rem_time(m) > 0) {
      left = m;
    } else {
      right = m;
    }
  }
  cout << fixed << setprecision(7) << transp_time(left);
}
