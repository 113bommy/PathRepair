#include <bits/stdc++.h>
int main() {
  int x, y, max, left, win = -1, turn = 0;
  scanf("%d%d", &x, &y);
  max = (x / 2 < y / 24) ? x / 2 : y / 24;
  x -= max * 2;
  y -= max * 24;
  left = 100 * x + 10 * y;
  while (win == -1) {
    if (!(left >= 220 && y >= 2))
      win = !turn;
    else {
      if (turn % 2 == 0) {
        if (x >= 2) {
          x -= 2;
          y -= 2;
        } else if (x == 1) {
          x -= 1;
          y -= 12;
        } else {
          y -= 22;
        }
      } else {
        if (y >= 22)
          y -= 22;
        else if (y >= 12) {
          x -= 1;
          y -= 12;
        } else {
          x -= 2;
          y -= 2;
        }
      }
      turn = (turn + 1) % 2;
      left -= 220;
    }
  }
  printf("%s\n", win % 2 == 0 ? "Ciel" : "Hanako");
  return 0;
}
