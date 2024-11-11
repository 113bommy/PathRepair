#include <bits/stdc++.h>
using namespace std;
const int MAX = 300;
int c[10];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    for (int i = 1; i <= 6; i++) scanf("%d", c + i);
    long long costX, costY;
    if (x < 0)
      costX = min(c[3], c[1] + c[5]);
    else if (x > 0)
      costX = min(c[6], c[4] + c[2]);
    else
      costX = 0;
    if (y < 0)
      costY = min(c[5], c[4] + c[6]);
    else if (y > 0)
      costY = min(c[2], c[1] + c[3]);
    else
      costY = 0;
    long long ans = 0;
    if (x >= 0 && y >= 0 && c[6] + c[2] > c[1])
      ans = min(x, y) * c[1] + (x >= y ? (x - y) * costX : (y - x) * costY);
    else if (x <= 0 && y <= 0 && c[3] + c[5] > c[4])
      ans = max(x, y) * c[4] + (x <= y ? (x - y) * -costX : (y - x) * -costY);
    else
      ans = abs(x) * costX + abs(y) * costY;
    printf("%lld\n", ans);
  }
  return 0;
}
