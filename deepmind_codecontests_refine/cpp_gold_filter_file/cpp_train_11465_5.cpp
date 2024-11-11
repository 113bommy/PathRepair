#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
void solve(int x) {
  double l, r, a, b;
  int flag = 0;
  l = 0.0;
  r = 1.0 * x / 2.0;
  while (l < r) {
    double mid = (l + r) / 2.0;
    a = mid;
    b = 1.0 * x - mid;
    if (fabs((a + b) - a * b) <= eps) {
      flag = 1;
      cout << "Y"
           << " ";
      printf("%.9f %.9f\n", b, a);
      break;
    }
    if ((a + b) <= a * b)
      r = mid;
    else
      l = mid;
  }
  if (flag == 0) cout << "N" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int d;
    cin >> d;
    if (d == 0) {
      double b = 0.0, a = 0.0;
      cout << "Y"
           << " ";
      printf("%.9f %.9f\n", b, a);
    } else
      solve(d);
  }
  return 0;
}
