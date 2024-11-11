#include <bits/stdc++.h>
using namespace std;
int nBuses;
double acc, dist;
double getTime(double dis, double v0, double a) {
  double t0 = sqrt(2 * dis / a), t;
  if (((a * t0) > (v0) + 1e-13)) {
    return (v0 / a) + (dis - v0 * v0 / (2 * a)) / v0;
  } else
    return t0;
}
int main() {
  scanf("%d%lf%lf", &nBuses, &acc, &dist);
  double t[100005], v[100005], lt = 0.0, lv = 1e12;
  for (int i = 0; i < nBuses; i++) {
    scanf("%lf%lf", t + i, v + i);
    double ret = 0.0;
    double curTime = getTime(dist, v[i], acc);
    if (((curTime + t[i]) > (lt)-1e-13)) {
      ret = curTime + t[i];
      lt = curTime;
      lv = v[i];
    } else {
      ret = lt;
    }
    printf("%.10lf\n", ret);
  }
  return 0;
}
