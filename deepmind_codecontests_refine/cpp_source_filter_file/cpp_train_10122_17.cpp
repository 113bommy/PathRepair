#include <bits/stdc++.h>
int main() {
  int t, a, b;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &a, &b);
    if (a < b) {
      if ((b - a) ^ 1) {
        puts("2");
      } else {
        puts("1");
      }
    } else if (a > b) {
      if ((a - b) ^ 1) {
        puts("1");
      } else
        puts("2");
    } else
      puts("0");
  }
  return 0;
}
