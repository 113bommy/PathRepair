#include <bits/stdc++.h>
int main(void) {
  int t, i, a, b;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d%d", &a, &b);
    if (a == b)
      printf("0\n");
    else if (a > b)
      if ((a - b) % 2 == 0)
        printf("1\n");
      else
        printf("2\n");
    else if ((b - a) % 2 == 0)
      printf("2\n");
    else
      printf("1\n");
  }
  return 0;
}
