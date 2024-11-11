#include <bits/stdc++.h>
using namespace std;
double cal(double a, double n) {
  double R, alpha, h;
  alpha = acos(-1.0) / n;
  R = a / (sin(alpha) * 2);
  h = sqrt(a * a - R * R);
  return h * n * a * a / (12 * tan(alpha));
}
int main() {
  double l[3];
  cin >> l[0] >> l[1] >> l[2];
  double sum = 0;
  for (int i = 0; i < 3; i++) sum += cal(l[i], i);
  printf("%.9f\n", sum);
  return 0;
}
