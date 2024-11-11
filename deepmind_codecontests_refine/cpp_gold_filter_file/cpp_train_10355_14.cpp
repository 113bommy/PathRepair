#include <bits/stdc++.h>
using namespace std;
int f(int h, int a, int d, int hm, int am, int dm) {
  if (a <= dm) return -1;
  int t = (int)ceil(1.0 * hm / (a - dm));
  if (am <= d) return 0;
  if (h > t * (am - d)) return 0;
  return t * (am - d) - h + 1;
}
int main() {
  int h, a, d, hm, am, dm, ch, ca, cd;
  scanf("%d%d%d%d%d%d%d%d%d", &h, &a, &d, &hm, &am, &dm, &ch, &ca, &cd);
  int ans = 0x3f3f3f3f;
  for (int i = 0; i + a <= 200; i++) {
    for (int j = 0; j + d <= 100; j++) {
      int t = f(h, a + i, d + j, hm, am, dm);
      if (t != -1) ans = min(ans, t * ch + i * ca + j * cd);
    }
  }
  printf("%d\n", ans);
  return 0;
}
