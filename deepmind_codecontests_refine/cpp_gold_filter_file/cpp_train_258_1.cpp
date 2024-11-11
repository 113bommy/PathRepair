#include <bits/stdc++.h>
using namespace std;
int n, m;
double px, py;
vector<pair<double, double> > points;
double get_radius(int i) {
  return (px - points[i].first) * (px - points[i].first) +
         (py - points[i].second) * (py - points[i].second);
}
double get_dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main() {
  scanf("%d %lf %lf", &n, &px, &py);
  points.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", &points[i].first, &points[i].second);
  }
  double max_area = -100000000000000000;
  double min_area = 100000000000000000;
  for (int i = 0; i < n; i++) {
    double radius = get_radius(i);
    double area = 3.14159265358979323846 * radius;
    max_area = max(max_area, area);
    int j = (i + 1) % n;
    double m1 = (points[j].second - points[i].second) /
                (points[j].first - points[i].first);
    double c1 = points[i].second - m1 * points[i].first;
    double m2 = -1.0 / m1;
    double c2 = py - px * m2;
    double xp, yp;
    if (points[i].first == points[j].first) {
      xp = points[i].first;
      yp = py;
    } else if (points[i].second == points[j].second) {
      xp = px;
      yp = points[i].second;
    } else {
      xp = (c2 - c1) / (m1 - m2), yp = m2 * xp + c2;
    }
    if (get_dist(points[i].first, points[i].second, xp, yp) +
            get_dist(points[j].first, points[j].second, xp, yp) -
            get_dist(points[i].first, points[i].second, points[j].first,
                     points[j].second) <=
        1e-9) {
      double rad = (px - xp) * (px - xp) + (py - yp) * (py - yp);
      min_area = min(min_area, 3.14159265358979323846 * rad);
    } else {
      double r1 = get_radius(i), r2 = get_radius(j);
      min_area = min(min_area, 3.14159265358979323846 * min(r1, r2));
    }
  }
  printf("%.20lf\n", max_area - min_area);
  return 0;
}
