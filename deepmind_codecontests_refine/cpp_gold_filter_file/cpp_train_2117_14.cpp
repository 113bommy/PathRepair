#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const long long maxn = 1e5 + 5, INF = 1e9 + 5;
inline long long read() {
  long long ret = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') ret = ret * 10 + ch - '0', ch = getchar();
  return ret * f;
}
long long n, m;
struct object {
  long long x, y, t;
  long long id, rank, ans, upper;
} a[maxn], b[maxn];
bool cmp(object aa, object bb) { return aa.x < bb.x; }
bool cmp_ti(object aa, object bb) { return aa.t < bb.t; }
bool cmp_id(object aa, object bb) { return aa.id < bb.id; }
long long num[maxn], busid[maxn];
void discrete() {
  for (long long i = 1; i <= n; i++)
    a[i].rank = i, busid[i] = a[i].id, num[i] = a[i].t;
}
void make_upper() {
  long long j = n;
  for (long long i = m; i >= 1; i--) {
    while (j - 1 >= 1 && a[j - 1].t >= b[i].t) j--;
    if (a[j].t < b[i].t)
      b[i].upper = -1;
    else
      b[i].upper = a[j].t;
  }
}
namespace SegmentTree {
long long tree[4 * maxn];
void insert(long long x, long long tl, long long tr, long long p,
            long long delta) {
  if (x == tl && tl == tr) {
    tree[p] = max(tree[p], delta);
    return;
  }
  long long mid = ((tr - tl) >> 1) + tl;
  if (x <= mid)
    insert(x, tl, mid, (p << 1), delta);
  else if (mid + 1 <= x)
    insert(x, mid + 1, tr, ((p << 1) + 1), delta);
  tree[p] = max(tree[(p << 1)], tree[((p << 1) + 1)]);
}
long long query(long long sl, long long sr, long long tl, long long tr,
                long long p, long long x) {
  if (num[tr] < sl || tree[p] < x) return INF;
  if (tl == tr) return tl;
  long long mid = ((tr - tl) >> 1) + tl, ret = INF;
  if (sl <= num[mid]) ret = min(ret, query(sl, sr, tl, mid, (p << 1), x));
  if (ret == INF && num[mid + 1] <= sr)
    ret = min(ret, query(sl, sr, mid + 1, tr, ((p << 1) + 1), x));
  return ret;
}
}  // namespace SegmentTree
signed main() {
  n = read();
  m = read();
  for (long long i = 1; i <= n; i++)
    a[i].x = read(), a[i].y = read(), a[i].t = read(), a[i].id = i;
  for (long long i = 1; i <= m; i++)
    b[i].x = read(), b[i].y = read(), b[i].t = read(), b[i].id = i;
  sort(a + 1, a + 1 + n, cmp_ti);
  sort(b + 1, b + 1 + m, cmp_ti);
  discrete();
  make_upper();
  sort(a + 1, a + 1 + n, cmp);
  sort(b + 1, b + 1 + m, cmp);
  long long j = 0;
  for (long long i = 1; i <= m; i++) {
    while (j + 1 <= n && a[j + 1].x <= b[i].x)
      SegmentTree::insert(a[j + 1].rank, 1, n, 1, a[j + 1].y), j++;
    if (b[i].t > num[n])
      b[i].ans = INF;
    else
      b[i].ans = SegmentTree::query(b[i].upper, num[n], 1, n, 1, b[i].y);
  }
  sort(b + 1, b + 1 + m, cmp_id);
  for (long long i = 1; i <= m; i++)
    printf("%lld ", ((b[i].ans == INF) ? -1 : busid[b[i].ans]));
  printf("\n");
  return 0;
}
