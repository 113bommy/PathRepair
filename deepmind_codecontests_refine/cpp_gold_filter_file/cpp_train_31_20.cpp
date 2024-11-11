#include <bits/stdc++.h>
int main() {
  int i, n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  i = (y * n) / 100;
  if (i >= x) {
    if (y * n > i * 100) {
      i++;
      printf("%d\n", i - x);
    } else
      printf("%d\n", i - x);
  } else
    printf("0\n");
  scanf("%d", &i);
  return 0;
}
