#include <bits/stdc++.h>
const long long P = 1000000007;
using namespace std;
double x[400][2];
double y[400][2];
double xsum[400];
double ysum[400];
double masa[400];
double vol(int k) {
  return abs((y[k][1] - y[k][0]) * (y[k][1] - y[k][0]) * (y[k][1] - y[k][0]));
}
inline bool miedzy(double a, double b, double c) {
  if (a <= b && b <= c) return true;
  if (c <= b && b <= a) return true;
  return false;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%lf %lf %lf %lf", &x[i + 1][0], &y[i + 1][0], &x[i + 1][1],
          &y[i + 1][1]);
  x[0][0] = -1000;
  x[0][1] = 1000;
  y[0][0] = -1000;
  y[0][1] = 1000;
  xsum[0] = 0;
  ysum[0] = 0;
  masa[0] = 0;
  for (int i = 1; i <= n; i++) {
    xsum[i] = xsum[i - 1] + ((x[i][0] + x[i][1]) / 2) * vol(i);
    ysum[i] = ysum[i - 1] + ((y[i][0] + y[i][1]) / 2) * vol(i);
    masa[i] = masa[i - 1] + vol(i);
  }
  int k = 1;
  while (k <= n) {
    for (int i = 1; i <= k; i++) {
      double srx = (xsum[k] - xsum[i - 1]) / (masa[k] - masa[i - 1]);
      double sry = (ysum[k] - ysum[i - 1]) / (masa[k] - masa[i - 1]);
      if (!miedzy(x[i][0], srx, x[i][1]) || !miedzy(y[i][0], sry, y[i][1]) ||
          !miedzy(x[i - 1][0], srx, x[i - 1][1]) ||
          !miedzy(y[i - 1][0], sry, y[i - 1][1])) {
        printf("%d\n", k - 1);
        return 0;
      }
    }
    k++;
  }
  printf("%d\n", n);
  return 0;
}
