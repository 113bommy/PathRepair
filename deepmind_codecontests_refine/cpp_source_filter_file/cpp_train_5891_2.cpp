#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const double pi = acos(-1.0);
const double eps = 1e-9;
int n;
double x[200100], y[200100], res;
double get(int i, int j, int k) {
  double A = y[i] - y[j];
  double B = x[j] - x[i];
  double C = x[i] * y[j] - x[j] * y[i];
  double d = abs(A * x[k] + B * y[k] + C);
  d /= sqrt(A * A + B * B);
  return d;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  x[n + 1] = x[1];
  y[n + 1] = y[1];
  x[n + 2] = x[2];
  y[n + 2] = y[2];
  res = 1e18;
  for (int i = 1; i < n; i++) {
    res = min(res, get(i, i + 2, i + 1));
  }
  printf("%.7f", res / 2.0);
  return 0;
}
