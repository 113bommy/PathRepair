#include <bits/stdc++.h>
using namespace std;
double get_dis(pair<double, double> a, pair<double, double> b) {
  return sqrt((a.first - b.first) * (a.first - b.first) +
              (a.second - b.second) * (a.second - b.second));
}
int main() {
  double a, b, c;
  cin >> a >> b >> c;
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  double ans_1 = x1, ans_2 = -(a * x1 + c) / (double)b, dist1 = abs(ans_2 - y1);
  double ans_3 = -(b * y1 + c) / (double)a, ans_4 = y1, dist2 = abs(ans_3 - x1);
  double ans_5 = x2, ans_6 = -(a * x2 + c) / (double)b, dist3 = abs(ans_6 - y2);
  double ans_7 = -(b * y2 + c) / (double)a, ans_8 = y2, dist4 = abs(ans_7 - x2);
  double res = 1e20;
  res = min(res, get_dis({ans_1, ans_2}, {ans_5, ans_6}) + dist1 + dist3);
  res = min(res, get_dis({ans_1, ans_2}, {ans_7, ans_8}) + dist1 + dist4);
  res = min(res, get_dis({ans_3, ans_4}, {ans_5, ans_6}) + dist2 + dist3);
  res = min(res, get_dis({ans_3, ans_4}, {ans_7, ans_8}) + dist2 + dist4);
  res = min(res, (double)abs(x1 - x2) + abs(y1 - y2));
  printf("%.8lf", res);
  return 0;
}
