#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
struct gg {
  int x, y, l, r, ma, lazy;
};
gg w[N << 2];
int n, b, f, p[N], xx[N], pi, l;
void build(int x, int y, int o) {
  w[o].x = x;
  w[o].y = y;
  w[o].l = w[o].r = w[o].ma = y - x + 1;
  w[o].lazy = -1;
  if (x == y) return;
  int mid = (x + y) >> 1;
  build(x, mid, o << 1);
  build(mid + 1, y, o << 1 | 1);
}
void pd(int o) {
  if (w[o].lazy == -1) return;
  w[o << 1].lazy = w[o << 1 | 1].lazy = w[o].lazy;
  int k = w[o].lazy;
  w[o << 1].l = w[o << 1].r = w[o << 1].ma =
      (k ^ 1) * (w[o << 1].y - w[o << 1].x + 1);
  w[o << 1 | 1].l = w[o << 1 | 1].r = w[o << 1 | 1].ma =
      (k ^ 1) * (w[o << 1 | 1].y - w[o << 1 | 1].x + 1);
  w[o].lazy = -1;
}
void hbing(int o) {
  w[o].l = w[o << 1].l;
  w[o].r = w[o << 1 | 1].r;
  if (w[o << 1].l == w[o << 1].y - w[o << 1].x + 1) w[o].l += w[o << 1 | 1].l;
  if (w[o << 1 | 1].r == w[o << 1 | 1].y - w[o << 1 | 1].x + 1)
    w[o].r += w[o << 1].r;
  w[o].ma =
      max(max(w[o << 1].ma, w[o << 1 | 1].ma), w[o << 1].r + w[o << 1 | 1].l);
}
int ask(int x, int o) {
  pd(o);
  hbing(o);
  if (w[o << 1].ma >= x) return ask(x, o << 1);
  if (w[o << 1].r + w[o << 1 | 1].l >= x) return w[o << 1].y - w[o << 1].r + 1;
  if (w[o << 1 | 1].ma >= x) return ask(x, o << 1 | 1);
  return -1;
}
void update(int x, int y, int o, int v) {
  if (x <= w[o].x && w[o].y <= y) {
    w[o].lazy = v;
    w[o].l = w[o].r = w[o].ma = (v ^ 1) * (w[o].y - w[o].x + 1);
    return;
  }
  pd(o);
  int mid = (w[o].x + w[o].y) / 2;
  if (y <= mid)
    update(x, y, o << 1, v);
  else if (x >= mid + 1)
    update(x, y, o << 1 | 1, v);
  else {
    update(x, mid, o << 1, v);
    update(mid + 1, y, o << 1 | 1, v);
  }
  hbing(o);
}
int main() {
  scanf("%d%d%d", &l, &b, &f);
  build(1, l + 400, 1);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &pi, &xx[i]);
    if (pi == 1) {
      p[i] = ask(xx[i] + b + f, 1);
      if (p[i] + b + xx[i] - 1 > l) p[i] = -1;
      if (p[i] != -1) update(p[i] + b, p[i] + xx[i] + b - 1, 1, 1);
      if (p[i] == -1)
        printf("-1\n");
      else
        printf("%d\n", p[i] - 1);
    } else {
      int j = xx[i];
      if (p[j] != -1 && p[j] != 0) update(p[j] + b, p[j] + xx[j] + b - 1, 1, 0);
    }
  }
  return 0;
}
