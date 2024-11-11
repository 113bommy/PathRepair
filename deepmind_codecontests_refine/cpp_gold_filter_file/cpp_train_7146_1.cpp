#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    double x1, y1, x2 = 1, y2 = 1, x = 3, y = 3, R, r;
    cin >> R >> x1 >> y1 >> x2 >> y2;
    double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if (d >= R) {
      cout << fixed << setprecision(15) << x1 << " ";
      cout << fixed << setprecision(15) << y1 << " ";
      cout << fixed << setprecision(15) << R;
    } else {
      if (x1 != x2) {
        double m = (y1 - y2) / (x1 - x2);
        double a = m * m + 1;
        double b = -2 * (x1 + m * m * x1);
        double c = x1 * x1 + m * m * x1 * x1 - R * R;
        double X1 = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
        double Y1 = m * X1 - m * x1 + y1;
        d = sqrt((X1 - x2) * (X1 - x2) + (Y1 - y2) * (Y1 - y2));
        double r = d / 2;
        double ansx = (x2 + X1) / 2, ansy = (Y1 + y2) / 2, ansr = r;
        X1 = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);
        Y1 = m * X1 - m * x1 + y1;
        d = sqrt((X1 - x2) * (X1 - x2) + (Y1 - y2) * (Y1 - y2));
        r = d / 2;
        if (r > ansr) {
          ansx = (x2 + X1) / 2;
          ansy = (Y1 + y2) / 2;
          ansr = r;
        }
        cout << fixed << setprecision(15) << ansx << " ";
        cout << fixed << setprecision(15) << ansy << " ";
        cout << fixed << setprecision(15) << ansr;
      } else {
        double m = (y1 - y2) / (x1 - x2);
        double a = 1;
        double b = -2 * y1;
        double c = y1 * y1 - R * R;
        double X1 = x1;
        double Y1 = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
        d = sqrt((X1 - x2) * (X1 - x2) + (Y1 - y2) * (Y1 - y2));
        double r = d / 2;
        double ansx = (x2 + X1) / 2, ansy = (Y1 + y2) / 2, ansr = r;
        X1 = x1;
        Y1 = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);
        d = sqrt((X1 - x2) * (X1 - x2) + (Y1 - y2) * (Y1 - y2));
        r = d / 2;
        if (r > ansr) {
          ansx = (x2 + X1) / 2;
          ansy = (Y1 + y2) / 2;
          ansr = r;
        }
        cout << fixed << setprecision(15) << ansx << " ";
        cout << fixed << setprecision(15) << ansy << " ";
        cout << fixed << setprecision(15) << ansr;
      }
    }
  }
  return 0;
}
