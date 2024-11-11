#include <bits/stdc++.h>
int x, y;
int a[3];
int res;
int main() {
  scanf("%d %d", &x, &y);
  res = 0;
  a[0] = a[1] = a[2] = y;
  while (1) {
    if (a[1] + a[2] - 1 >= x) {
      res += 3;
      break;
    }
    a[0] = a[1];
    a[1] = a[2];
    a[2] = a[0] + a[1];
    res++;
  }
  printf("%d\n", res);
  return 0;
}
