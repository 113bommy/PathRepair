#include <bits/stdc++.h>
template <typename Tp>
inline void read(Tp& x) {
  x = 0;
  bool fg = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') fg ^= 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (Tp)(ch ^ 48), ch = getchar();
  if (fg) x = -x;
}
template <typename Tp, typename... Args>
void read(Tp& t, Args&... args) {
  read(t);
  read(args...);
}
using namespace std;
const int N = 100010;
int a[N], ans[N], val[N << 1], totval;
struct quer {
  int id, l, r, t;
} q[N];
struct modi {
  int p, Old, New;
} m[N];
int n, Q, bl[N], B, totq, totm;
int ct[N], vs[N];
int l = 1, r = 0, t = 0;
int getmex() {
  for (int i = 1;; ++i)
    if (vs[i] == 0) return i;
}
void upd(int vl, int k) {
  --vs[ct[vl]];
  ct[vl] += k;
  ++vs[ct[vl]];
}
void updM(int id, int k) {
  if (k == 1) {
    m[id].Old = a[m[id].p];
    a[m[id].p] = m[id].New;
    if (l <= m[id].p && m[id].p <= r) {
      upd(m[id].Old, -1);
      upd(m[id].New, 1);
    }
  } else {
    a[m[id].p] = m[id].Old;
    if (l <= m[id].p && m[id].p <= r) {
      upd(m[id].New, -1);
      upd(m[id].Old, 1);
    }
  }
}
int main() {
  read(n, Q);
  for (int i = 1; i <= n; ++i) read(a[i]), val[++totval] = a[i];
  B = max(1, (int)pow(n, 2.0 / 3.0));
  for (int i = 1; i <= n; ++i) bl[i] = (i - 1) / B + 1;
  for (int i = 1; i <= Q; ++i) {
    int op;
    read(op);
    if (op == 1) {
      ++totq;
      read(q[totq].l, q[totq].r);
      q[totq].id = totq;
      q[totq].t = totm;
    } else {
      ++totm;
      read(m[totm].p, m[totm].New);
      val[++totval] = m[totm].New;
    }
  }
  sort(val + 1, val + totval + 1);
  totval = unique(val + 1, val + totval + 1) - val - 1;
  for (int i = 1; i <= n; ++i)
    a[i] = lower_bound(val + 1, val + totval + 1, a[i]) - val;
  for (int i = 1; i <= totm; ++i)
    m[i].New = lower_bound(val + 1, val + totval + 1, m[i].New) - val;
  sort(q + 1, q + totq + 1, [](quer& a, quer& b) {
    int ida = bl[a.l] * 10000 + bl[a.r];
    int idb = bl[b.l] * 10000 + bl[b.r];
    return ida != idb ? ida < idb : a.t < b.t;
  });
  for (int i = 1; i <= totq; ++i) {
    while (l > q[i].l) upd(a[--l], 1);
    while (r < q[i].r) upd(a[++r], 1);
    while (l < q[i].l) upd(a[l++], -1);
    while (r > q[i].r) upd(a[r--], -1);
    while (t < q[i].t) updM(++t, 1);
    while (t > q[i].t) updM(t--, -1);
    ans[q[i].id] = getmex();
  }
  for (int i = 1; i <= totq; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
