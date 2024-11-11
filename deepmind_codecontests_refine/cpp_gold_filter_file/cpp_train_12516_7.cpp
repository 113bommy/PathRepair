#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int M = 1000005;
const long long inf = 1000000000000000ll;
class node {
 public:
  long long x, y, z;
  node() {}
  node(long long x, long long y, long long z) : x(x), y(y), z(z) {}
} monster[N];
struct feature {
  long long x, c;
} a[N], b[N];
struct seg {
  int l, r;
  long long tag, mx;
} t[M << 2];
int n, m, p, tot;
long long ans = -inf, mn = inf, sum = 0, mx1, mx2, mn1, mn2;
bool cmp1(feature a, feature b) {
  return (a.x < b.x) || (a.x == b.x && a.c < b.c);
}
bool cmp2(node a, node b) { return a.x < b.x; }
void init() {
  int i, l = 0, j;
  for (i = 1; i <= m; i = j + 1) {
    j = i;
    while (j < m && b[j + 1].x == b[j].x) j++;
    b[++l] = b[i];
  }
  m = l;
  mn = b[m].c;
  for (i = m; i >= 1; i--) {
    if (mn < b[i].c) b[i].c = mn;
    if (b[i].c < mn) mn = b[i].c;
  }
}
void release(int k, long long w) {
  t[k].tag += w;
  t[k].mx += w;
}
void pushdown(int k) {
  if (t[k].tag) {
    release(k << 1, t[k].tag);
    release(k << 1 | 1, t[k].tag);
    t[k].tag = 0;
  }
}
void update(int k) { t[k].mx = max(t[k << 1].mx, t[k << 1 | 1].mx); }
void build(int k, int l, int r) {
  t[k].l = l;
  t[k].r = r;
  t[k].mx = -inf;
  t[k].tag = 0;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
}
void modify(int k, int L, int R, long long w) {
  if (L <= t[k].l && t[k].r <= R) {
    release(k, w);
    return;
  }
  pushdown(k);
  int mid = (t[k].l + t[k].r) >> 1;
  if (L <= mid) modify(k << 1, L, R, w);
  if (R > mid) modify(k << 1 | 1, L, R, w);
  update(k);
}
void modifyp(int k, int pt, long long w) {
  if (t[k].l == t[k].r) {
    t[k].mx = max(t[k].mx, w);
    return;
  }
  int mid = (t[k].l + t[k].r) >> 1;
  if (pt <= mid)
    modifyp(k << 1, pt, w);
  else
    modifyp(k << 1 | 1, pt, w);
  update(k);
}
void solve() {
  int i, j;
  j = 1;
  for (i = 1; i <= n; i++) {
    while (monster[j].x < a[i].x && j <= p) {
      if (monster[j].y <= tot) modify(1, monster[j].y, tot, monster[j].z);
      j++;
    }
    ans = max(ans, t[1].mx - a[i].c);
  }
}
int main() {
  int i, last, j;
  scanf("%d%d%d", &n, &m, &p);
  for (i = 1; i <= n; i++)
    scanf("%lld%lld", &a[i].x, &a[i].c), mn = min(mn, a[i].c),
                                         mx1 = max(mx1, a[i].x);
  sum = mn;
  mn = inf;
  for (i = 1; i <= m; i++)
    scanf("%lld%lld", &b[i].x, &b[i].c), mn = min(mn, b[i].c),
                                         mx2 = max(mx2, b[i].x);
  sum += mn;
  for (i = 1; i <= p; i++) {
    scanf("%lld%lld%lld", &monster[i].x, &monster[i].y, &monster[i].z);
    mn1 = min(mn1, monster[i].x);
    mn2 = min(mn2, monster[i].y);
  }
  sort(monster + 1, monster + 1 + p, cmp2);
  sort(a + 1, a + 1 + n, cmp1);
  sort(b + 1, b + 1 + m, cmp1);
  tot = b[m].x - 1;
  if (!tot || mx1 <= mn1 || mx2 <= mn2) {
    printf("%lld\n", -sum);
    return 0;
  }
  init();
  build(1, 1, tot);
  last = 1;
  for (i = 1; i <= m; i++) {
    for (j = last; j < b[i].x; j++) modifyp(1, j, -b[i].c);
    last = b[i].x;
  }
  solve();
  printf("%I64d\n", ans);
  return 0;
}
