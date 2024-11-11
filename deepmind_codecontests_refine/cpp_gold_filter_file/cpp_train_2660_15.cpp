#include <bits/stdc++.h>
int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  if ((a + b > c && a + c > b && b + c > a) ||
      (a + c > d && a + d > c && c + d > a) ||
      (a + b > d && a + d > b && b + d > a) ||
      (b + c > d && b + d > c && c + d > b)) {
    printf("TRIANGLE\n");
  } else if ((a + b >= c && a + c > b && b + c > a) ||
             (a + b > c && a + c >= b && b + c > a) ||
             (a + b > c && a + c > b && b + c >= a)) {
    printf("SEGMENT\n");
  } else if ((a + c >= d && a + d > c && c + d > a) ||
             (a + c > d && a + d >= c && c + d > a) ||
             (a + c > d && a + d > c && c + d >= a)) {
    printf("SEGMENT\n");
  } else if ((a + b >= d && a + d > b && b + d > a) ||
             (a + b > d && a + d >= b && b + d > a) ||
             (a + b > d && a + d > b && b + d >= a)) {
    printf("SEGMENT\n");
  } else if ((b + c >= d && b + d > c && c + d > b) ||
             (b + c > d && b + d >= c && c + d > b) ||
             (b + c > d && b + d > c && c + d >= b)) {
    printf("SEGMENT\n");
  } else {
    printf("IMPOSSIBLE");
  }
  return 0;
}
