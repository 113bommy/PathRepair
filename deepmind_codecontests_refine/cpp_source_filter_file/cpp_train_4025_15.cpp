#include <bits/stdc++.h>
using namespace std;
int main() {
  float hh, mm;
  cin >> hh >> mm;
  float d, c;
  int h, n;
  cin >> h >> d >> c >> n;
  if (hh >= 20) {
    float f;
    int i = (h / n);
    if (h % n != 0) {
      i = i + 1;
    }
    f = (i) * (0.8 * c + 0.000);
    cout << f;
    return 0;
  }
  if (hh < 20) {
    int s = (h / n);
    if (h % n != 0) {
      s = s + 1;
    }
    int g = d * ((20 - hh) * 60 - (-mm)) + h;
    int f = g / n;
    if (g % n != 0) {
      f++;
    }
    float j = 0.8 * c + 0.000;
    float b = min(f * j, ((s)*c));
    cout << b;
    return 0;
  }
  return 0;
}
