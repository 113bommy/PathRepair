#include <bits/stdc++.h>
int n;
void print(int x, int d) {
  for (int i = x; i >= 0; i--) {
    for (int j = 4 * i + d; j > 0; j--) {
      printf("%d %d\n", j, 4 * i + 1 + d);
    }
    printf("%d %d\n", 4 * i + 1 + d, 4 * i + 2 + d);
    for (int j = 1; j <= 4 * i + d; j++) {
      printf("%d %d\n", j, 4 * i + 2 + d);
    }
    for (int j = 4 * i + d; j > 0; j--) {
      printf("%d %d\n", j, 4 * i + 3 + d);
    }
    printf("%d %d\n", 4 * i + 3 + d, 4 * i + 4 + d);
    for (int j = 1; j <= 4 * i + d; j++) {
      printf("%d %d\n", j, 4 * i + 4 + d);
    }
    printf("%d %d\n", 4 * i + 1 + d, 4 * i + 4 + d);
    printf("%d %d\n", 4 * i + 2 + d, 4 * i + 3 + d);
    printf("%d %d\n", 4 * i + 1 + d, 4 * i + 3 + d);
    printf("%d %d\n", 4 * i + 4 + d, 4 * i + 2 + d);
  }
}
int main() {
  scanf("%d", &n);
  if ((n % 4) > 1) {
    printf("NO");
    return 0;
  } else {
    if (n == 1) {
      printf("YES");
      return 0;
    }
    printf("YES\n");
    if (n % 4 == 0) {
      print((n / 4) - 1, 0);
    } else {
      print((n / 4) - 1, 1);
    }
  }
  return 0;
}
