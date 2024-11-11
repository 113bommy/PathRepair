#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = LONG_LONG_MAX;
int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    long long z = x * y;
    long long l = 0, r = 1e6 + 5;
    long long ans = 1e6 + 5;
    while (r - l > 1) {
      long long mid = (l + r) >> 1;
      if (mid * mid * mid <= z)
        ans = mid, l = mid;
      else
        r = mid;
    }
    if (ans * ans * ans == z && x % ans == 0 && y % ans == 0)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
