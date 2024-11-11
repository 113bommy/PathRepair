#include <bits/stdc++.h>
using namespace std;
const int RLEN = 1 << 20 | 1;
inline char gc() {
  static char ibuf[RLEN], *ib, *ob;
  (ob == ib) && (ob = (ib = ibuf) + fread(ibuf, 1, RLEN, stdin));
  return (ob == ib) ? EOF : *ib++;
}
inline int read() {
  char ch = getchar();
  int res = 0, f = 1;
  while (!isdigit(ch)) f ^= ch == '-', ch = getchar();
  while (isdigit(ch)) res = (res + (res << 2) << 1) + (ch ^ 48), ch = getchar();
  return f ? res : -res;
}
template <class tp>
inline void chemx(tp &a, tp b) {
  a < b ? a = b : 0;
}
template <class tp>
inline void chemn(tp &a, tp b) {
  a > b ? a = b : 0;
}
const int N = 120005;
namespace Seg {
long long s[N << 2];
int t[N << 2], mn[N << 2], tag[N << 2], ctag[N << 2];
inline void pushup(int u) {
  mn[u] = min(mn[(u << 1)], mn[((u << 1) | 1)]);
  t[u] = 0;
  if (mn[(u << 1)] == mn[u]) t[u] += t[(u << 1)];
  if (mn[((u << 1) | 1)] == mn[u]) t[u] += t[((u << 1) | 1)];
  s[u] = s[(u << 1)] + s[((u << 1) | 1)];
}
inline void pushnow(int u, int k) { mn[u] += k, tag[u] += k; }
inline void pushnowc(int u, int k) { ctag[u] += k, s[u] += 1ll * t[u] * k; }
inline void pushdown(int u) {
  if (tag[u]) {
    pushnow((u << 1), tag[u]);
    pushnow(((u << 1) | 1), tag[u]);
    tag[u] = 0;
  }
  if (ctag[u]) {
    if (mn[(u << 1)] == mn[u]) pushnowc((u << 1), ctag[u]);
    if (mn[((u << 1) | 1)] == mn[u]) pushnowc(((u << 1) | 1), ctag[u]);
    ctag[u] = 0;
  }
}
void build(int u, int l, int r) {
  if (l == r) {
    t[u] = 1, mn[u] = l;
    return;
  }
  build((u << 1), l, ((l + r) >> 1)),
      build(((u << 1) | 1), ((l + r) >> 1) + 1, r);
  pushup(u);
}
void update(int u, int l, int r, int st, int des, int k) {
  if (des < st) return;
  if (st <= l && r <= des) return pushnow(u, k);
  pushdown(u);
  if (st <= ((l + r) >> 1)) update((u << 1), l, ((l + r) >> 1), st, des, k);
  if (((l + r) >> 1) < des)
    update(((u << 1) | 1), ((l + r) >> 1) + 1, r, st, des, k);
  pushup(u);
}
long long query(int u, int l, int r, int st, int des) {
  if (des < st) return 0;
  if (st <= l && r <= des) return s[u];
  pushdown(u);
  long long res = 0;
  if (st <= ((l + r) >> 1)) res += query((u << 1), l, ((l + r) >> 1), st, des);
  if (((l + r) >> 1) < des)
    res += query(((u << 1) | 1), ((l + r) >> 1) + 1, r, st, des);
  pushup(u);
  return res;
}
}  // namespace Seg
int n, m, a[N];
long long ans[N];
vector<pair<int, int> > q[N];
int q1[N], q2[N], top1, top2;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  m = read(), Seg::build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int l = read(), r = read();
    q[r].push_back(pair<int, int>(l, i));
  }
  for (int i = 1; i <= n; i++) {
    Seg::update(1, 1, n, 1, n, -1);
    while (top1 && a[q1[top1]] <= a[i])
      Seg::update(1, 1, n, q1[top1 - 1] + 1, q1[top1], -a[q1[top1]]), top1--;
    Seg::update(1, 1, n, q1[top1] + 1, i - 1, a[i]);
    q1[++top1] = i;
    while (top2 && a[q2[top2]] >= a[i])
      Seg::update(1, 1, n, q2[top2 - 1] + 1, q2[top2], a[q2[top2]]), top2--;
    Seg::update(1, 1, n, q2[top2] + 1, i - 1, -a[i]), q2[++top2] = i;
    Seg::pushnowc(1, 1);
    for (pair<int, int> &x : q[i]) {
      ans[x.second] = Seg::query(1, 1, n, x.first, i);
    }
  }
  for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
}
