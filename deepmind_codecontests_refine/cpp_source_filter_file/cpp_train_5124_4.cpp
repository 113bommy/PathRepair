#include <bits/stdc++.h>
int main() {
  int count, i, a, x, max, tc;
  scanf("%d", &tc);
  for (int j = 0; j < tc; j++) {
    count = 0, max = 0;
    scanf("%d", &x);
    char s[x];
    scanf("%s", s);
    for (i = x; i > 0; i--) {
      if (s[i] == 'P') {
        count += 1;
      } else {
        if (count > max) {
          max = count;
        }
        count = 0;
      }
    }
    printf("%d\n", max);
  }
  return 0;
}
