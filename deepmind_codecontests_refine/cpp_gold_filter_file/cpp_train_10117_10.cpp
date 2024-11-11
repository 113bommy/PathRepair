#include <bits/stdc++.h>
using namespace std;
int ans[707 << 1][707 << 1], a[(1000000 + 500)];
int q;
int main() {
  int mx = 0;
  scanf("%d", &q);
  while (q--) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    if (t == 1) {
      a[x] += y;
      mx = max(mx, x);
      for (int i = 1; i <= 707; ++i) ans[i][x % i] += y;
    } else {
      if (x <= 707) {
        printf("%d\n", ans[x][y]);
        continue;
      }
      int ret = 0;
      for (int i = y; i <= mx; i += x) ret += a[i];
      printf("%d\n", ret);
    }
  }
  return 0;
}
