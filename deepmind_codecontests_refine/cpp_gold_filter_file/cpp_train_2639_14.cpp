#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-2;
struct Point {
  double x, y;
} point[3];
double dist(struct Point a, struct Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double area(double a, double b, double c) {
  double p = (a + b + c) / 2;
  return sqrt(p * (p - a) * (p - b) * (p - c));
}
double fgcd(double a, double b) {
  if (b < eps)
    return a;
  else
    return fgcd(b, fmod(a, b));
}
int main() {
  for (int i = 0; i < 3; i++) scanf("%lf%lf", &point[i].x, &point[i].y);
  double len[3];
  for (int i = 0; i < 3; i++) len[i] = dist(point[i], point[(i + 1) % 3]);
  double s = area(len[0], len[1], len[2]),
         r = (len[0] * len[1] * len[2]) / (4 * s);
  sort(len, len + 3);
  double ang[3] = {0};
  for (int i = 0; i < 2; i++) {
    ang[i] = 2 * asin(len[i] / (2 * r));
  }
  ang[2] = 2 * PI - ang[0] - ang[1];
  double tp = fgcd(ang[0], fgcd(ang[1], ang[2]));
  double sx = (r * r * sin(tp)) / 2;
  double ans = sx * (2 * PI / tp);
  printf("%.6lf", ans);
  return 0;
}
