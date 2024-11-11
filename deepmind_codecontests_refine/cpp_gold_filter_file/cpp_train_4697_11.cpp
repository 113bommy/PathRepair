#include <bits/stdc++.h>
int a[100001];
int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  int max = 0;
  if (a + b > c && b + c > a && a + c > b) {
    printf("0");
  } else {
    if (a + b <= c) {
      max = c - (a + b) + 1;
      printf("%d", max);
    } else {
      if (c + b <= a) {
        max = a - (c + b) + 1;
        printf("%d", max);
      } else {
        if (a + c <= b) {
          max = b - (a + c) + 1;
          printf("%d", max);
        }
      }
    }
  }
  return 0;
}
