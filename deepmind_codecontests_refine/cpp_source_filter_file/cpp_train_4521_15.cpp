#include <bits/stdc++.h>
struct pt {
  double x, y;
} p[305], q[305];
int k, n, cnt, cnt2;
double y[301][302], ans[301], prod[305];
double area() {
  double ans = 0;
  for (int i = 1; i <= cnt; i++)
    ans += (p[i].x * p[i % cnt + 1].y - p[i].y * p[i % cnt + 1].x) / 2;
  return ans;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k + 1; j++) scanf("%lf", &y[i][j]);
  for (int t = 1; t <= k; t++) {
    cnt = 4;
    p[1].x = 0, p[1].y = 1001, p[2].x = 0, p[2].y = 0;
    p[3].x = 1, p[3].y = 0, p[4].x = 1, p[4].y = 1001;
    double s = area(), tmp;
    for (int l = 1; l <= n; l++) {
      cnt2 = 0;
      for (int i = 1; i <= cnt; i++) {
        double x1 = 1 - p[i].x, x2 = p[i].x, y1 = p[i].y - y[l][t],
               y2 = y[l][t + 1] - p[i].y;
        prod[i] = x1 * y2 - x2 * y1;
      }
      for (int i = 1; i <= cnt; i++) {
        if (prod[i] < 0) {
          if (i > 1)
            if (prod[i - 1] > 0) {
              q[++cnt2].x = (p[i - 1].x * prod[i] - p[i].x * prod[i - 1]) /
                            (prod[i] - prod[i - 1]);
              q[cnt2].y = (p[i - 1].y * prod[i] - p[i].y * prod[i - 1]) /
                          (prod[i] - prod[i - 1]);
            }
          q[++cnt2] = p[i];
        } else if (prod[i - 1] < 0) {
          q[++cnt2].x = (p[i - 1].x * prod[i] - p[i].x * prod[i - 1]) /
                        (prod[i] - prod[i - 1]);
          q[cnt2].y = (p[i - 1].y * prod[i] - p[i].y * prod[i - 1]) /
                      (prod[i] - prod[i - 1]);
        }
      }
      cnt = cnt2;
      for (int i = 1; i <= cnt2; i++) p[i] = q[i];
      tmp = area();
      ans[l] += s - tmp;
      s = tmp;
    }
  }
  for (int i = 1; i <= n; i++) printf("%lf\n", ans[i]);
}
