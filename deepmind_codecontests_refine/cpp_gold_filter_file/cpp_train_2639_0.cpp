#include <bits/stdc++.h>
using namespace std;
double dist(double a_x, double a_y, double b_x, double b_y) {
  return sqrt((a_x - b_x) * (a_x - b_x) + (a_y - b_y) * (a_y - b_y));
}
double fgcd(double a, double b) { return a < 0.01 ? b : fgcd(fmod(b, a), a); }
int main() {
  double x1, y1;
  double x2, y2;
  double x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  double a = dist(x1, y1, x2, y2);
  double b = dist(x3, y3, x2, y2);
  double c = dist(x1, y1, x3, y3);
  double p = (a + b + c) / 2;
  double s = sqrt(p * (p - a) * (p - b) * (p - c));
  double r = (a * b * c) / (4 * s);
  double deg1 = 2 * asin(a / (2 * r));
  double deg2 = 2 * asin(b / (2 * r));
  double deg3 = 2 * acos(-1) - deg1 - deg2;
  double deg = fgcd(deg1, fgcd(deg2, deg3));
  double ss = acos(-1) * r * r * sin(deg) / deg;
  printf("%.9lf\n", ss);
  return 0;
}
