#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  for (int i = 0; i != x; ++i) {
    long long x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    if (x2 - x1 + 1 > x || y2 - y1 > x) {
      cout << x * y;
    } else {
      long long delta_x = x2 > x1 ? x2 - x1 : x1 - x2;
      long long delta_y = y1 > y2 ? y1 - y2 : y2 - y1;
      long long x_untouchable = 0;
      x_untouchable = (delta_x + 1) * 2 - x - 2;
      if (x_untouchable < 0) x_untouchable = 0;
      long long y_untouchable = 0;
      y_untouchable = (delta_y + 1) * 2 - y - 2;
      if (y_untouchable < 0) y_untouchable = 0;
      cout << y_untouchable * x + x_untouchable * y -
                  x_untouchable * y_untouchable +
                  (delta_x - x_untouchable) * (delta_y - y_untouchable) * 2
           << endl;
    }
  }
}
