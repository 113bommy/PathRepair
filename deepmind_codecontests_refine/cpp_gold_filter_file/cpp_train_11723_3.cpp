#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
struct hehe {
  double l, r;
  int bj;
} e[200005];
struct haha {
  int x, v, t;
} hmz[200005];
int n, s;
int cnt;
bool fansile(double l, double r) {
  if (l > r) return false;
  if (l > 1e6) return false;
  if (r > 1e6) r = 1e6;
  long long ll = l, rr = r;
  if (ll < rr) return true;
  if (fabs(l - ll) <= 1e-10) return true;
  if (fabs(r - rr) <= 1e-10) return true;
  return false;
}
bool xydy(double x) {
  if (fabs(x) <= 1e-9) return true;
  if (x < 0) return true;
  return false;
}
bool cmp(const hehe &x, const hehe &y) { return x.l < y.l; }
bool pd(double shijian) {
  bool zuobj = false, youbj = false;
  bool zuocz = false, youcz = false;
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (hmz[i].t == 1) {
      if (xydy((double)hmz[i].x / hmz[i].v - shijian)) {
        zuobj = true;
        continue;
      }
      double l, r;
      l = hmz[i].x;
      r = ((double)shijian * ((double)s * s - (double)hmz[i].v * hmz[i].v) +
           (double)hmz[i].v * hmz[i].x) /
          (double)s;
      if (fansile(l, r)) {
        zuocz = true;
        cnt++;
        e[cnt].bj = 1;
        e[cnt].l = l;
        e[cnt].r = r;
      }
    } else {
      double d = (double)1e6 - hmz[i].x;
      if (xydy(d / hmz[i].v - shijian)) {
        youbj = true;
        continue;
      }
      double l, r;
      l = 1e6 -
          (((double)shijian * ((double)s * s - (double)hmz[i].v * hmz[i].v) +
            (double)hmz[i].v * d) /
           (double)s);
      r = (double)hmz[i].x;
      if (fansile(l, r)) {
        youcz = true;
        cnt++;
        e[cnt].bj = 2;
        e[cnt].l = l;
        e[cnt].r = r;
      }
    }
  }
  if (zuobj && youbj) return true;
  if (zuobj && youcz) return true;
  if (zuocz && youbj) return true;
  if (!zuobj && !zuocz) return false;
  if (!youbj && !youcz) return false;
  sort(e + 1, e + cnt + 1, cmp);
  for (int i = 1; i <= cnt - 1; i++)
    if (e[i].bj != e[i + 1].bj && xydy(e[i].l - e[i + 1].l) &&
        xydy(e[i + 1].l - e[i].r) &&
        fansile(e[i + 1].l, min(e[i + 1].r, e[i].r)))
      return true;
  return false;
}
void solve() {
  double l = 0, r = 1e6;
  double mid;
  while (l + eps < r) {
    mid = (l + r) / 2;
    if (pd(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.9lf\n", l);
}
int main() {
  scanf("%d%d", &n, &s);
  for (int i = 1; i <= n; i++) scanf("%d%d%d", &hmz[i].x, &hmz[i].v, &hmz[i].t);
  solve();
  return 0;
}
