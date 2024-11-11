#include <bits/stdc++.h>
using LL = long long;
using namespace std;
const int N = (int)2e5 + 10, M = 998244353;
struct I {
  int l, r;
  bool operator<(const I &rhs) const { return l < rhs.l; }
  I() {}
  I(int l, int r) : l(l), r(r) {}
};
int n, q, as[N * 4], bs[N * 4], sum[N * 4];
set<I> ints[N];
void apply(int id, int l, int r, int na, int nb) {
  sum[id] = ((LL)sum[id] * na % M + (LL)nb * (r - l + 1) % M) % M;
  as[id] = (LL)as[id] * na % M;
  bs[id] = ((LL)bs[id] * na + nb) % M;
}
void push_down(int id, int l, int r) {
  if (as[id] != 1 || bs[id] != 0) {
    int mi = (l + r) >> 1;
    apply(id << 1, l, mi, as[id], bs[id]);
    apply(id << 1 | 1, mi + 1, r, as[id], bs[id]);
    as[id] = 1;
    bs[id] = 0;
  }
}
void push_up(int id) { sum[id] = (sum[id << 1] + sum[id << 1 | 1]) % M; }
int query(int id, int l, int r, int x, int y) {
  if (l > y || r < x) return 0;
  if (x <= l && r <= y) return sum[id];
  int mi = (l + r) >> 1;
  push_down(id, l, r);
  return (query(id << 1, l, mi, x, y) + query(id << 1 | 1, mi + 1, r, x, y)) %
         M;
}
void update(int id, int l, int r, int x, int y, int a, int b) {
  if (l > y || r < x) return;
  if (x <= l && r <= y) {
    apply(id, l, r, a, b);
    return;
  }
  int mi = (l + r) >> 1;
  push_down(id, l, r);
  update(id << 1, l, mi, x, y, a, b);
  update(id << 1 | 1, mi + 1, r, x, y, a, b);
  push_up(id);
}
void insert(int l, int r, int x) {
  auto it1 = std::prev(ints[x].upper_bound(I(l, l))),
       it2 = ints[x].upper_bound(I(r, r));
  if (it1->r < l) ++it1;
  int last = l - 1, nl = l, nr = r;
  for (auto it = it1; it != it2; it++) {
    int il = it->l, ir = it->r;
    update(1, 1, n, last + 1, il - 1, 1, 1);
    update(1, 1, n, max(il, l), min(ir, r), 2, 0);
    last = ir;
    nl = min(il, l);
    nr = max(ir, r);
  }
  update(1, 1, n, last + 1, r, 1, 1);
  ints[x].erase(it1, it2);
  ints[x].emplace(nl, nr);
}
int main() {
  scanf("%d%d", &n, &q);
  fill(as, as + N * 4, 1);
  for (int i = 1; i <= n; i++) {
    ints[i].emplace(0, 0);
    ints[i].emplace(n + 1, n + 1);
  }
  int op, l, r, x;
  for (int i = 0; i < q; i++) {
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1) {
      scanf("%d", &x);
      insert(l, r, x);
    } else
      printf("%d\n", query(1, 1, n, l, r));
  }
}
