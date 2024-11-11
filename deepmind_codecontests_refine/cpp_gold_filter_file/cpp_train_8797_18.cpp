#include <bits/stdc++.h>
int main(void) {
  int x, t = 5, count = 0;
  scanf("%d", &x);
  while (t) {
    while (x - t >= 0) {
      count++;
      x = x - t;
    }
    t--;
  }
  printf("%d", count);
  return 0;
}
