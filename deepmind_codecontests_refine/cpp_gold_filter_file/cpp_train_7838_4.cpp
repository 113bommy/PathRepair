#include <bits/stdc++.h>
int main() {
  int k, i, j, b = 0, c, d = 0, a[15];
  scanf("%d", &k);
  for (i = 0; i < 12; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < 11; i++) {
    for (j = i + 1; j < 12; j++) {
      if (a[i] < a[j]) {
        c = a[i];
        a[i] = a[j];
        a[j] = c;
      }
    }
  }
  if (k == 0) {
    printf("0\n");
  } else {
    while (b < k && d < 12) {
      b += (a[d]);
      d++;
    }
    if (b >= k) {
      printf("%d\n", d);
    } else {
      printf("-1\n");
    }
  }
  return 0;
}
