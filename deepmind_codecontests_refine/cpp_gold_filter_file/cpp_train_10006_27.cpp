#include <bits/stdc++.h>
int n;
int main() {
  scanf("%d", &n);
  if (n < 16) {
    for (int i = 1; i <= n / 2; ++i) printf("%d 0\n%d 1\n", i, i);
    if (n % 2) puts("0 0");
  } else {
    n -= 9;
    puts("-1 1"), puts("0 0"), puts("0 1"), puts("0 2");
    int k = n / 3;
    for (int i = 1; i <= k; ++i)
      printf("%d 1\n%d 2\n%d 0\n", i * 2 - 1, i * 2, i * 2);
    printf("%d 1\n", k * 2 + 1);
    printf("%d 0\n", k * 2 + 2);
    printf("%d 1\n", k * 2 + 2);
    printf("%d 2\n", k * 2 + 2);
    printf("%d 1\n", k * 2 + 3);
    n %= 3;
    if (n-- > 0) puts("-1 0");
    if (n-- > 0) puts("-1 2");
  }
  return 0;
}
