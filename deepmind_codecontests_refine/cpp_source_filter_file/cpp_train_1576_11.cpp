#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = 3.1415926535;
bool greaterThan(double a, double b) { return (a > b + EPS); }
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(NULL);
  int n, R;
  cin >> n >> R;
  double l = 0, r = 200;
  for (int i = 0; i < 60 && l + EPS < r; ++i) {
    double m = (l + r) / 2.0;
    double left = m / (double(m + R));
    double right = sin(PI / n);
    if (greaterThan(left, right))
      r = m;
    else
      l = m;
  }
  cout << fixed << setprecision(7) << (l + r) / 2.0 << '\n';
  return 0;
}
