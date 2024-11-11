#include <bits/stdc++.h>
using namespace std;
double area(double a, double b, double c) {
  double p = (a + b + c) / 2;
  return sqrt(p * (p - a) * (p - b) * (p - c));
}
double third(double a, double b) {
  return sqrt((a * a) + (b * b) - (2 * a * b * cos(120 * acos(-1.0) / 180)));
}
int main() {
  double a, b, c, d, e, f, ans = 0;
  cin >> a >> b >> c >> d >> e >> f;
  double t1 = third(a, b);
  double t2 = third(c, d);
  double t3 = third(e, f);
  ans += area(a, b, t1) + area(c, d, t2) + area(e, f, t3) + area(t1, t2, t3);
  int x = round(ans / (area(1, 1, 1)));
  cout << x << endl;
  return 0;
}
