#include <bits/stdc++.h>
using namespace std;
double dist(long long x, long long y) { return sqrt((double)(x * x + y * y)); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long x0, y0, v, T;
  cin >> x0 >> y0 >> v >> T;
  double r0 = (double)(v * T);
  double PI = asin(1) * (2.0);
  int n;
  cin >> n;
  long long x, y, r;
  vector<pair<double, double> > ranges;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y >> r;
    x -= x0;
    y -= y0;
    double d1 = dist(x, y);
    if (d1 < r + 1e-8) {
      printf("1.0000000\n");
      return 0;
    }
    if (d1 - r > r0) {
      continue;
    }
    double angm = atan2(y, x);
    if (angm < 0) {
      angm += 2.0 * PI;
    }
    double ang;
    if (r0 * r0 > d1 * d1 - r * r) {
      ang = asin(r / d1);
    } else {
      ang = acos((r0 * r0 + d1 * d1 - r * r) / (2.0 * r0 * d1));
    }
    double angL = angm + ang;
    double angR = angm - ang;
    if (angL > 2.0 * PI) {
      ranges.push_back(make_pair(0, angL - 2.0 * PI));
      ranges.push_back(make_pair(angR, 2.0 * PI));
    } else if (angR < 0) {
      ranges.push_back(make_pair(0, angL));
      ranges.push_back(make_pair(angR + 2.0 * PI, 2 * PI));
    } else {
      ranges.push_back(make_pair(angR, angL));
    }
  }
  sort(ranges.begin(), ranges.end());
  double totalRange = 0.0;
  double cF = 0.0, cS = 0.0;
  for (int i = 0; i < ranges.size(); i++) {
    if (ranges[i].first > cS) {
      totalRange += ranges[i].second - ranges[i].first;
      cF = ranges[i].first;
      cS = ranges[i].second;
    } else {
      if (ranges[i].second > cS) {
        totalRange += ranges[i].second - cS;
        cS = ranges[i].second;
      }
    }
  }
  double prob = totalRange / (2.0 * PI);
  printf("%.9f\n", prob);
  return 0;
}
