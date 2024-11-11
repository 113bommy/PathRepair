#include <bits/stdc++.h>
static int min(int a, int b) { return a < b ? a : b; }
int main(void) {
  int n, m, x, y, k, i;
  long long ts = 0;
  scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
  for (i = 0; i < k; ++i) {
    int dx, dy, s, lx, ly;
    scanf("%d %d", &dx, &dy);
    lx = dx < 0 ? 1 : n;
    ly = dy < 0 ? 1 : m;
    s = min(dx == 0 ? 1000000000 : (lx - x) / dx,
            dy == 0 ? 1000000000 : (ly - y) / dy);
    x += s * dx;
    y += s * dy;
    ts += s;
  }
  printf("%d\n", ts);
  exit(EXIT_SUCCESS);
}
