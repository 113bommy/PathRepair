#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100007];
pair<int, int> b[100007];
pair<int, int> p, r;
double t, q, x, y, w;
int fl = 1;
int main() {
  int n;
  int d1, d2, res = 0;
  scanf("%d", &n);
  ;
  scanf("%d", &d1);
  ;
  scanf("%d", &d2);
  ;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i].first);
    ;
    scanf("%d", &a[i].second);
    ;
    scanf("%d", &b[i].first);
    ;
    scanf("%d", &b[i].second);
    ;
  }
  for (int i = 1; i < n; ++i) {
    p.first = b[i + 1].first - a[i + 1].first;
    p.second = b[i + 1].second - a[i + 1].second;
    r.first = b[i].first - a[i].first;
    r.second = b[i].second - a[i].second;
    t = 2.0 * r.first * (p.first - r.first);
    t += 2.0 * r.second * (p.second - r.second);
    q = 2.0 * (r.first - p.first) * (r.first - p.first);
    q += 2.0 * (r.second - p.second) * (r.second - p.second);
    t = t / q;
    t = -t;
    x = r.first * r.first + r.second * r.second;
    y = p.first * p.first + p.second * p.second;
    if (t <= 0.0 || t >= 1.0) {
      if (y < 1.0 * d1 * d1 && fl == 1) {
        res += 1;
        fl = 0;
      } else if (y > 1.0 * d2 * d2 && fl == 0)
        fl = 1;
    } else {
      w = (t * (p.first - r.first) + r.first) *
          (t * (p.first - r.first) + r.first);
      w += (t * (p.second - r.second) + r.second) *
           (t * (p.second - r.second) + r.second);
      if (w < x) {
        if (w < 1.0 * d1 * d1 && fl == 1) {
          res += 1;
          fl = 0;
        }
        if (y > 1.0 * d2 * d2 && fl == 0) fl = 1;
      } else {
        if (w > 1.0 * d2 * d2 && fl == 0) fl = 1;
        if (y < 1.0 * d1 * d1 && fl == 1) {
          res += 1;
          fl = 0;
        }
      }
    }
  }
  printf("%d\n", res);
  return 0;
}
