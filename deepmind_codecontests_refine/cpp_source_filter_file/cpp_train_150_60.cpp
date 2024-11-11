#include <bits/stdc++.h>
int main() {
  int n, i, r, j, d, k, x = 0;
  scanf("%d", &n);
  r = n / 4;
  char str[n];
  scanf("%s", str);
  for (i = 0; str[i]; i++) {
    if (str[i] == '*') {
      for (j = i + 1; j <= r; j++) {
        if (str[j] == '*') {
          d = j - i;
          for (k = i + d; str[k]; k = k + d) {
            if (str[k] == '*')
              x++;
            else
              break;
          }
          if (x >= 4) {
            printf("yes");
            return 0;
          } else
            x = 0;
        }
      }
    }
  }
  printf("no");
}
