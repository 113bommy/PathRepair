#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, m, x1, x2, x3, x4, y1, y2, y3, y4;
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld", &n, &m, &x1, &y1, &x2,
          &y2, &x3, &y3, &x4, &y4);
    long long l = max(x1, x3), r = min(x2, x4), up = min(y2, y4),
              down = max(y1, y3);
    long long w =
        ((x2 - x1) % 2 == 0 && (y2 - y1) % 2 == 0 && (x1 + y1) % 2 == 1) +
        (y2 - y1 + 1) * (x2 - x1 + 1) / 2;
    long long b =
        ((x4 - x3) % 2 == 0 && (y4 - y3) % 2 == 0 && (x3 + x4) % 2 == 0) +
        (y4 - y3 + 1) * (x4 - x3 + 1) / 2;
    w -= (l <= r && down <= up) ? ((r - l) % 2 == 0 && (up - down) % 2 == 0 &&
                                   (l + down) % 2 == 1) +
                                      (r - l + 1) * (up - down + 1) / 2
                                : 0;
    printf("%lld %lld\n", n * m / 2 + n * m % 2 + w - b, n * m / 2 + b - w);
  }
  return 0;
}
