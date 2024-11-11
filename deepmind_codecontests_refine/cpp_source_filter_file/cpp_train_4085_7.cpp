#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 10000;
const long long lim = 1000000;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long n, m, p, b[maxn], cb[maxn], buc[maxn];
pair<long long, long long> a[maxn];
struct monster {
  long long x, y, z;
} mydata[maxn];
struct segment_tree {
  long long mx[maxn * 4], tag[maxn * 4];
  void push_up(long long x) { mx[x] = max(mx[x << 1], mx[x << 1 | 1]); }
  void build(long long l, long long r, long long root) {
    if (l == r) {
      mx[root] = (buc[l]) ? -buc[l] : -inf;
      return;
    }
    long long mid = (l + r) >> 1;
    build(l, mid, root << 1);
    build(mid + 1, r, root << 1 | 1);
    push_up(root);
  }
  void push_down(long long x) {
    if (!tag[x]) return;
    tag[x << 1] += tag[x];
    tag[x << 1 | 1] += tag[x];
    mx[x << 1] += tag[x];
    mx[x << 1 | 1] += tag[x];
    tag[x] = 0;
  }
  void update(long long l, long long r, long long root, long long tl,
              long long tr, long long val) {
    if (tl <= l && r <= tr) {
      tag[root] += val;
      mx[root] += val;
      return;
    }
    push_down(root);
    long long mid = (l + r) >> 1;
    if (tl <= mid) update(l, mid, root << 1, tl, tr, val);
    if (tr >= mid + 1) update(mid + 1, r, root << 1 | 1, tl, tr, val);
    push_up(root);
    return;
  }
} t;
bool cmp(monster x, monster y) { return x.x < y.x; }
signed main() {
  scanf("%lld%lld%lld", &n, &m, &p);
  for (long long i = 1; i <= n; i++)
    scanf("%lld%lld", &a[i].first, &a[i].second);
  for (long long i = 1; i <= m; i++) scanf("%lld%lld", &b[i], &cb[i]);
  sort(a + 1, a + 1 + n);
  for (long long i = 1; i <= m; i++) {
    if (!buc[b[i]])
      buc[b[i]] = cb[i];
    else
      buc[b[i]] = min(cb[i], buc[b[i]]);
  }
  for (long long i = 1; i <= p; i++)
    scanf("%lld%lld%lld", &mydata[i].x, &mydata[i].y, &mydata[i].z);
  sort(mydata + 1, mydata + 1 + p, cmp);
  t.build(1, lim, 1);
  long long mo_cnt = 0;
  long long out = -inf;
  for (long long i = 1; i <= n; i++) {
    long long ans = -a[i].second;
    while (mo_cnt < p && mydata[mo_cnt + 1].x < a[i].first) {
      t.update(1, lim, 1, mydata[mo_cnt + 1].y + 1, lim, mydata[mo_cnt + 1].z);
      mo_cnt++;
    }
    ans += t.mx[1];
    out = max(ans, out);
  }
  printf("%lld", out);
  return 0;
}
