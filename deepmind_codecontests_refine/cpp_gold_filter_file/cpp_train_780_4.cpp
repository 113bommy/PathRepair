#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long x1, y1, x2, y2;
  scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
  printf("%lld", (y2 - y1 + 2) / 2 * (x2 - x1 + 1) - (x2 - x1 + 1) / 2);
  return 0;
}
