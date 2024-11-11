#include <bits/stdc++.h>
using namespace std;
double getLength(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double getR(double a, double b, double c) {
  double p = (a + b + c) / 2.0;
  return (a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c)));
}
double getAngle(double a, double b, double c) {
  return acos((b * b + c * c - a * a) / (2 * b * c)) * 2;
}
double gcd(double a, double b) {
  if (a < b) return gcd(b, a);
  if (fabs(b) < 0.001) {
    return a;
  } else {
    return gcd(b, a - floor(a / b) * b);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  double x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  double a = getLength(x2, y2, x3, y3);
  double b = getLength(x3, y3, x1, y1);
  double c = getLength(x1, y1, x2, y2);
  double A = getAngle(a, b, c);
  double B = getAngle(b, c, a);
  double C = getAngle(c, a, b);
  double g = gcd(gcd(A, B), C);
  double R = getR(a, b, c);
  double res = R * R * cos(g / 2.0) * sin(g / 2.0) * (2.0 * 3.141592659 / g);
  printf("%.6f\n", res);
  return 0;
}
