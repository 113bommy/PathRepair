#include <bits/stdc++.h>
int main() {
  int n, d1, d2, d3, d4, x, flag1 = 1, flag2 = 1, flag3 = 1, ans, i;
  scanf("%d", &n);
  for (i = n + 1; i < 9999; i++) {
    x = i;
    d1 = x % 10;
    x = x / 10;
    d2 = x % 10;
    x = x / 10;
    d3 = x % 10;
    x = x / 10;
    d4 = x;
    if (d1 != d2 && d1 != d3 && d1 != d4)
      flag1 = 1;
    else
      flag1 = 0;
    if (d2 != d1 && d2 != d3 && d2 != d4)
      flag2 = 1;
    else
      flag2 = 0;
    if (d3 != d1 && d3 != d2 && d3 != d4)
      flag3 = 1;
    else
      flag3 = 0;
    if (flag1 == 1 && flag2 == 1 && flag3 == 1) {
      ans = i;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}
