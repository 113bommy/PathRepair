#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000000")
using namespace std;
int n;
double a[500001], b[500001], p, q;
string st;
double calc(double y1) {
  double y2 = 1.;
  for (int i = 0; i < n; i++) {
    y2 = min(y2, (1. - (a[i] * y1)) / b[i]);
  }
  double ret = p * y1 + q * y2;
  return ret;
}
int main() {
  cin >> n >> p >> q;
  double maxi = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    maxi = max(b[i], maxi);
  }
  double l = 0, r = 1. / maxi;
  for (int i = 0; i < 100; i++) {
    double m1 = (fabs(l - r)) / 3;
    double x1 = calc(l + m1), x2 = calc(r - m1);
    if (x1 >= x2)
      r = r - m1;
    else
      l = l + m1;
  }
  printf("%.10lf\n", calc(l));
  return 0;
}
