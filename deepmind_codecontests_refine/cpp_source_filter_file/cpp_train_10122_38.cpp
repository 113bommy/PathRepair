#include <bits/stdc++.h>
int main() {
  int t, a, b, s;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &a, &b);
    if (a < b) {
      s = b - a;
      if (s == 1)
        printf("1\n");
      else
        printf("2\n");
    } else if (a > b) {
      s = a - b;
      if (s % 2 == 0)
        printf("1\n");
      else
        printf("2\n");
    } else
      printf("0\n");
  }
}
