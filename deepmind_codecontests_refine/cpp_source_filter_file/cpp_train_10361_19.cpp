#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int MAX = 2e5 + 50;
int t;
double r, h, v[MAX], s[MAX];
struct node {
  int l, r;
  double ans;
} xds[MAX * 4];
void pushup(int x) { xds[x].ans = max(xds[x << 1].ans, xds[x << 1 | 1].ans); }
void js(int l, int r, int x) {
  int m = (l + r) / 2;
  xds[x].l = l;
  xds[x].r = r;
  xds[x].ans = 0;
  if (l == r) return;
  js(l, m, x << 1);
  js(m + 1, r, x << 1 | 1);
}
void xg(int pos, double val, int x) {
  int m = (xds[x].l + xds[x].r) / 2;
  if (pos == xds[x].l && pos == xds[x].r) {
    xds[x].ans = val;
    return;
  }
  if (pos <= m)
    xg(pos, val, x << 1);
  else
    xg(pos, val, x << 1 | 1);
  pushup(x);
}
double cx(int L, int R, int x) {
  int m = (xds[x].l + xds[x].r) / 2;
  if (L == xds[x].l && R == xds[x].r) return xds[x].ans;
  if (R <= m) return cx(L, R, x << 1);
  if (L > m) return cx(L, R, x << 1 | 1);
  return max(cx(L, m, x << 1), cx(m + 1, R, x << 1 | 1));
}
int main() {
  int i, pos;
  double val;
  while (~scanf("%d", &t)) {
    for (i = 0; i < t; i++) {
      scanf("%ld%ld", &r, &h);
      v[i] = s[i] = r * r * h;
    }
    sort(s, s + t);
    js(0, t, 1);
    for (i = 0; i < t; i++) {
      pos = lower_bound(s, s + t, v[i]) - s;
      if (pos == 0)
        val = v[i];
      else
        val = cx(0, pos - 1, 1) + v[i];
      xg(pos, val, 1);
    }
    printf("%.12lf\n", cx(0, t, 1) * pi);
  }
  return 0;
}
