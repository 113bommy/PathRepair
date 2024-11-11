#include <bits/stdc++.h>
int main() {
  int x, y;
  scanf("%d%d", &x, &y);
  int c = 1;
  while (x >= 0 && y >= 0) {
    if (c % 2 != 0) {
      if (x >= 2 && y >= 2) {
        x = x - 2;
        y = y - 2;
        c++;
      } else if (x >= 1 && y >= 12) {
        x = x - 1;
        y = y - 12;
        c++;
      } else if (x == 0 && y >= 22) {
        y = y - 22;
        c++;
      } else {
        printf("Hanako");
        exit(0);
      }
    } else {
      if (y >= 22) {
        y = y - 22;
        c++;
      } else if (x >= 1 && y >= 12) {
        x = x - 1;
        y = y - 12;
        c++;
      } else if (x >= 2 && y >= 2) {
        x = x - 2;
        y = y - 2;
        c++;
      } else {
        printf("Ciel");
        exit(0);
      }
    }
  }
}
