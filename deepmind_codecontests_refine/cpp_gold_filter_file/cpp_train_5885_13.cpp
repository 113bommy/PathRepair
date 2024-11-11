#include <bits/stdc++.h>
using namespace std;
double a, b, c;
double rad(double x) { return x * M_PI / 180; }
int main() {
  cin >> a >> b >> c;
  double aa = (a / 2) / sin(rad(60));
  double ah = aa * cos(rad(60));
  double bb = (b / 2) / sin(rad(45));
  double bh = bb * cos(rad(45));
  double cc = (c / 2) / sin(rad(36));
  double ch = cc * cos(rad(36));
  cout.precision(16);
  cout << (a * a * sqrt(3.0) / 4 * sqrt(a * a - aa * aa) +
           b * b * sqrt(b * b - bb * bb) +
           (ch * c / 2) * 5 * sqrt(c * c - cc * cc)) /
              3.0;
}
