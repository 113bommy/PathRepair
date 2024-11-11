#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, a, d, t, v;
  double maxTime, dt;
  cin >> n >> a >> d;
  for (int i = 0; i < n; i++) {
    cin >> t >> v;
    double s = v * v / (2.0 * a);
    if (s > d)
      dt = sqrt(2.0 * d / a);
    else
      dt = 1.0 * v / a + (d - s) / v;
    dt += t;
    maxTime = dt > maxTime ? dt : maxTime;
    printf("%.10lf\n", maxTime);
  }
  return 0;
}
