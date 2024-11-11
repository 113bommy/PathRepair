#include <bits/stdc++.h>
using namespace std;
struct sample {
  int p;
  int ind;
};
bool operator<(sample s1, sample s2) {
  if (s1.p < s2.p)
    return true;
  else
    return false;
}
int main() {
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  double v, t;
  cin >> v >> t;
  double vx, vy, wx, wy;
  cin >> vx >> vy >> wx >> wy;
  double time = 100000000;
  double a = v * v - vy * vy - vx * vx;
  double c = y1 - y2;
  c = -1 * c * c;
  c = c - (x2 - x1) * (x2 - x1);
  double b = -2 * vy * (y1 - y2) - 2 * vx * (x1 - x2);
  double time1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
  double time2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
  if (time1 <= t && time1 > 0) time = time1;
  if (time2 <= t && time2 > 0) time = min(time, time2);
  if (time <= t)
    printf("%.9lf", time);
  else {
    time = 100000000;
    a = v * v - wy * wy - wx * wx;
    c = vy * t - wy * t + y1 - y2;
    c = -1 * c * c;
    c = c - (x2 - x1 - vx * t + wx * t) * (x2 - x1 - vx * t + wx * t);
    b = -2 * wy * (vy * t - wy * t + y1 - y2) -
        2 * wx * (vx * t - wx * t + x1 - x2);
    time1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    time2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    if (time1 >= t) time = time1;
    if (time2 >= t) time = min(time, time2);
    printf("%.9lf", time);
  }
  return 0;
}
