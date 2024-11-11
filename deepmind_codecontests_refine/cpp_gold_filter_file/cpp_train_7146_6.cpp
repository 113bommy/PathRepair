#include <bits/stdc++.h>
using namespace std;
int main() {
  long long R, x1, y1, x2, y2;
  cin >> R >> x1 >> y1 >> x2 >> y2;
  long long t = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  if (t > R * R) {
    cout << setprecision(15) << x1 << " " << y1 << " " << R;
  } else if (t == R * R) {
    cout << setprecision(15) << x1 << " " << y1 << " "
         << (double)(R - 0.00000001);
  } else {
    if (t != 0) {
      double xAO = (x1 - x2);
      double yAO = (y1 - y2);
      double r = 10000000 * (R + sqrt(t)) / 2;
      double xans = (xAO / sqrt(t)) * r + x2 * 10000000;
      double yans = (yAO / sqrt(t)) * r + y2 * 10000000;
      cout << setprecision(15) << xans / 10000000 << " " << yans / 10000000
           << " " << r / 10000000;
    } else {
      cout << setprecision(15) << x1 << " " << y1 - (double)R / 2 << " "
           << (double)R / 2 - 0.000000001;
    }
  }
  return 0;
}
