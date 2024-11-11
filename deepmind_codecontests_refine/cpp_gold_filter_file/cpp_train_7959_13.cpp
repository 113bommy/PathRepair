#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int C, H;
  int p[4], x, y;
  scanf("%d", &C);
  for (int lx = 0; lx < 4; lx++) p[lx] = 2000000001;
  for (int lx = 0; lx < C; lx++) {
    scanf("%d %d", &x, &y);
    p[0] = min(p[0], x + y);
    p[1] = min(p[1], -x + y);
    p[2] = min(p[2], x - y);
    p[3] = min(p[3], -x - y);
  }
  scanf("%d", &H);
  int d = 2000000001, ih;
  for (int lx = 0; lx < H; lx++) {
    scanf("%d %d", &x, &y);
    int cal =
        max(max(x + y - p[0], -x + y - p[1]), max(x - y - p[2], -x - y - p[3]));
    if (cal < d) d = cal, ih = lx + 1;
  }
  printf("%d\n%d\n", d, ih);
  return 0;
}
