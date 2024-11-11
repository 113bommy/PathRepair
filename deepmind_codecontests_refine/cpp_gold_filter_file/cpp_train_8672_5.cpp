#include <bits/stdc++.h>
using namespace std;
struct elem {
  double l, r, m, s;
  int lg, rg;
};
int x[500000];
double a[600000];
elem v[600000];
const int shift = (1 << 18);
void count(int x) {
  if (x == 1) {
    v[x].lg = 0;
    v[x].rg = shift - 1;
  }
  if (x >= shift) {
    v[x].l = min(a[x], 0.0);
    v[x].r = min(a[x], 0.0);
    v[x].m = min(a[x], 0.0);
    v[x].s = a[x];
  } else {
    int left = 2 * x;
    int right = 2 * x + 1;
    v[left].lg = v[x].lg;
    v[left].rg = (v[x].lg + x[v].rg) / 2;
    v[right].rg = v[x].rg;
    v[right].lg = (v[x].lg + x[v].rg) / 2 + 1;
    count(left);
    count(right);
    v[x].l = min(v[left].l, v[left].s + v[right].l);
    v[x].r = min(v[right].r, v[right].s + v[left].r);
    v[x].m = min(v[left].r + v[right].l, min(v[left].m, v[right].m));
    v[x].s = v[left].s + v[right].s;
  }
}
elem minim(int x, int L, int R) {
  if (L == v[x].lg && R == v[x].rg) return v[x];
  int left = 2 * x;
  int right = 2 * x + 1;
  if (R <= v[left].rg) return minim(left, L, R);
  if (L >= v[right].lg) return minim(right, L, R);
  elem res;
  elem rl = minim(left, L, v[left].rg);
  elem rr = minim(right, v[right].lg, R);
  res.l = min(rl.l, rl.s + rr.l);
  res.r = min(rr.r, rr.s + rl.r);
  res.m = min(rl.r + rr.l, min(rl.m, rr.m));
  res.s = rl.s + rr.s;
  return res;
}
int main() {
  for (int i = 0; i < 600000; i++) a[i] = 0;
  int n, m, c;
  scanf("%d%d%d", &n, &m, &c);
  for (int i = 0; i < n; i++) {
    scanf("%d", x + i);
  }
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    a[shift + i - 1] = -((x[i] - x[i - 1]) / 2.0 - c * (p / 100.0));
  }
  count(1);
  double ans = 0;
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    elem e = minim(1, a - 1, b - 2);
    ans += -e.m;
  }
  printf("%.10lf\n", ans);
  return 0;
}
