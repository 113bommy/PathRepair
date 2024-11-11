#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60777216")
using namespace std;
double xa, ya, xb, yb;
int n;
double x[11111], y[11111], a[11111], w[11111];
int k;
const double pi = acos(-1.);
double go(double a, double w) {
  double v = 0;
  int num = 100;
  for (int i(0); i < (num + 1); ++i) {
    double x = xa + (xb - xa) * i / double(num);
    double y = ya + (yb - ya) * i / double(num);
    double q = atan2(y, x) - a;
    if (q > 2 * pi) q -= 2 * pi;
    while (q < 0) q += 2 * pi;
    if (q > 2 * pi - q) q = 2 * pi - q;
    double T = (w < 1e-5 ? (i == 0 ? 0 : 1e10) : q / w);
    v = max(v, hypot(x - xa, y - ya) / T);
  }
  return v;
}
int main() {
  cin >> xa >> ya >> xb >> yb >> n;
  for (int i(0); i < (n); ++i)
    scanf("%lf %lf %lf %lf", x + i, y + i, a + i, w + i);
  cin >> k;
  vector<double> v;
  for (int i(0); i < (n); ++i) {
    xa -= x[i], ya -= y[i], xb -= x[i], yb -= y[i];
    v.push_back(go(a[i], w[i]));
    xa += x[i], ya += y[i], xb += x[i], yb += y[i];
  }
  sort((v).begin(), (v).end());
  reverse(v.begin(), v.end());
  if (k >= v.size())
    puts("0.0000");
  else
    printf("%.4lf\n", v[k]);
  return 0;
}
