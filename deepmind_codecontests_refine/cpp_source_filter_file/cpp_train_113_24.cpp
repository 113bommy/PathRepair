#include <bits/stdc++.h>
using namespace std;
int ask(int a, int b) {
  printf("? %d %d\n", a, b);
  fflush(stdout);
  int flg;
  scanf("%d", &flg);
  return flg;
}
int ans_a = 0, ans_b = 0, a0 = 0, b0 = 0;
int seta(int mask) {
  ans_a |= mask;
  a0 |= mask;
}
int setb(int mask) {
  ans_b |= mask;
  b0 |= mask;
}
void f(int mask, int w) {
  if (mask == 0) {
    printf("! %d %d\n", ans_a, ans_b);
    fflush(stdout);
    return;
  }
  if (w == 0) {
    int x = ask(a0 | mask, b0);
    if (x == -1) {
      seta(mask);
      setb(mask);
    }
    f(mask >> 1, 0);
  } else {
    int x = ask(a0 | mask, b0);
    int y = ask(a0, b0 | mask);
    if (w == 1) {
      if (x * y == -1) {
        if (x == -1) {
          seta(mask);
          setb(mask);
        }
        f(mask >> 1, w);
      } else {
        seta(mask);
        f(mask >> 1, x);
      }
    } else {
      if (x * y == -1) {
        if (y == -1) {
          seta(mask);
          setb(mask);
        }
        f(mask >> 1, w);
      } else {
        setb(mask);
        f(mask >> 1, y);
      }
    }
  }
  return;
}
int main() {
  f(1 << 30, ask(0, 0));
  return 0;
}
