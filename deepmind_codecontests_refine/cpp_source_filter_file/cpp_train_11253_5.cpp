#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, minn, x, y;
  scanf("%d", &n);
  minn = INT_MAX;
  for (int i = 1; i <= n; i++) {
    int u = n / i;
    if (n % i) u++;
    if (minn > (u + i)) {
      minn = u + i;
      y = u;
      x = i;
    }
  }
  int h = n;
  while (y) {
    for (int i = h - x + 1; i <= h; i++) {
      if (i <= 0) break;
      printf("%d ", i);
    }
    y--;
    h -= x;
  }
  return 0;
}
