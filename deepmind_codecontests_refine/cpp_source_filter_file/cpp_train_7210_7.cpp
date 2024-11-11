#include <bits/stdc++.h>
int main() {
  long a[7], m, sum = 0, count = 0, i;
  scanf("%ld", &m);
  for (i = 0; i < 7; i++) scanf("%ld", &a[i]);
  for (;;) {
    for (i = 0; i < 7; i++) {
      sum += a[i];
      if (sum <= m)
        count++;
      else
        break;
    }
    if (sum > m) {
      printf("%ld", count + 1);
      break;
    } else {
      m = m - sum;
      sum = 0;
      count = 0;
    }
  }
}
