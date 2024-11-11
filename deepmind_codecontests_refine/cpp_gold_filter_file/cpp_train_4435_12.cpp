#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, h, x, area, arN, areaN, h1, h2, m, i, ar;
  cin >> n >> h;
  area = 0.5 * h;
  arN = area / n;
  h1 = 0;
  h2 = 1;
  for (i = 1; i < n; i++) {
    areaN = arN * i;
    while (h2 > h1) {
      m = (h1 + h2) / 2;
      ar = (m * m * h) / 2;
      if (abs(areaN - ar) < 0.000000005) {
        printf("%lf ", m * h);
        break;
      } else if (ar > areaN)
        h2 = m;
      else
        h1 = m;
    }
    h1 = m;
    h2 = 1;
  }
  return 0;
}
