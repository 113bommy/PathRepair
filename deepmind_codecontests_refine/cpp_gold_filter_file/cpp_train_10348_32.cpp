#include <bits/stdc++.h>
int main() {
  int b, g, sum, i;
  scanf("%d %d", &b, &g);
  sum = b + (g - 1);
  printf("%d\n", sum);
  for (i = 1; i <= g; i++) {
    printf("1 %d\n", i);
  }
  for (i = 2; i <= b; i++) {
    printf("%d %d\n", i, g);
  }
  return 0;
}
