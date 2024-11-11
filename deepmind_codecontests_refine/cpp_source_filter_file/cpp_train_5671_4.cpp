#include <bits/stdc++.h>
using namespace std;
int n, m, dx, dy, x, y, f[1000005], freq[1000005], ans, z;
int main() {
  scanf("%d %d %d %d", &n, &m, &dx, &dy);
  int curx = 0, cury = 0;
  do {
    curx += dx;
    cury += dy;
    curx %= n;
    cury %= n;
    f[curx] = cury;
  } while (curx != 0);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    int k = (y - f[x] + n) % n;
    if (++freq[k] > ans) {
      ans = f[k];
      z = k;
    }
  }
  printf("0 %d\n", z);
  return 0;
}
