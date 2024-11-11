#include <bits/stdc++.h>
using namespace std;
int n;
struct pr {
  int x, y;
} u, d, l, r, ul, ur, dl, dr;
int main() {
  scanf("%d%d%d", &n, &u.x, &u.y);
  ul = ur = dl = dr = d = l = r = u;
  for (int i = (2); i <= (n); ++i) {
    pr x;
    scanf("%d%d", &x.x, &x.y);
    if (x.x < u.x) u = x;
    if (x.x > d.x) d = x;
    if (x.y < l.y) l = x;
    if (x.y > r.y) r = x;
    if (x.x + x.y < ul.x + ul.y) ul = x;
    if (x.x + x.y > dr.x + dr.y) dr = x;
    if (x.x - x.y < ur.x - ur.y) ur = x;
    if (x.x - x.y > dl.x - dl.y) dl = x;
  }
  printf("%d", max(max(d.x + r.y - ul.x - ul.y, d.x - l.y - ur.x + ur.y),
                   max(dl.x - dl.y - u.x + r.y, dr.x + dr.y - u.x - l.y)) *
                   2);
  for (int i = (4); i <= (n); ++i) printf(" %d", (d.x - u.x + r.y - l.y) * 2);
}
