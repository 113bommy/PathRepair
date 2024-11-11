#include <bits/stdc++.h>
using namespace std;
int flag[200];
int main() {
  int x1, x2, a, b;
  while (scanf("%d %d %d %d", &x1, &x2, &a, &b) == 4) {
    bool now = 0;
    if (x1 > x2) {
      swap(x1, x2);
      swap(a, b);
      a = -a;
      b = -b;
      now = 1;
    }
    int len = x2 - x1;
    if (a <= 0) {
      if (b >= len) {
        puts("FIRST");
        int ans;
        if (now)
          ans = x1;
        else
          ans = x2;
        printf("%d\n", ans);
      } else {
        puts("DRAW");
      }
    } else {
      int res = len % (a + b);
      if (res == 0) {
        puts("SECOND");
      } else if (res >= a && res <= b) {
        puts("FIRST");
        if (flag) {
          printf("%d\n", x2 - res);
        } else {
          printf("%d\n", x1 + res);
        }
      } else {
        puts("DRAW");
      }
    }
  }
  return 0;
}
