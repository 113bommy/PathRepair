#include <bits/stdc++.h>
int main() {
  int a, b, c, count = 0, i, j;
  scanf("%d%d%d", &a, &b, &c);
  if ((a == c) || (b == c)) {
    count++;
  } else {
    for (i = a; i < c; i += a) {
      for (j = 0; j < c; j += b) {
        if ((i + j) == c) {
          count++;
          break;
        }
      }
    }
  }
  if (count != 0) {
    printf("Yes");
  } else {
    printf("No");
  }
  return 0;
}
