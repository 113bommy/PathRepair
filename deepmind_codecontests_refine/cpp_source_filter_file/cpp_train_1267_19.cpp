#include <bits/stdc++.h>
int main() {
  int n, x, y, i, j, a[100005], flag, b, e;
  scanf("%d%d%d", &n, &x, &y);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= n; i++) {
    flag = 1;
    if (i - x)
      b = i - x;
    else
      b = 1;
    for (j = b; j < i; j++) {
      if (a[i] >= a[j]) {
        flag = 0;
        break;
      }
    }
    if (i + y > n)
      e = n;
    else
      e = i + y;
    for (j = i + 1; j <= e; j++) {
      if (a[i] >= a[j]) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
