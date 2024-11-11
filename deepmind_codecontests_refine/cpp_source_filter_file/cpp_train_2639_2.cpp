#include <bits/stdc++.h>
typedef struct {
  double x, y;
} t_coord;
double polygon_center_angle(int n) { return 2 * 3.14159265358979323846 / n; }
double center_angle(t_coord center, t_coord point) {
  return atan2(point.x - center.x, point.y - center.y);
}
t_coord move(const t_coord point, const t_coord vector) {
  t_coord res;
  res.x = point.x + vector.x;
  res.y = point.y + vector.y;
  return res;
}
t_coord calc_center(const t_coord p[3]) {
  t_coord res;
  double d = 2 * ((p[0].x * (p[1].y - p[2].y)) + (p[1].x * (p[2].y - p[0].y)) +
                  (p[2].x * (p[0].y - p[1].y)));
  res.x =
      ((((p[0].x) * (p[0].x)) + ((p[0].y) * (p[0].y))) * (p[1].y - p[2].y) +
       (((p[1].x) * (p[1].x)) + ((p[1].y) * (p[1].y))) * (p[2].y - p[0].y) +
       (((p[2].x) * (p[2].x)) + ((p[2].y) * (p[2].y))) * (p[0].y - p[1].y)) /
      d;
  res.y =
      ((((p[0].x) * (p[0].x)) + ((p[0].y) * (p[0].y))) * (p[2].x - p[1].x) +
       (((p[1].x) * (p[1].x)) + ((p[1].y) * (p[1].y))) * (p[0].x - p[2].x) +
       (((p[2].x) * (p[2].x)) + ((p[2].y) * (p[2].y))) * (p[1].x - p[0].x)) /
      d;
  return res;
}
double check(double angle, double divisor_angle) {
  double tmp = angle / divisor_angle;
  int factor = tmp + 0.5;
  double res = fabs(factor - tmp);
  return res;
}
int main() {
  t_coord p[3], center;
  double angle[3], angle_diff[2], poly_min_angle, diff;
  int min_poly;
  for (int i = 0; i < 3; ++i) scanf("%lf %lf", &p[i].x, &p[i].y);
  center = calc_center(p);
  for (int i = 0; i < 3; ++i) angle[i] = center_angle(center, p[i]);
  for (int i = 0; i < 2; ++i) {
    angle_diff[i] = angle[i] - angle[i + 1];
    if (angle_diff[i] < 0.) angle_diff[i] += 2 * 3.14159265358979323846;
  }
  for (int i = 3; i <= 100; ++i) {
    poly_min_angle = polygon_center_angle(i);
    for (int j = 0; j < 2; ++j) {
      diff = check(angle_diff[j], poly_min_angle);
      if (diff > 1e-8) break;
    }
    if (diff < 1e-8) {
      min_poly = i;
      break;
    }
  }
  double r = sqrt(((p[0].x - center.x) * (p[0].x - center.x)) +
                  ((p[0].y - center.y) * (p[0].y - center.y)));
  double area =
      min_poly * (cos(poly_min_angle / 2) * r) * (sin(poly_min_angle / 2) * r);
  printf("%f", area);
  return 0;
}
