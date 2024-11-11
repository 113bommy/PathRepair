#include <bits/stdc++.h>
using namespace std;
int mm, dd, yy;
int leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int normal[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool f(int x, int y, int z) {
  if (y > 12 || y == 0) return 0;
  if (z % 4 == 0) {
    if (x == 0 || x > leap[y - 1]) return 0;
  } else {
    if (x == 0 || x > normal[y - 1]) return 0;
  }
  if (z + 18 > yy) return 0;
  if (z + 18 < yy) return 1;
  if (mm < y) return 0;
  if (mm > y) return 1;
  if (dd < x) return 0;
  return 1;
}
int main() {
  int x, y, z;
  scanf("%d.%d.%d", &dd, &mm, &yy);
  scanf("%d.%d.%d", &x, &y, &z);
  if (f(x, y, z) || f(x, z, y) || f(z, x, y) || f(z, y, x) || f(y, x, z) ||
      f(y, z, x))
    puts("YES");
  else
    puts("NO");
  return 0;
}
