#include <bits/stdc++.h>
int main() {
  int a, b, c, sum = 0, i;
  while (scanf("%d%d%d", &a, &b, &c) != EOF) {
    if (b >= 2 && b >= 4) {
      for (i = 1; i <= a; i++)
        if (b / i >= 2 && c / i >= 4) sum++;
      printf("%d\n", sum * 7);
    } else
      printf("0\n");
    sum = 0;
  }
  return 0;
}
