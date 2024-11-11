#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, x, y, sub = 0;
  scanf("%d %d %d", &a, &x, &y);
  if (y % a == 0 || abs(x) >= a) {
    printf("-1\n");
    return 0;
  }
  int lvl = y / a + 1;
  if (lvl & 1 == 0 || lvl == 1) {
    if (abs(x) >= double(a) / 2.0) {
      printf("-1\n");
      return 0;
    }
  }
  if (lvl & 1 && lvl != 1) {
    if (x == 0) {
      printf("-1\n");
      return 0;
    }
    if (x > 0)
      sub = 0;
    else
      sub = 1;
    if (lvl == 1) sub = 0;
  }
  int res = (lvl - 1) / 2 + lvl - sub;
  printf("%d\n", res);
  return 0;
}
