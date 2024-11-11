#include <bits/stdc++.h>
int main() {
  int x, val = 1, o = 1, n = 2, ans;
  scanf("%d", &x);
  while (val <= x) {
    if (x % val == 0) ans = val;
    o *= 2;
    n *= 2;
    val = (n - 1) * o;
  }
  printf("%d", ans);
  return 0;
}
