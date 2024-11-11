#include <bits/stdc++.h>
using namespace std;
const int N = 120006, Nd = N << 2;
int n, Q;
int d[N], ha[Nd], ti[Nd], mi[Nd], addv[Nd], St[2][N], tp[2];
long long ans[Nd], res[Nd];
struct querys {
  int l, r, id;
  bool operator<(const querys &rhs) const { return r < rhs.r; }
} q[N];
void Setv(int o, int x) { mi[o] += x, addv[o] += x; }
void Sett(int o, int x) {
  ans[o] += 1ll * x * ha[o];
  ti[o] += x;
}
void pushup(int o) {
  mi[o] = min(mi[o << 1], mi[o << 1 | 1]);
  ha[o] = 0;
  if (mi[o] == mi[o << 1]) ha[o] += ha[o << 1];
  if (mi[o] == mi[o << 1 | 1]) ha[o] += ha[o << 1 | 1];
  ans[o] = ans[o << 1] + ans[o << 1 | 1];
}
void pushdown(int o) {
  if (addv[o]) Setv(o << 1, addv[o]), Setv(o << 1 | 1, addv[o]), addv[o] = 0;
  if (ti[o]) {
    if (mi[o] == mi[o << 1]) Sett(o << 1, ti[o]);
    if (mi[o] == mi[o << 1 | 1]) Sett(o << 1 | 1, ti[o]);
    ti[o] = 0;
  }
}
void build(int l, int r, int o) {
  mi[o] = l, ha[o] = 1;
  if (l == r) return;
  int mid = l + r >> 1;
  build(l, mid, o << 1);
  build(mid + 1, r, o << 1 | 1);
}
void modify(int L, int R, int l, int r, int o, int v) {
  if (L <= l && r <= R) {
    Setv(o, v);
    return;
  }
  int mid = l + r >> 1;
  pushdown(o);
  if (L <= mid) modify(L, R, l, mid, o << 1, v);
  if (R > mid) modify(L, R, mid + 1, r, o << 1 | 1, v);
  pushup(o);
}
long long query(int L, int R, int l, int r, int o) {
  if (L <= l && r <= R) return ans[o];
  int mid = l + r >> 1;
  long long res = 0ll;
  pushdown(o);
  if (L <= mid) res += query(L, R, l, mid, o << 1);
  if (R > mid) res += query(L, R, mid + 1, r, o << 1 | 1);
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
  build(1, n, 1);
  scanf("%d", &Q);
  for (int i = 1; i <= Q; i++) scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
  sort(q + 1, q + 1 + Q);
  for (int i = 1, now = 1; i <= n; i++) {
    Setv(1, -1);
    for (; tp[0] && d[i] > d[St[0][tp[0]]]; tp[0]--)
      modify(St[0][tp[0] - 1] + 1, St[0][tp[0]], 1, n, 1,
             d[i] - d[St[0][tp[0]]]);
    St[0][++tp[0]] = i;
    for (; tp[1] && d[i] < d[St[1][tp[1]]]; tp[1]--)
      modify(St[1][tp[1] - 1] + 1, St[1][tp[1]], 1, n, 1,
             d[St[1][tp[1]]] - d[i]);
    St[1][++tp[1]] = i;
    Sett(1, 1);
    for (; now <= Q && q[now].r == i; now++)
      res[q[now].id] = query(q[now].l, q[now].r, 1, n, 1);
  }
  for (int i = 1; i <= Q; i++) printf("%I64d\n", res[i]);
  return 0;
}
