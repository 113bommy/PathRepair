#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int maxm = 1e5 + 5;
const int N = 1e6 + 1;
long long mx[maxn << 2];
void pushup(int o) { mx[o] = max(mx[o << 1], mx[o << 1 | 1]); }
pair<int, long long> a[maxn];
int b[maxn];
long long lazy[maxn << 2];
void pushdown(int o) {
  if (lazy[o]) {
    lazy[o << 1] += lazy[o];
    lazy[o << 1 | 1] += lazy[o];
    mx[o << 1 | 1] += lazy[o];
    mx[o << 1] += lazy[o];
    lazy[o] = 0;
  }
}
void build(int l, int r, int o, int t) {
  if (l == r) {
    if (!t) mx[o] = -b[l];
    return;
  }
  int mid = l + r >> 1;
  pushdown(o);
  build(l, mid, o << 1, t);
  build(mid + 1, r, o << 1 | 1, t);
  pushup(o);
}
void update(int v, int L, int R, int l, int r, int o) {
  if (L <= l && r <= R) {
    lazy[o] += v;
    mx[o] += v;
    return;
  }
  int mid = l + r >> 1;
  pushdown(o);
  if (L <= mid) update(v, L, R, l, mid, o << 1);
  if (R > mid) update(v, L, R, mid + 1, r, o << 1 | 1);
  pushup(o);
}
long long query(int L, int R, int l, int r, int o) {
  if (L <= l && r <= R) {
    return mx[o];
  }
  int mid = l + r >> 1;
  long long res = 0;
  if (L <= mid) res = max(res, query(L, R, l, mid, o << 1));
  if (R > mid) res = max(res, query(L, R, mid + 1, r, o << 1 | 1));
  return res;
}
struct mon {
  int x, y, v;
  bool operator<(const mon& hs) const {
    if (x == hs.x) return y < hs.y;
    return x < hs.x;
  }
} e[maxn];
int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d %lld", &a[i].first, &a[i].second);
  }
  for (int i = 1; i <= N; ++i) b[i] = 2e9;
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    b[x] = min(b[x], y);
  }
  build(1, N, 1, 0);
  for (int i = 1; i <= q; i++) {
    scanf("%d %d %d", &e[i].x, &e[i].y, &e[i].v);
  }
  sort(e + 1, e + q + 1);
  int now = 1;
  long long ans = -2e9;
  for (int i = 1; i <= n; i++) {
    for (; now <= q; now++) {
      if (e[now].x >= a[i].first) break;
      update(e[now].v, e[now].y + 1, N, 1, N, 1);
    }
    ans = max(ans, mx[1] - a[i].second);
  }
  printf("%lld\n", ans);
}
