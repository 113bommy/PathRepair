#include <bits/stdc++.h>
using namespace std;
const int N = 1.5e5 + 10;
int n, Q, p, a[N], o, tg[N * 4];
struct node {
  int a[5], b[5];
  node() {
    for (int i = (0); i <= (4); ++i) a[i] = b[i] = 0;
  }
} f[N * 4];
inline node operator+(node a, node b) {
  for (int i = (0); i <= (o - 1); ++i) {
    bool ok = 0;
    int k = 0;
    for (int j = (0); j <= (o - 1); ++j)
      if (a.a[i] == b.a[j]) {
        b.b[j] += a.b[i];
        ok = 1;
        break;
      }
    if (ok) continue;
    for (int j = (1); j <= (o - 1); ++j)
      if (b.b[j] < b.b[k]) k = j;
    if (b.b[k] <= a.b[i]) {
      int t = b.b[k];
      b.b[k] = a.b[i] + 1;
      b.a[k] = a.a[i];
      for (int j = (0); j <= (o - 1); ++j) b.b[j] -= t;
    } else {
      for (int j = (0); j <= (o - 1); ++j) b.b[j] -= a.b[i];
    }
  }
  return b;
}
inline void pt(int o, int le, int x) {
  tg[o] = x;
  f[o] = node();
  f[o].a[0] = x;
  f[o].b[0] = le;
}
inline void pd(int o, int le) {
  if (tg[o]) {
    pt(o << 1, le + 1 >> 1, tg[o]);
    pt(o << 1 | 1, le >> 1, tg[o]);
    tg[o] = 0;
  }
}
void bui(int l, int r, int o) {
  if (l == r) {
    f[o].a[0] = a[l];
    f[o].b[0] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  bui(l, mid, o << 1);
  bui(mid + 1, r, o << 1 | 1);
  f[o] = f[o << 1] + f[o << 1 | 1];
}
void upd(int o, int l, int r, int ql, int qr, int x) {
  if (ql <= l && r <= qr) {
    pt(o, r - l + 1, x);
    return;
  }
  if (ql > r || qr < l) return;
  int mid = (l + r) >> 1;
  pd(o, r - l + 1);
  upd(o << 1, l, mid, ql, qr, x);
  upd(o << 1 | 1, mid + 1, r, ql, qr, x);
  f[o] = f[o << 1] + f[o << 1 | 1];
}
node que(int o, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return f[o];
  if (ql > r || qr < l) return node();
  int mid = (l + r) >> 1;
  pd(o, r - l + 1);
  return que(o << 1, l, mid, ql, qr) + que(o << 1 | 1, mid + 1, r, ql, qr);
}
int main() {
  scanf("%d%d%d", &n, &Q, &p);
  o = 100 / p;
  for (int i = (1); i <= (n); ++i) scanf("%d", a + i);
  bui(1, n, 1);
  while (Q--) {
    int opt, l, r, x;
    scanf("%d%d%d", &opt, &l, &r);
    if (opt == 1)
      scanf("%d", &x), upd(1, 1, n, l, r, x);
    else {
      node a = que(1, 1, n, l, r);
      int cnt = 0;
      for (int i = (0); i <= (o - 1); ++i)
        if (a.b[i]) ++cnt;
      printf("%d ", cnt);
      for (int i = (0); i <= (o - 1); ++i)
        if (a.b[i]) printf("%d ", a.a[i]);
      puts("");
    }
  }
  return 0;
}
