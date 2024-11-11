#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, x, y, z;
  scanf("%d%d%d%d%d%d", &a, &b, &c, &x, &y, &z);
  bool can = true;
  int more = 0;
  int less = 0;
  if (a > z)
    more += (a - x) / 2;
  else
    less += x - a;
  if (b > y)
    more += (b - y) / 2;
  else
    less += y - b;
  if (c > z)
    more += (c - z) / 2;
  else
    less += z - c;
  if (more >= less)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
