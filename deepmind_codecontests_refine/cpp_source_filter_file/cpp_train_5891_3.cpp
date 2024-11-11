#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  long double n, X1, Y1, X2, Y2, x1, y1, x2, y2, x, y, m, tempx, tempy;
  long double Min = LONG_MAX;
  cin >> n >> X1 >> Y1 >> X2 >> Y2;
  x1 = X1;
  y1 = Y1;
  x = X2;
  y = Y2;
  for (int i = 2; i < n; i++) {
    cin >> x2 >> y2;
    if (x1 == x2) {
      Min = min(Min, abs(x - x1));
    } else {
      m = (y1 - y2) / (x1 - x2);
      Min = min(Min, abs(y - m * x + m * x1 - y1) / sqrt(1 + m * m));
    }
    tempx = x;
    tempy = y;
    x = x2;
    y = y2;
    x1 = tempx;
    y1 = tempy;
  }
  if (x1 == X1) {
    Min = min(Min, abs(x - x1));
  } else {
    m = (Y1 - y1) / (X1 - x1);
    Min = min(Min, abs(y - m * x + m * x1 - y1) / sqrt(1 + m * m));
  }
  if (x == X2) {
    Min = min(Min, abs(x - x1));
  } else {
    m = (Y2 - y) / (X2 - x);
    Min = min(Min, abs(Y1 - m * X1 + m * x - y) / sqrt(1 + m * m));
  }
  cout << setprecision(20) << Min / 2;
}
