#include <bits/stdc++.h>
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    int temp = y - x, diff = 0, flag = 0;
    for (int i = 1; i <= temp; i++) {
      if (temp % i == 0) {
        diff = i;
        for (int i = 1; i < n; i++) {
          if (x + (diff * i) == y) {
            flag = 1;
          }
        }
        if (flag)
          break;
        else
          continue;
      }
    }
    int index = 1;
    for (int i = 0; i < n; i++) {
      if (y - (i * diff) >= 0)
        printf("%d", y - (i * diff));
      else {
        printf("%d", y + (index * diff));
        index++;
      }
      if (i < n - 1) printf(" ");
    }
    puts("");
  }
  return 0;
}
