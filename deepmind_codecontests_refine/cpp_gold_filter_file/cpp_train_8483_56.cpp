#include <bits/stdc++.h>
int main() {
  int r, b;
  scanf("%d %d", &r, &b);
  int s = r + b;
  if (r == b)
    printf("%d 0", s / 2);
  else if (r < b) {
    printf("%d ", r);
    if ((s - (r * 2)) < 2)
      printf("0");
    else if ((s - (r * 2)) == 0)
      printf("%d", r);
    else if ((s - (r * 2)) >= 2)
      printf("%d", ((s - (r * 2))) / 2);
  } else if (r > b) {
    printf("%d ", b);
    if ((s - (b * 2)) < 2)
      printf("0");
    else if ((s - (b * 2)) == 0)
      printf("%d", b);
    else if ((s - (b * 2)) >= 2)
      printf("%d", ((s - (b * 2))) / 2);
  }
}
