#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int x, y, z;
int main() {
  scanf("%d%d%d%d%d%d", &a, &b, &c, &x, &y, &z);
  int x1 = a - x, x2 = b - y, x3 = c - z;
  int o1, o2, o3, i1, i2, i3;
  o1 = o2 = o3 = i1 = i2 = i3 = 0;
  if (x1 > 0) {
    if (x1 % 2 == 0)
      o1 = x1 / 2;
    else {
      o1 = x1 / 2 + 1;
      i1 = 1;
    }
  } else {
    x1 = -x1;
    i1 += x1;
    x1 = -x1;
  }
  if (x2 > 0) {
    if (x2 % 2 == 0)
      o2 = x2 / 2;
    else {
      o2 = x2 / 2 + 1;
      i2 = 1;
    }
  } else {
    x2 = -x2;
    i2 += x2;
    x2 = -x2;
  }
  if (x3 > 0) {
    if (x3 % 2 == 0)
      o3 = x3 / 2;
    else {
      o3 = x3 / 2 + 1;
      i3 = 1;
    }
  } else {
    x3 = -x3;
    i3 += x3;
    x3 = -x3;
  }
  if (x1 + x2 + x3 != i1 + i2 + i3) {
    printf("No\n");
    return 0;
  } else
    printf("Yes\n");
  return 0;
}
