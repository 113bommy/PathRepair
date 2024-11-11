#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int MAXX, MAXY, MAYX, MAYY, x, y, n;
  char s[10];
  scanf("%d", &n);
  MAXX = -1;
  MAXY = -1;
  MAYY = -1;
  MAYX = -1;
  while (n--) {
    scanf("%s %d %d", s, &x, &y);
    if (x > y) swap(x, y);
    if (s[0] == '+') {
      if (MAXX < x) {
        MAXX = x;
        MAXY = y;
      }
      if (MAXX == x) {
        if (MAXY < y) {
          MAXX = x;
          MAXY = y;
        }
      }
      if (MAYY < y) {
        MAYY = y;
        MAYX = x;
      }
      if (MAXY == y) {
        if (MAYX < x) {
          MAYX = x;
          MAYY = y;
        }
      }
    } else {
      if (x >= MAXX && y >= MAXY && x >= MAYX && y >= MAYY) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
  }
}
