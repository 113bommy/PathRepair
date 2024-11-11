#include <bits/stdc++.h>
using namespace std;
double miin(double x, double y) { return x > y ? y : x; }
int main() {
  int n;
  cin >> n;
  double a[1][2];
  double max, min;
  double b[n];
  double m1, m2, x, y;
  for (int i = 0; i < n; i++) {
    cin >> a[0][0] >> a[0][1];
    if (a[0][0] != 0) {
      x = atan2(abs(a[0][1]), abs(a[0][0])) * 180 / 3.14159265;
      if (a[0][0] < 0 && a[0][1] >= 0)
        x = 180 - x;
      else if (a[0][0] < 0 && a[0][1] <= 0)
        x = 180 + x;
      else if (a[0][0] > 0 && a[0][1] < 0)
        x = 360 - x;
    } else if (a[0][0] == 0) {
      if (a[0][1] > 0) x = 90;
      if (a[0][1] < 0) x = 270;
    }
    if (i == 0) {
      min = x;
      max = x;
    } else {
      if (x < min)
        min = x;
      else if (x > max)
        max = x;
    }
    b[i] = x;
  }
  double ans = max - min;
  sort(b, b + n);
  for (int i = 1; i < n; i++) {
    ans = miin(ans, 360 - (b[i] - b[i - 1]));
  }
  printf("%f\n", ans);
}
