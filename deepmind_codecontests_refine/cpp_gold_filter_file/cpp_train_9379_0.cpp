#include <bits/stdc++.h>
using namespace std;
typedef struct Res {
  int x, t;
  bool operator<(const Res &b) const {
    if (x < b.x || x == b.x && t < b.t) return 1;
    return 0;
  }
} Res;
Res X[500005], Y[500005];
int s1[500005], s2[500005], t1[222222], t2[222222], t3[222222], t4[222222];
int main(void) {
  int cnt, n, i, j, k, sum, x1, y1, x2, y2, now, c, d;
  scanf("%d", &n);
  cnt = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    t1[i] = x1, t2[i] = y1, t3[i] = x2, t4[i] = y2;
    X[++cnt].x = x1, X[cnt].t = 1;
    Y[cnt].x = y1, Y[cnt].t = 1;
    X[++cnt].x = x2 + 1, X[cnt].t = -1;
    Y[cnt].x = y2 + 1, Y[cnt].t = -1;
  }
  sort(X + 1, X + cnt + 1);
  sort(Y + 1, Y + cnt + 1);
  now = c = d = 0;
  for (i = 1; i <= cnt; i++) {
    now += X[i].t;
    if (now >= n - 1 && (X[i + 1].x != X[i].x || i == cnt)) s1[++c] = X[i].x;
  }
  now = 0;
  for (i = 1; i <= cnt; i++) {
    now += Y[i].t;
    if (now >= n - 1 && (Y[i + 1].x != Y[i].x || i == cnt)) s2[++d] = Y[i].x;
  }
  for (i = 1; i <= c; i++) {
    for (j = 1; j <= d; j++) {
      sum = 0;
      for (k = 1; k <= n; k++) {
        if (s1[i] >= t1[k] && s1[i] <= t3[k] && s2[j] >= t2[k] &&
            s2[j] <= t4[k])
          sum++;
      }
      if (sum >= n - 1) {
        printf("%d %d\n", s1[i], s2[j]);
        return 0;
      }
    }
  }
  return 0;
}
