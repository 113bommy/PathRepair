#include <bits/stdc++.h>
using namespace std;
int main() {
  long x, y;
  scanf("%ld%ld", &x, &y);
  bool p1 = false, p2 = false;
  while (1) {
    p1 = false;
    p2 = false;
    if (x >= 2 && y >= 2) {
      x -= 2;
      y -= 2;
      p1 = true;
    } else if (x == 1 && y >= 12) {
      x -= 1;
      y -= 12;
      p1 = true;
    } else if (y >= 22) {
      y -= 22;
      p1 = true;
    }
    if (!p1) {
      printf("Hanako\n");
      return 0;
    }
    if (y >= 22) {
      y -= 22;
      p2 = true;
    } else if (x >= 1 && y >= 12) {
      x -= 1;
      y -= 12;
      p2 = true;
    } else if (x >= 2 && y >= 2) {
      x -= 2;
      y -= 2;
      p2 = true;
    }
    if (!p2) {
      printf("Ciel\n");
      return 0;
    }
    if (!(p1 && p2)) break;
  }
  if (p1) {
    printf("Ciel\n");
  } else
    printf("Hanako\n");
  return 0;
}
