#include <bits/stdc++.h>
int main() {
  int t;
  int i, j, k;
  int flag;
  long long x1, x2, x3, x4, x, y;
  int ans[55][55];
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld%lld%lld", &x1, &x2, &x3, &x4);
    x = x3 - x1;
    y = x4 - x2;
    printf("%lld\n", x * y + 1);
  }
  return 0;
}
