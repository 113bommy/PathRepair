#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 1e6 + 2;
int n, a[N], b[M + 10], va[M + 10], p[M * 4 + 10], q[M * 4 + 10],
    ad[M * 4 + 10], Q;
inline void up(int x) {
  p[x] = min(p[x << 1], p[x << 1 | 1]);
  q[x] = 0;
  if (p[x] == p[x << 1]) q[x] += q[x << 1];
  if (p[x] == p[x << 1 | 1]) q[x] += q[x << 1 | 1];
}
inline void pd(int x) {
  if (ad[x])
    ad[x << 1] += ad[x], p[x << 1] += ad[x], ad[x << 1 | 1] += ad[x],
        p[x << 1 | 1] += ad[x], ad[x] = 0;
}
void bui(int l, int r, int o) {
  if (l == r) {
    p[o] = b[l];
    q[o] = va[l];
    return;
  }
  int mid = (l + r) >> 1;
  bui(l, mid, o << 1);
  bui(mid + 1, r, o << 1 | 1);
  up(o);
}
void upd(int l, int r, int o, int x, int y) {
  if (l == r) {
    q[o] = y;
    return;
  }
  int mid = (l + r) >> 1;
  pd(o);
  x > mid ? upd(mid + 1, r, o << 1 | 1, x, y) : upd(l, mid, o << 1, x, y);
  up(o);
}
void add(int l, int r, int o, int ql, int qr, int x) {
  if (ql > r || qr < l) return;
  if (ql <= l && r <= qr) {
    p[o] += x;
    ad[o] += x;
    return;
  }
  int mid = (l + r) >> 1;
  pd(o);
  add(l, mid, o << 1, ql, qr, x);
  add(mid + 1, r, o << 1 | 1, ql, qr, x);
  up(o);
}
inline void Add(int l, int r, int x) {
  if (l > r) swap(l, r);
  add(0, M - 1, 1, l, r - 1, x);
}
int main() {
  scanf("%d%d", &n, &Q);
  a[0] = M;
  for (int i = (1); i <= (n); ++i) scanf("%d", a + i);
  for (int i = (1); i <= (n + 1); ++i) va[a[i]] = 1;
  for (int i = (0); i <= (n); ++i) {
    int x = a[i], y = a[i + 1];
    if (x > y) swap(x, y);
    ++b[x];
    --b[y];
  }
  for (int i = (1); i <= (M); ++i) b[i] += b[i - 1];
  bui(0, M - 1, 1);
  cerr << q[1] - 1 << endl;
  while (Q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    upd(0, M - 1, 1, a[x], 0);
    upd(0, M - 1, 1, y, 1);
    Add(a[x], a[x - 1], -1);
    Add(a[x], a[x + 1], -1);
    Add(y, a[x - 1], 1);
    Add(y, a[x + 1], 1);
    a[x] = y;
    printf("%d\n", q[1] - 1);
  }
  return 0;
}
