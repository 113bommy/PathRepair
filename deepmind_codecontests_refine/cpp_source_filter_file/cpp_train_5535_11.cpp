#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, m;
  int s, f, t;
  while (scanf("%d%d", &n, &m) != -1) {
    m--;
    for (i = 1; i <= n; i++) {
      scanf("%d%d%d", &s, &f, &t);
      if (s == f) {
        printf("%d\n", 0);
        continue;
      }
      s--;
      f--;
      int tm = t % (2 * m);
      int s2 = (2 * m - s) % (2 * m);
      if ((s2 + 2 * m - tm) % (2 * m) < (s + 2 * m - tm) % (2 * m)) s = s2;
      t = t + (s + 2 * m - tm) % (2 * m);
      int t2 = (2 * m - f) % (2 * m);
      int ans = min((f + 2 * m - s) % (2 * m), (t2 + 2 * m - s) % (2 * m)) + t;
      printf("%d\n", ans);
    }
  }
}
