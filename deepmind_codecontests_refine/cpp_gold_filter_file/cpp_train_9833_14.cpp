#include <bits/stdc++.h>
using namespace std;
double ncr(double n, double r) {
  double ret = 1;
  for (double i = 0; i < r; i++) {
    ret *= n - i;
    ret /= (i + 1);
  }
  return ret;
}
int main() {
  double n, m;
  while (cin >> n >> m) {
    double ans = 0;
    for (double i = 1; i <= min(n, m); i++) {
      ans += (i / n) * (ncr(m - 1, i - 1) * ncr(n * m - m, n - i) /
                        ncr(n * m - 1, n - 1));
    }
    cout << fixed << setprecision(10) << ans << endl;
  }
}
