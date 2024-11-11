#include <bits/stdc++.h>
using namespace std;
const int mn = 1e5 + 10;
long long x[mn], y[mn], d[mn];
inline long double sq(long double x) { return x * x; }
inline long long sq(long long x) { return x * x; }
long double eps = 1e-8;
long double i1x, i1y, i2x, i2y;
vector<pair<long long, long long> > ans;
void idk(long long xx, long long yy, int i, int n) {
  if (sq(xx - x[0]) + sq(yy - y[0]) != d[i]) return;
  vector<long long> v;
  for (int j = 0; j < n; j++) v.push_back(sq(xx - x[j]) + sq(yy - y[j]));
  sort(v.begin(), v.end());
  for (int j = 0; j < n; j++)
    if (d[j] != v[j]) return;
  ans.push_back({xx, yy});
}
void intersect(long double x1, long double y1, long double r1, long double x2,
               long double y2, long double r2, long double r12, long double r22,
               int i, int n) {
  long double dis = sqrt(sq(x1 - x2) + sq(y1 - y2));
  long double dis2 = sq(x1 - x2) + sq(y1 - y2);
  if (dis > r1 + r2 + eps) return;
  long double t = atan2(y2 - y1, x2 - x1);
  long double p = (r12 + dis2 - r22) / 2 / r1 / dis;
  if (p > 1) p = 1;
  if (p < -1) p = -1;
  long double k = acos(p);
  i1x = x1 + r1 * cos(t + k);
  i1y = y1 + r1 * sin(t + k);
  i2x = x1 + r1 * cos(t - k);
  i2y = y1 + r1 * sin(t - k);
  if (fabs(i1x) + fabs(i1y) < 1e9)
    for (int j = -6; j <= 6; j++) {
      for (int k = -6; k <= 6; k++) {
        idk((long long)i1x + j, (long long)i1y + k, i, n);
      }
    }
  if (fabs(i2x) + fabs(i2y) < 1e9)
    for (int j = -6; j <= 6; j++) {
      for (int k = -6; k <= 6; k++) {
        idk((long long)i2x + j, (long long)i2y + k, i, n);
      }
    }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld%lld", x + i, y + i);
  long double sx = 0, sy = 0, sxy = 0;
  for (int i = 0; i < n; i++) sx += x[i], sy += y[i];
  long double cx = sx / n, cy = sy / n;
  for (int i = 0; i < n; i++) sxy += sq(cx - x[i]) + sq(cy - y[i]);
  int m;
  scanf("%d", &m);
  while (m--) {
    ans.clear();
    for (int i = 0; i < n; i++) scanf("%lld", d + i);
    long long h1 = 0, h2 = 0;
    for (int i = 0; i < n; i++)
      h1 += d[i] / 1000000000, h2 += d[i] % 1000000000;
    long double r2 = (((long double)h1) * 1e9 + ((long double)(h2)-sxy)) / n;
    for (int i = 0; i < n; i++) {
      if (i && d[i] == d[i - 1]) continue;
      intersect(cx, cy, sqrt(r2), x[0], y[0], sqrt(d[i]), d[i], r2, i, n);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    printf("%d", ans.size());
    for (auto hail : ans) printf(" %lld %lld", hail.first, hail.second);
    printf("\n");
  }
}
