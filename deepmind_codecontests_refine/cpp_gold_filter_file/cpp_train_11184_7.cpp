#include <bits/stdc++.h>
using namespace std;
bool check(int x) {
  double y;
  y = sqrt(x);
  int t;
  t = sqrt(x);
  if (y == t)
    return 1;
  else
    return 0;
}
int main() {
  int a, b;
  cin >> a >> b;
  int i;
  int x, y, x1, y1;
  bool ans = false;
  float slope, slope90, k, t;
  for (int(i) = (1); (i) <= (a - 1); ++i) {
    if (check(a * a - i * i)) {
      x = i;
      y = sqrt(a * a - i * i);
      slope = (y * 1.0) / (x * 1.0);
      slope90 = -1.0 / slope;
      k = sqrt((b * b) / (slope90 * slope90 + 1));
      if (ceil(k) == floor(k)) {
        x1 = k;
        t = k * slope90;
        if (fabs(t - round(t)) < 0.0001) {
          y1 = round(t);
          if (x1 != x && y1 != y) {
            ans = true;
            break;
          }
        }
      }
    }
  }
  if (ans) {
    cout << "YES" << endl;
    cout << "0 0" << endl;
    cout << x << " " << y << endl;
    cout << x1 << " " << y1 << endl;
  } else
    cout << "NO";
  return 0;
}
