#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &x, T y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
inline bool chkmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
inline void read(int &x) {
  char ch = getchar();
  int f = 1;
  x = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
int n, m, q, a[200050];
long long ans[200050], b[200050];
vector<pair<int, int> > link[200050];
struct solver {
  long long lazy[200050 << 2], minx[200050 << 2];
  void build(int u, int l, int r, long long *s) {
    if (l == r) return (void)(minx[u] = s[l]);
    build(u << 1, l, ((l + r) >> 1), s),
        build(u << 1 | 1, ((l + r) >> 1) + 1, r, s);
    minx[u] = min(minx[u << 1], minx[u << 1 | 1]);
  }
  void add(int u, long long w) { lazy[u] += w, minx[u] += w; }
  void push(int u) {
    if (lazy[u]) add(u << 1, lazy[u]), add(u << 1 | 1, lazy[u]), lazy[u] = 0;
  }
  void modify(int u, int l, int r, int tl, int tr, int w) {
    if (tl <= l && r <= tr) return add(u, w);
    push(u);
    if (tl <= ((l + r) >> 1)) modify(u << 1, l, ((l + r) >> 1), tl, tr, w);
    if (((l + r) >> 1) < tr)
      modify(u << 1 | 1, ((l + r) >> 1) + 1, r, tl, tr, w);
    minx[u] = min(minx[u << 1], minx[u << 1 | 1]);
  }
} sgt1, sgt2;
int main() {
  int u, v, w;
  read(n), read(m), read(q);
  for (register int i = 1; i <= n - 1; ++i) read(a[i]), scanf("%lld", &b[i]);
  for (register int i = 1; i <= m; ++i)
    read(u), read(v), read(w), link[u].push_back(make_pair(v, w));
  sgt2.build(1, 0, n - 1, b);
  for (register int i = 1; i <= n; ++i) {
    for (auto cur : link[i]) {
      sgt2.modify(1, 0, n - 1, 0, cur.first - 1, cur.second);
    }
    ans[i] = sgt2.minx[1] + a[i];
  }
  sgt1.build(1, 1, n, ans);
  printf("%lld\n", sgt1.minx[1]);
  while (q--) {
    read(u), read(v);
    sgt1.modify(1, 1, n, u, u, -a[u]), a[u] = v,
                                       sgt1.modify(1, 1, n, u, u, a[u]);
    printf("%lld\n", sgt1.minx[1]);
  }
  return 0;
}
