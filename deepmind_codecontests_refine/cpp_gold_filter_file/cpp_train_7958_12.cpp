#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  if (n < 4) {
    printf("NO");
    return 0;
  }
  printf("YES\n");
  if (n % 2) {
    printf("2 - 1 = 1\n");
    printf("5 * 4 = 20\n");
    printf("20 + 3 = 23\n");
    printf("23 + 1 = 24\n");
    for (int i = 7; i <= n; i += 2)
      printf("%d - %d = 1\n24 * 1 = 24\n", i, i - 1);
  } else {
    printf("1 * 2 = 2\n");
    printf("2 * 3 = 6\n");
    printf("6 * 4 = 24\n");
    for (int i = 6; i <= n; i += 2)
      printf("%d - %d = 1\n24 * 1 = 24\n", i, i - 1);
  }
  return 0;
}
