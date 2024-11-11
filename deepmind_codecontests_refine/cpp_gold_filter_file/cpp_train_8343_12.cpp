#include <bits/stdc++.h>
const int N = 200005;
int n, m;
long long cost[N];
long long val[N << 2], laz[N << 2], ans;
struct Node {
  int l, u;
  long long p;
  inline bool operator<(const Node &rph) const { return u < rph.u; }
} a[N];
inline void pushup(int x) { val[x] = std::max(val[x << 1], val[x << 1 | 1]); }
inline void pushdown(int x) {
  if (laz[x]) {
    int ls = x << 1, rs = x << 1 | 1;
    laz[ls] += laz[x], laz[rs] += laz[x];
    val[ls] += laz[x], val[rs] += laz[x];
    laz[x] = 0;
  }
}
void modify(int x, int l, int r, int L, int R, long long v) {
  if (L <= l && r <= R) return (void)(val[x] += v, laz[x] += v);
  int mid = (l + r) >> 1;
  pushdown(x);
  if (L <= mid) modify(x << 1, l, mid, L, R, v);
  if (mid < R) modify(x << 1 | 1, mid + 1, r, L, R, v);
  pushup(x);
}
int head[N], left[N], nxt[N], p[N], cnt = 0;
void add(int R, int L, int v) {
  nxt[++cnt] = head[R];
  head[R] = cnt;
  left[cnt] = L;
  p[cnt] = v;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &cost[i]);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%lld", &a[i].l, &a[i].u, &a[i].p);
    add(a[i].u, a[i].l, a[i].p);
  }
  std::sort(a + 1, a + m + 1);
  for (int i = 1; i <= n; ++i) {
    modify(1, 1, n, i, i, ans);
    modify(1, 1, n, 1, i, -cost[i]);
    for (int j = head[i]; j; j = nxt[j]) modify(1, 1, n, 1, left[j], p[j]);
    ans = std::max(ans, val[1]);
  }
  printf("%lld", ans);
  return 0;
}
