#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct tt {
  int v, p, q;
} z[N], *(sp[N]), *(sv[N]);
bool cmpp(struct tt* const(&a), struct tt* const(&b)) { return a->p < b->p; }
bool cmpv(struct tt* const(&a), struct tt* const(&b)) { return a->v < b->v; }
struct ww {
  int x, u, q;
} a[N * 3 * 3];
void f(int id, int p, int q, int pp, int qq, int c) {
  if (p == pp && q == qq) {
    a[id].x += c;
    a[id].u += c;
    if (!a[id].q) {
      a[id].q = p;
    }
    return;
  }
  int now1 = id + id + 1;
  int now2 = now1 + 1;
  int mid = (p + q) / 2;
  if (a[id].u) {
    a[now1].x += a[id].u;
    a[now1].u += a[id].u;
    a[now2].x += a[id].u;
    a[now2].u += a[id].u;
    a[id].u = 0;
  }
  if (qq <= mid) {
    f(now1, p, mid, pp, qq, c);
  } else if (pp > mid) {
    f(now2, mid + 1, q, pp, qq, c);
  } else {
    f(now1, p, mid, pp, mid, c);
    f(now2, mid + 1, q, mid + 1, qq, c);
  }
  if (a[now1].x > a[now2].x) {
    a[id].x = a[now1].x;
    a[id].q = a[now1].q;
  } else {
    a[id].x = a[now2].x;
    a[id].q = a[now2].q;
  }
}
int main() {
  int n = 0, in = 0, ax = 0, i = 0, kp = 0, kv = 0, ans = 0, pp = 0, qq = 0;
  while (scanf("%d", &n) == 1) {
    in = 300000 + 1;
    ax = 1 - 1;
    for (i = 0; i < n; i++) {
      scanf("%d%d%d", &z[i].p, &z[i].v, &z[i].q);
      sp[i] = &z[i];
      sv[i] = &z[i];
      if (z[i].q > ax) {
        ax = z[i].q;
      }
      if (z[i].q < in) {
        in = z[i].q;
      }
      if (z[i].v > ax) {
        ax = z[i].v;
      }
      if (z[i].v < in) {
        in = z[i].v;
      }
    }
    sort(sp, sp + n, cmpp);
    sort(sv, sv + n, cmpv);
    kp = 0;
    kv = 0;
    ans = 0;
    memset(a, 0, sizeof(a));
    for (i = sp[0]->p; i <= sv[n - 1]->v; i++) {
      while (kv < n && sv[kv]->v < i) {
        f(0, in, ax, sv[kv]->v, sv[kv]->q, -1);
        kv++;
      }
      while (kp < n && sp[kp]->p <= i) {
        f(0, in, ax, sp[kp]->v, sp[kp]->q, 1);
        kp++;
      }
      if (a[0].x > ans) {
        ans = a[0].x;
        pp = i;
        qq = a[0].q;
      }
    }
    printf("%d\n", ans);
    for (i = 0; i < n; i++) {
      if (z[i].p <= pp && qq <= z[i].q && pp <= z[i].v && z[i].v <= qq) {
        printf("%d ", i + 1);
      }
    }
    printf("\n");
  }
  return 0;
}
