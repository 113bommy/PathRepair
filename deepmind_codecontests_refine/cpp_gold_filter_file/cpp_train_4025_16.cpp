#include <bits/stdc++.h>
using namespace std;
int main() {
  long long hh, mm, h, d, c, n;
  cin >> hh >> mm >> h >> d >> c >> n;
  if (hh < 20) {
    double cur = (h / n + (h % n != 0)) * c * 1.0;
    double cut = (((20 * 60 - hh * 60 - mm) * d + h) / n +
                  (((20 * 60 - hh * 60 - mm) * d + h) % n != 0)) *
                 c * 0.8;
    printf("%.4lf\n", min(cur, cut));
  } else {
    printf("%.4lf\n", (h / n + (h % n != 0)) * c * 0.8);
  }
  return 0;
}
