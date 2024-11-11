#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t1, t2, x1, x2, t0;
  double temp = 10e9 + 5;
  ;
  long c, h;
  cin >> t1 >> t2 >> x1 >> x2 >> t0;
  while (x1 >= 0 && x2 >= 0) {
    double t = ((t1 * x1) + (t2 * x2)) / (double)(x1 + x2);
    if (t < t0) {
      x1--;
      continue;
    }
    if (t < temp) {
      temp = t, c = x1, h = x2;
    }
    x2--;
  }
  cout << c << " " << h << "\n";
  return 0;
}
