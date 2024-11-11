#include <bits/stdc++.h>
using namespace std;
long long c[10];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long x, y, ans = 0;
    scanf("%lld %lld", &x, &y);
    for (int i = 1; i <= 6; ++i) {
      scanf("%lld", &c[i]);
    }
    for (int i = 1; i <= 6; ++i) {
      int j = i - 1, k = i + 1;
      if (!j) j = 6;
      if (k > 6) k %= 6;
      c[i] = min(c[i], c[j] + c[k]);
    }
    if (x >= 0 && y >= 0) {
      long long tmp = min(x, y);
      ans = c[1] * tmp + c[2] * (y - tmp) + c[6] * (x - tmp);
    } else if (x >= 0 && y < 0) {
      ans = c[6] * x - c[5] * y;
    } else if (x < 0 && y >= 0) {
      ans = c[2] * y - c[3] * x;
    } else {
      long long tmp = min(-x, -y);
      ans = c[4] * tmp - c[5] * (y + tmp) - c[4] * (x + tmp);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
