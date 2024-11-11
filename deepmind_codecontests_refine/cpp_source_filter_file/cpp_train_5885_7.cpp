#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c;
  cin >> a >> b >> c;
  double s1, s2, s3, sum = 0;
  s1 = (a * a * a * sqrt(3) * sqrt(6)) / 36 * 1.0;
  s2 = (b * b * b * sqrt(2)) / 6 * 1.0;
  double x = sin(54.0 / 180.0 * 3.141592653579) /
             sin(72.0 / 180.0 * 3.141592653579) * c;
  s3 = 5.0 / 6.0 * c * x * sin(54.0 / 180.0 * 3.141592653579) *
       sqrt(c * c - x * x);
  sum = s1 + s2 + s3;
  printf("%.7lf\n", sum);
  return 0;
}
