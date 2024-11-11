#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5 + 9;
long long val[MX], va[MX];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    for (int i = 0; i < 6; i++) scanf("%lld", &val[i]), va[i] = val[i];
    for (int i = 0; i < 6; i++) {
      long long v = (val[(i - 1 + 6) % 6] + val[(i + 1) % 6]);
      va[i] = min(va[i], v);
    }
    long long xx, numx, yy, numy;
    if (x >= 0) {
      if (y <= 0)
        xx = 5, numx = x, yy = 4, numy = -y;
      else {
        if (x >= y)
          xx = 0, numx = y, yy = 5, numy = x - y;
        else
          xx = 0, numx = x, yy = 1, numy = y - x;
      }
    } else {
      if (y <= 0) {
        y = abs(y), x = abs(x);
        if (x >= y)
          xx = 2, numx = x - y, yy = 3, numy = y;
        else
          xx = 3, numx = x, yy = 4, numy = y - x;
      } else
        xx = 2, numx = -x, yy = 1, numy = y;
    }
    printf("%lld\n", va[xx] * numx + va[yy] * numy);
  }
  return 0;
}
