#include <bits/stdc++.h>
using namespace std;
const double pi = 4 * atan(1.0);
int main() {
  double d, h, v, e;
  while (cin >> d >> h >> v >> e) {
    double decrease = v * 1.0 / (pi * d * 1.0 / 4.0);
    if (decrease <= e)
      puts("NO");
    else {
      puts("YES");
      cout << fixed << setprecision(12) << h * 1.0 / (decrease - e) << endl;
    }
  }
  return 0;
}
