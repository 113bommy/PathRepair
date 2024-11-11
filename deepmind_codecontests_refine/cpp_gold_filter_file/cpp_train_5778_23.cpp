#include <bits/stdc++.h>
using namespace std;
const double pi(3.14159265358979);
const double r(1.73205080756);
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
int a[123456], dp[123456];
map<double, int> m;
double are(double a, double b, double c) {
  double ar1 = (r * a * b) / 4.0;
  double s = sqrt(pow(a, 2) + pow(b, 2) + a * b);
  double x = (r * a) / (2 * s);
  double ax = sqrt(1 - x * x);
  double ar2 = 0.5 * c * s * (0.5 * r * ax + 0.5 * x);
  return ar1 + ar2;
}
int main() {
  int i, j, n;
  double a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  double ar = 0;
  ar += are(a, b, c);
  ar += are(d, e, f);
  double ans = (4.0 * (ar)) / r;
  cout << int(ans + 0.05);
  return 0;
}
