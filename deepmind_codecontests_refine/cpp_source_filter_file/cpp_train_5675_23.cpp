#include <bits/stdc++.h>
using namespace std;
const double EPS = (double)1e-6;
pair<double, double> S, D, v1, v2;
int V, t;
double ans;
double dist(const pair<double, double>& A, const pair<double, double>& B) {
  return sqrt((A.first - B.first) * (A.first - B.first) +
              (A.second - B.second) * (A.second - B.second));
}
double myabs(double x) { return x > 0 ? x : -x; }
bool ok(double T) {
  pair<double, double> tmp = S;
  tmp.first +=
      v1.first * min(T, (double)t) + v2.first * max(T - (double)t, (double)0);
  tmp.second +=
      v1.second * min(T, (double)t) + v2.second * max(T - (double)t, (double)0);
  if (dist(tmp, D) - T * V <= EPS) return 1;
  return 0;
}
void binsrc(double l, double r) {
  double mid;
  while (abs(l - r) > EPS) {
    mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      r = mid;
    } else {
      l = mid;
    }
  }
}
int main() {
  cin >> S.first >> S.second;
  cin >> D.first >> D.second;
  cin >> V >> t;
  cin >> v1.first >> v1.second;
  cin >> v2.first >> v2.second;
  binsrc(0, 10000000);
  printf("%.18lf\n", ans);
  return 0;
}
