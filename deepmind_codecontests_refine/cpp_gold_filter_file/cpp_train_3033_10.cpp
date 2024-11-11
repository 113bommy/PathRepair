#include <bits/stdc++.h>
constexpr int N = 500005, M = 20;
int n, m, c[N], base[M], pos[M], ans[N];
struct Query {
  int l, r;
  int id;
  inline bool operator<(const Query &rhs) const { return r < rhs.r; }
} q[N];
inline void insert(int x, int p) {
  for (int i = M - 1; ~i; --i)
    if ((x >> i) & 1) {
      if (base[i]) {
        if (pos[i] < p) std::swap(x, base[i]), std::swap(p, pos[i]);
        x ^= base[i];
      } else
        return base[i] = x, pos[i] = p, void();
    }
}
inline int query(int p) {
  int res = 0;
  for (int i = M - 1; ~i; --i)
    if (base[i] && pos[i] >= p) {
      res = std::max(res, res ^ base[i]);
    }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &c[i]);
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &q[i].l, &q[i].r);
    q[i].id = i;
  }
  std::sort(q + 1, q + m + 1);
  for (int i = 1, cur = 0; i <= m; ++i) {
    while (cur < q[i].r) ++cur, insert(c[cur], cur);
    ans[q[i].id] = query(q[i].l);
  }
  for (int i = 1; i <= m; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
