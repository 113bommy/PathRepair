#include <bits/stdc++.h>
const double PI = acos(-1.0);
using namespace std;
char s[10];
int getey(int ex) { return ex % 10 * 10 + (ex / 10) % 10; }
int getAns(int bx, int by, int ex, int ey) {
  if (ex < bx) ex += 24;
  return (ex - bx) * 60 + ey - by;
}
int main() {
  while (scanf("%s", s) == 1) {
    int bx, by, ex, ey;
    bx = (s[0] - '0') * 10 + s[1] - '0';
    by = (s[3] - '0') * 10 + s[4] - '0';
    ex = bx;
    while (1) {
      ey = getey(ex);
      if (ey <= 60 && ey >= 0) {
        if (ex == bx) {
          if (ey >= by) break;
        } else
          break;
      }
      ex = (ex + 1) % 24;
    }
    printf("%d\n", getAns(bx, by, ex, ey));
  }
  return 0;
}
