#include <bits/stdc++.h>
using namespace std;
long long a, b, c, X1, Y1, X2, Y2;
double x[10], y[10];
double ans;
double Abs(double x) { return x > 0 ? x : -x; }
double dis(double X1, double Y1, double X2, double Y2) {
  return sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
}
int main() {
  ios::sync_with_stdio(false);
  int i, j;
  cin >> a >> b >> c >> X1 >> Y1 >> X2 >> Y2;
  ans = Abs(X1 - X2) + Abs(Y1 - Y2);
  if (a == 0 || b == 0) return printf("%.10lf", ans), 0;
  x[1] = (double)(-c - b * Y1) / a;
  y[1] = Y1;
  x[2] = X1;
  y[2] = (double)(-a * X1 - c) / b;
  x[3] = (double)(-c - b * Y2) / a;
  y[3] = Y2;
  x[4] = X2;
  y[4] = (double)(-a * X2 - c) / b;
  for (i = 1; i <= 2; i++)
    for (j = 3; j <= 4; j++)
      ans = min(ans, dis(X1, Y1, x[i], y[i]) + dis(x[i], y[i], x[j], y[j]) +
                         dis(x[j], y[j], X2, Y2));
  printf("%.10lf", ans);
  return 0;
}
