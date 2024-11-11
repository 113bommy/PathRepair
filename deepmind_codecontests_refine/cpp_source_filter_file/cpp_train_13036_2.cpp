#include <bits/stdc++.h>
int main() {
  int t;
  scanf("%d", &t);
  int i;
  for (i = 0; i < t; i++) {
    int a, b, c, ans, x;
    scanf("%d %d %d", &a, &b, &c);
    if (a >= 4 && b >= 4 && c >= 4) {
      ans = 7;
    } else if (a >= 3 && b >= 3 && c >= 3) {
      ans = 6;
    } else if ((a >= 2 && b >= 2 && c >= 3) || (a >= 3 && b >= 2 && c >= 2) ||
               (a >= 2 && b >= 3 && c >= 2)) {
      ans = 5;
    } else if ((a >= 2 && b >= 2 && c >= 1) || (a >= 1 && b >= 2 && c >= 2) ||
               (a >= 2 && b >= 1 && c >= 2)) {
      ans = 4;
    } else if ((a >= 1 && b >= 1 && c >= 1) || (a == 0 && b >= 2 && c >= 2) ||
               (a >= 2 && b == 0 && c >= 2) || (a >= 2 && b >= 2 && c == 0)) {
      ans = 3;
    } else if (((a == 0 && b >= 1 && c >= 1) || (a >= 1 && b == 0 && c >= 1) ||
                (a >= 1 && b >= 1 && c == 0))) {
      ans = 2;
    } else if (a == 1 || b == 1 || c == 1) {
      ans = 1;
    } else if (a == 0 && b == 0 && c == 0) {
      ans = 0;
    }
    printf("%d\n", ans);
  }
  return 0;
}
