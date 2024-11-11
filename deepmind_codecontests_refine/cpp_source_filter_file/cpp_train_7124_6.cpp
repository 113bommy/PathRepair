#include <bits/stdc++.h>
using namespace std;
struct note {
  long double thi;
  int add;
} p[100005];
int n, d, sum, tot;
long double sqr(long double x) { return x * x; }
long double dist(long double x, long double y, long double xx, long double yy) {
  return sqrt(sqr(x - xx) + sqr(y - yy));
}
long double get(long double A, long double B, long double C) {
  return acos((sqr(A) + sqr(C) - sqr(B)) / (2 * A * C));
}
bool cmp(note i, note j) {
  return j.thi - i.thi > 1e-10 || fabs(j.thi - i.thi) < 1e-10 && i.add > j.add;
}
int main() {
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; i++) {
    long double x, y, r;
    cin >> x >> y >> r;
    long double tmp = atan2(y, x), dis = dist(0, 0, x, y);
    int fr = ceil((dis - r - 1e-10) / d), to = floor((dis + r + 1e-10) / d);
    for (int j = fr; j <= to; j++) {
      long double thi = get((long double)j * d, dis, r);
      long double r1 = tmp - thi, r2 = tmp + thi;
      if (r1 <= -acos(-1)) {
        r1 += 2 * acos(-1);
        ++sum;
      } else if (r2 >= acos(-1)) {
        r2 -= 2 * acos(-1);
        ++sum;
      }
      p[++tot].thi = r1;
      p[tot].add = 1;
      p[++tot].thi = r2;
      p[tot].add = -1;
    }
  }
  sort(p + 1, p + tot + 1, cmp);
  int ans = 0;
  for (int i = 1; i <= tot; i++) {
    sum += p[i].add;
    ans = max(ans, sum);
  }
  printf("%d", ans);
  return 0;
}
