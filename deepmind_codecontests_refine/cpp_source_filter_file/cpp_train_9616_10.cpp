#include <bits/stdc++.h>
int main() {
  int t, i, a[10000], count1 = 0, count2 = 0, x, y;
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < t; i++) {
    if (a[i] % 2 == 0) {
      count1++;
      x = i;
    } else {
      count2++;
      y = i;
    }
  }
  if (count1 > count2) {
    printf("%d", y);
  } else {
    printf("%d", x);
  }
}
