#include <bits/stdc++.h>
using namespace std;
int t;
double l1, l2, l;
double r1, r2, r, rr;
double x1, x2;
double x, y;
int k;
int main() {
  cout.setf(ios::fixed);
  cout.precision(7);
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> r1 >> r2 >> k;
    r = 2 * r2;
    x1 = r * r / r1 / 2;
    x2 = 2 * r2;
    x = (x1 + x2) / 2;
    rr = (x2 - x1) / 2;
    y = rr * 2 * k;
    l1 = sqrt(x * x + y * y) - rr;
    l2 = sqrt(x * x + y * y) + rr;
    l = r * r / 2 * (1 / l1 - 1 / l2);
    cout << l << "\n";
  }
  return 0;
}
