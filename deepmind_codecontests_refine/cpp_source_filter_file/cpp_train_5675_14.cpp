#include <bits/stdc++.h>
using namespace std;
double getDist(double x1, double y1, double x2, double y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
int main() {
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  double maxV, t;
  cin >> maxV >> t;
  double v1, v2, w1, w2;
  cin >> v1 >> v2 >> w1 >> w2;
  double lo = 0;
  double hi = 1e6;
  double result;
  for (int cycle = 0; cycle < 400; cycle++) {
    double time = lo + (hi - lo) / 2;
    double sX = x1 + v1 * min(t, time) + w1 * max(0.0, time - t);
    double sY = y1 + v2 * min(t, time) + w2 * max(0.0, time - t);
    double D = getDist(sX, sY, x2, y2);
    double needTime = D / maxV;
    if (needTime <= time) {
      result = needTime;
      hi = time;
    } else
      lo = time;
  }
  printf("%.10lf\n", result);
}
