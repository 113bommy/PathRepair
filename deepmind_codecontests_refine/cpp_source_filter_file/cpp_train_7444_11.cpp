#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
  inline bool operator<(const point t) const {
    return 1LL * y * t.x > 1LL * x * t.y;
  }
  inline bool operator==(const point t) const {
    return (x == t.x) && (y == t.y);
  }
};
point p[120000];
point m;
double k1, k2, b2, y_;
int q[120000];
int i, n, t, tx, ty;
int main() {
  scanf("%d%d%d", &n, &m.x, &m.y);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &p[i].x, &p[i].y);
    tx = max(tx, p[i].x), ty = max(ty, p[i].y);
  }
  n++, p[n] = (point){tx, 0};
  n++, p[n] = (point){0, ty};
  sort(p + 1, p + n + 1);
  n = unique(p + 1, p + n + 1) - p - 1;
  for (i = 1; i <= n; i++) {
    while ((t > 1) &&
           ((1LL * (p[q[t]].x - p[q[t - 1]].x) * (p[i].y - p[q[t]].y)) >
            1LL * (p[q[t]].y - p[q[t - 1]].y) * (p[i].x - p[q[t]].x)))
      t--;
    t++, q[t] = i;
  }
  for (i = 1; i < t; i++)
    if ((!(m < p[q[i]])) && (m < p[q[i + 1]])) {
      if (i == 1) printf("%.15lf", 1.0 * m.y / ty);
      if (i == t - 1) printf("%.15lf", 1.0 * m.x / tx);
      if ((i > 1) && (i < t - 1)) {
        k1 = 1.0 * m.y / m.x;
        k2 = 1.0 * (p[q[i + 1]].y - p[q[i]].y) / (p[q[i + 1]].x - p[q[i]].x);
        b2 = p[q[i]].y - k2 * p[q[i]].x;
        y_ = -k1 / (k2 - k1) * b2;
        printf("%.15lf", m.y / y_);
      }
      return 0;
    }
}
