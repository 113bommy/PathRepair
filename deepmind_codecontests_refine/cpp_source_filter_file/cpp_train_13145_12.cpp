#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 2e4 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;
long long c[7];
long long ans;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x, y;
    scanf("%d%d", &x, &y);
    for (int i = 1; i <= 6; i++) scanf("%lld", &c[i]);
    c[1] = min(c[1], c[2] + c[6]);
    c[2] = min(c[2], c[1] + c[3]);
    c[3] = min(c[3], c[2] + c[4]);
    c[4] = min(c[4], c[3] + c[5]);
    c[5] = min(c[5], c[4] + c[6]);
    c[6] = min(c[6], c[1] + c[5]);
    if (x >= 0 && y >= 0) {
      if (x > y)
        printf("%lld\n", y * c[1] + (x - y) * c[2]);
      else
        printf("%lld\n", x * c[1] + (y - x) * c[6]);
    } else if (x <= 0 && y <= 0) {
      if (x > y)
        printf("%lld\n", (-x) * c[4] + (x - y) * c[5]);
      else
        printf("%lld\n", (-y) * c[4] + (y - x) * c[3]);
    } else if (x >= 0 && y <= 0)
      printf("%lld\n", x * c[6] + (-y) * c[5]);
    else
      printf("%lld\n", (-x) * c[3] + y * c[2]);
  }
  return 0;
}
