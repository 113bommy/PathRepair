#include <bits/stdc++.h>
int time_set(int h, int m, int prev) {
  if (m > prev) {
    m -= prev;
    return h * 100 + m;
  } else {
    m += 60;
    m -= prev;
    h += 24;
    h -= 1;
    h %= 24;
    return h * 100 + m;
  }
}
int main() {
  int x;
  scanf("%d", &x);
  int h, m;
  scanf("%d %d", &h, &m);
  if (h / 10 == 7 || h % 10 == 7 || m / 10 == 7 || m % 10 == 7) {
    printf("0");
    return 0;
  }
  for (int i = 1;; i++) {
    int time = time_set(h, m, x);
    h = time / 100;
    m = time % 100;
    if (h / 10 == 7 || h % 10 == 7 || m / 10 == 7 || m % 10 == 7) {
      printf("%d", i);
      return 0;
    }
  }
}
