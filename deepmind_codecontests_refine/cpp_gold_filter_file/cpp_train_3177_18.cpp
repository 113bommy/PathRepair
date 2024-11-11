#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  int x, y, z;
  scanf("%d %d %d", &x, &y, &z);
  while (a - 2 >= x) {
    if (b < y)
      b += 1;
    else
      c += 1;
    a -= 2;
  }
  while (b - 2 >= y) {
    if (a < x)
      a += 1;
    else
      c += 1;
    b -= 2;
  }
  while (c - 2 >= z) {
    if (a < x)
      a += 1;
    else
      b += 1;
    c -= 2;
  }
  puts(a >= x && b >= y && c >= z ? "Yes" : "No");
  return 0;
}
