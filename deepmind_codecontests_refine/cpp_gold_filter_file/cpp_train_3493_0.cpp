#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
double ff[N << 2], gg[N << 2];
double aa[N], bb[N];
double fun(double f1, double g1, double f2, double g2) {
  return f1 * f2 / (1 - (1 - f2) * g1);
}
double gun(double f1, double g1, double f2, double g2) {
  return g2 + (1 - g2) * g1 * f2 / (1 - (1 - f2) * g1);
}
void up(int o) {
  ff[o] = fun(ff[o << 1], gg[o << 1], ff[o << 1 | 1], gg[o << 1 | 1]);
  gg[o] = gun(ff[o << 1], gg[o << 1], ff[o << 1 | 1], gg[o << 1 | 1]);
}
void build(int l, int r, int o) {
  if (l == r) {
    ff[o] = gg[o] = aa[l] / bb[l];
    return;
  }
  build(l, (l + r) / 2, o << 1);
  build((l + r) / 2 + 1, r, o << 1 | 1);
  up(o);
}
int L, R;
double V;
void update(int l, int r, int o, int x) {
  if (l == r) {
    ff[o] = gg[o] = V;
    return;
  }
  if (x <= (l + r) / 2)
    update(l, (l + r) / 2, o << 1, x);
  else
    update((l + r) / 2 + 1, r, o << 1 | 1, x);
  up(o);
}
double f1, g1;
int fg;
void query(int l, int r, int o) {
  if (L <= l && r <= R) {
    if (!fg) {
      fg = 1;
      f1 = ff[o], g1 = gg[o];
      return;
    }
    double f2 = fun(f1, g1, ff[o], gg[o]);
    double g2 = gun(f1, g1, ff[o], gg[o]);
    f1 = f2, g1 = g2;
    return;
  }
  if (L <= (l + r) / 2) query(l, (l + r) / 2, o << 1);
  if (R > (l + r) / 2) query((l + r) / 2 + 1, r, o << 1 | 1);
}
int main() {
  int n, q;
  while (scanf("%d%d", &n, &q) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf", &aa[i], &bb[i]);
    }
    build(0, n - 1, 1);
    for (int i = 0; i < q; i++) {
      int op, id, l, r;
      scanf("%d", &op);
      if (op == 1) {
        scanf("%d%d%d", &id, &l, &r);
        V = (double)l / r;
        update(0, n - 1, 1, id - 1);
      } else {
        scanf("%d%d", &L, &R);
        L--, R--;
        fg = 0;
        query(0, n - 1, 1);
        printf("%.10lf\n", f1);
      }
    }
  }
  return 0;
}
