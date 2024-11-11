#include <bits/stdc++.h>
using namespace std;
bool totC(int x1, int y1, int r1, int x2, int y2, int r2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r1 - r2) * (r1 - r2);
}
bool apart(int x1, int y1, int r1, int x2, int y2, int r2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) >= (r1 + r2) * (r1 + r2);
}
int main() {
  int x1, y1, r11, r12;
  int x2, y2, r21, r22;
  int res = 0;
  scanf("%d%d%d%d", &x1, &y1, &r11, &r12);
  scanf("%d%d%d%d", &x2, &y2, &r21, &r22);
  if (r11 >= r22 && totC(x1, y1, r11, x2, y2, r22) ||
      r21 >= r11 && totC(x2, y2, r21, x1, y1, r11) ||
      apart(x1, y1, r11, x2, y2, r22))
    res++;
  if (r11 >= r21 && totC(x1, y1, r11, x2, y2, r21) ||
      r21 >= r12 && totC(x2, y2, r21, x1, y1, r12) ||
      apart(x2, y2, r11, x1, y1, r12))
    res++;
  if (r12 >= r22 && totC(x1, y1, r12, x2, y2, r22) ||
      r21 >= r12 && totC(x2, y2, r21, x1, y1, r12) ||
      apart(x1, y1, r12, x2, y2, r22))
    res++;
  if (r22 >= r12 && totC(x2, y2, r22, x1, y1, r12) ||
      r11 >= r22 && totC(x1, y1, r11, x2, y2, r22) ||
      apart(x2, y2, r22, x1, y1, r12))
    res++;
  printf("%d\n", res);
  return 0;
}
