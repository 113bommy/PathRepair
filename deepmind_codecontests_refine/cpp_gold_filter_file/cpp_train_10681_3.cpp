#include <bits/stdc++.h>
using namespace std;
double H, F;
vector<double> x;
double func(double x1, double x2) {
  double x3 = x1 * (F + H) / (F - H);
  double x4 = x2 * (F + H) / (F - H);
  if (x3 < x2 && x1 < x4) return (x3 + x1) * H;
  if (x2 < x3 && x4 < x1) return (x2 + x4) * H;
  if (x1 + x2 > x3 + x4) {
    swap(x1, x4);
    swap(x2, x3);
  }
  double a = x4 - x1, b = x3 - x2, p = 0.0;
  if (a + b > 1.0E-9) p = a * b / (a + b) / (a + b);
  return (x1 + x2 + p * (a + b)) * H;
}
int main(void) {
  int N, i, j;
  double low, high;
  cin >> N >> H >> F;
  for ((i) = 0; (i) < (int)(N); (i)++) {
    cin >> low >> high;
    x.push_back(low);
    x.push_back(high);
  }
  sort(x.begin(), x.end());
  double ans = 0.0;
  for ((i) = 0; (i) < (int)(N); (i)++) {
    double d = x[2 * i + 1] - x[2 * i];
    double d2 = d * (F + H) / (F - H);
    ans += (d + d2) * 2.0 * H;
  }
  for ((i) = 0; (i) < (int)(N); (i)++)
    for ((j) = 0; (j) < (int)(N); (j)++) {
      ans -= func(x[2 * i + 1], x[2 * j + 1]);
      ans -= func(x[2 * i], x[2 * j]);
      ans += func(x[2 * i + 1], x[2 * j]);
      ans += func(x[2 * i], x[2 * j + 1]);
    }
  printf("%.9f\n", ans);
  return 0;
}
