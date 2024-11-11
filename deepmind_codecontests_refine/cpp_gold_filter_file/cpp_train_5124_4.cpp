#include <bits/stdc++.h>
int main() {
  int t, i, n, count, max;
  scanf("%d", &t);
  char c[100];
  while (t--) {
    max = 0;
    count = 0;
    scanf("%d", &n);
    scanf("%s", c);
    for (i = 0; i < n; ++i) {
      if (c[i] == 'A') {
        break;
      }
    }
    if (i == n - 1) {
      printf("0\n");
    } else {
      for (; i < n; ++i) {
        if (c[i] == 'P') {
          count++;
          max = max < count ? count : max;
        } else
          count = 0;
      }
      printf("%d\n", max);
    }
  }
}
