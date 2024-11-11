#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long x1, y1, x2, y2;
  scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
  printf("%lld", (y1 - y2 + 2) / 2 * (x1 - x2 + 1) - (x1 - x2 + 1) / 2);
  return 0;
}
