#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
const double pi = acos(-1.0);
const double eps = 1e-9;
int n;
double a, d;
double t, v, last = -1.0;
double calc(double t, double v) {
  double second = v * v / 2.0 / a;
  if (second > d)
    return t + sqrt(2.0 * d / a);
  else
    return (d - second) / v + v / a + t;
}
int main() {
  cin >> n >> a >> d;
  for (int i = 0; i < n; i++) {
    scanf("%f%f", &t, &v);
    last = max(last, calc(t, v));
    printf("%.9lf\n", last);
  }
  return 0;
}
