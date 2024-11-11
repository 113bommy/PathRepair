#include <bits/stdc++.h>
using namespace std;
int cl(int x, int y) {
  if (x % y == 0) return x / y;
  return x / y + 1;
}
int main() {
  int r, c;
  scanf("%d%d", &r, &c);
  int z = 0, mx = 0;
  mx = c * cl(r, 3);
  mx = max(mx, r * cl(c, 3));
  mx = max(mx, r * (c / 2) + (c % 2) * ((r / 2) + r % 2));
  mx = max(mx, c * (r / 2) + (r % 2) * ((c / 2) + c % 2));
  if (c == 2) mx = max(mx, 2 * c * (r / 4) + c * min(2, r % 4));
  if (r == 2) mx = max(mx, 2 * r * (c / 4) + r * min(2, c % 4));
  printf("%d\n", mx);
  scanf("%*d");
}
