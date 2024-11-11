#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int loca[201000], Q[201000];
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; i++) scanf("%d", &loca[i]);
  int m;
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d", &Q[i]);
  int tot = 0;
  for (int i = 1; i <= m; i++) {
    double ans = 0;
    while (tot < n && loca[tot + 1] + 1 <= Q[i]) tot++;
    if (loca[tot] + 1 == Q[i] && loca[tot + 1] == Q[i])
      ans = PI;
    else if (loca[tot] + 1 == Q[i] || loca[tot + 1] == Q[i])
      ans = PI / 2;
    else {
      if (tot) ans = max(ans, atan((double)1 / (Q[i] - loca[tot] - 1)));
      if (tot < n) ans = max(ans, atan((double)1 / (loca[tot + 1] - Q[i])));
      int L = tot, R = tot + 1, x = Q[i];
      while (L && R <= n) {
        int disl = x - loca[L] - 1, disr = loca[R] - x;
        if ((R - L) % 20 == 0 &&
            2 * atan((double)1 / max(disl, disr)) < ans + 1e-8)
          break;
        if (abs(loca[R] - x - x + loca[L] + 1) < 2) {
          ans = max(ans, 2 * atan((double)1 / max(disl, disr)));
          break;
        }
        if (disr > disl)
          L--;
        else
          R++;
      }
    }
    printf("%.9lf\n", ans);
  }
  return 0;
}
