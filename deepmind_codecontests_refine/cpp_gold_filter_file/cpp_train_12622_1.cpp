#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n, k, t;
int main() {
  scanf("%d", &t);
  long long x1, x2, y1, y2;
  long long ans = 0;
  while (t--) {
    scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
    ans = 1 + (y2 - y1) * (x2 - x1);
    printf("%lld\n", ans);
  }
  return 0;
}
