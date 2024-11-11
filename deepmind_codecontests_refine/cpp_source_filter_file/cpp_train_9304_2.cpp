#include <bits/stdc++.h>
using namespace std;
int main() {
  double w, h, a;
  cin >> w >> h >> a;
  if (h > w) swap(w, h);
  if (a > 90) a = 180 - a;
  if (a == 90) {
    cout << h * h;
    return 0;
  }
  double c = cos(a * (M_PI / 180));
  double s = sin(a * (M_PI / 180));
  if (a / 2 > (180 / M_PI) * atan(h / w)) {
    cout << fixed << setprecision(7) << w * h - h * (w - h * s / c);
    return 0;
  } else {
    double aa = (w * s - h * (1 + c)) / (s * s - (1 + c) * (1 + c));
    double bb = (h * s - w * (1 + c)) / (s * s - (1 + c) * (1 + c));
    cout << fixed << setprecision(7) << w * h - (aa * aa + bb * bb) * s * c;
    return 0;
  }
}
