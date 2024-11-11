#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long x[2], y[2];
  for (int i = 0; i < 2; i++) {
    cin >> x[i] >> y[i];
  }
  double ans = 1e10;
  ans = abs(x[0] - x[1]) + abs(y[0] - y[1]);
  double nx[2], ny[2];
  for (int i = 0; i < 2; i++) {
    double tmp = 0;
    if (a == 0 || b == 0) break;
    if (i) {
      nx[0] = -1.0 * (b * y[0] + c) / a;
      ny[0] = y[0];
    } else {
      nx[0] = x[0];
      ny[0] = -1.0 * (a * x[0] + c) / b;
    }
    for (int j = 0; j < 2; j++) {
      tmp = 0;
      if (j) {
        nx[1] = x[1];
        ny[1] = -1.0 * (a * x[1] + c) / b;
      } else {
        nx[1] = -1.0 * (b * y[1] + c) / a;
        ny[1] = y[1];
      }
      for (int k = 0; k < 2; k++) {
        tmp += abs(ny[k] - y[k]) + abs(nx[k] - x[k]);
      }
      tmp += sqrt((ny[0] - ny[1]) * (ny[0] - ny[1]) +
                  (nx[0] - nx[1]) * (nx[0] - nx[1]));
      ans = min(ans, tmp);
    }
  }
  printf("%.9f", ans);
}
