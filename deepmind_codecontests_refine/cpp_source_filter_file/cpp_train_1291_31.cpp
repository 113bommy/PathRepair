#include <bits/stdc++.h>
int main(void) {
  int h, r;
  while (scanf("%d%d", &r, &h) != -1) {
    int ans = 0;
    int a = h % r;
    int b = h / r;
    int cnt = 0;
    if (2 * a > r) {
      cnt = 2;
      if (2 * a >= r * 1.732) {
        cnt++;
      }
    } else {
      cnt = 1;
    }
    ans = 2 * b + cnt;
    printf("%d\n", ans);
  }
  return 0;
}
