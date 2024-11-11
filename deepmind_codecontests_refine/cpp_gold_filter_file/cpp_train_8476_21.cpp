#include <bits/stdc++.h>
using namespace std;
int main() {
  double x;
  cin >> x;
  for (int a = 1; a <= 10; a++) {
    for (int h = 1; h <= 10; h++) {
      double vol = (a * a * h) / 3.0;
      double sidearea = sqrt(h * h + a * a / 4.0) * a / 2.0;
      double r = 0.75 * vol / sidearea;
      if (fabs(r - x) < 1e-6) {
        cout << a << " " << h << endl;
        return 0;
      }
    }
  }
  return 0;
}
