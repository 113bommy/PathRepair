#include <bits/stdc++.h>
using namespace std;
long double dyst(long double x1, long double y1, long double x2,
                 long double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
long double eps = 0.000001;
bool zero(long double x) { return (x + eps > 0 && x - eps < 0); }
int main() {
  long double a, b, c;
  cin >> a >> b >> c;
  long double x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long double wyn = abs(x1 - x2) + abs(y1 - y2);
  if (zero(a) || zero(b)) {
    cout << wyn;
    return 0;
  }
  long double pomy1 = -(a * x1 + c) / b;
  long double pomx1 = -(b * y1 + c) / a;
  long double pomy2 = -(a * x2 + c) / b;
  long double pomx2 = -(b * y2 + c) / a;
  wyn =
      min(wyn, abs(x1 - pomx1) + abs(x2 - pomx2) + dyst(pomx1, y1, pomx2, y2));
  wyn =
      min(wyn, abs(x1 - pomx1) + abs(y2 - pomy2) + dyst(pomx1, y1, x2, pomy2));
  wyn =
      min(wyn, abs(y1 - pomy1) + abs(x2 - pomx2) + dyst(pomy1, x1, y2, pomx2));
  wyn =
      min(wyn, abs(y1 - pomy1) + abs(y2 - pomy2) + dyst(pomy1, x1, pomy2, x2));
  cout << fixed << setprecision(9) << wyn;
}
