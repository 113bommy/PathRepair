#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long cnt1 = 0, cnt2 = 0;
long long tot;
long long lsh[200005], a[200005];
long long sum[200005 << 2], cnt[200005 << 2];
void push_up(long long p) {
  sum[p] = sum[p << 1] + sum[p << 1 | 1];
  cnt[p] = cnt[p << 1 | 1] + cnt[p << 1];
}
void modify(long long p, long long l, long long r, long long x, long long v) {
  cnt[p] += v;
  if (l == r) {
    sum[p] = cnt[p] * lsh[l];
    return;
  }
  long long mid = (l + r) >> 1;
  if (x <= mid)
    modify(p << 1, l, mid, x, v);
  else
    modify(p << 1 | 1, mid + 1, r, x, v);
  push_up(p);
}
long long kth(long long p, long long l, long long r, long long k) {
  if (k > cnt[p]) return m + 1;
  if (l == r) return l;
  long long mid = (l + r) >> 1, v = cnt[p << 1];
  if (v >= k)
    return kth(p << 1, l, mid, k);
  else
    return kth(p << 1 | 1, mid + 1, r, k - v);
}
long long query(long long p, long long l, long long r, long long ql,
                long long qr) {
  if (ql > qr) return 0;
  if (ql <= l && qr >= r) return sum[p];
  long long mid = (l + r) >> 1, res = 0;
  if (ql <= mid) res += query(p << 1, l, mid, ql, qr);
  if (qr > mid) res += query(p << 1 | 1, mid + 1, r, ql, qr);
  return res;
}
struct opt {
  long long tp, x;
} p[200005];
long long getid(long long x) {
  return lower_bound(lsh + 1, lsh + n + 1, x) - lsh;
}
set<long long> s1, s2;
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld%lld", &p[i].tp, &p[i].x);
    lsh[i] = abs(p[i].x);
  }
  sort(lsh + 1, lsh + n + 1);
  m = unique(lsh + 1, lsh + n + 1) - lsh - 1;
  for (long long i = 1; i <= n; i++) {
    long long pos = getid(abs(p[i].x));
    tot += p[i].x;
    if (p[i].x > 0) {
      modify(1, 1, m, pos, 1);
      if (p[i].tp == 0)
        cnt1++, s1.insert(pos);
      else
        cnt2++, s2.insert(pos);
    }
    if (p[i].x < 0) {
      modify(1, 1, m, pos, -1);
      if (p[i].tp == 0)
        cnt1--, s1.erase(pos);
      else
        cnt2--, s2.erase(pos);
    }
    if (s1.empty()) {
      long long t = kth(1, 1, m, 2);
      long long tmp = query(1, 1, m, t, m);
      printf("%lld\n", tot + tmp);
    } else if ((*s1.rbegin() < *s2.begin())) {
      long long t = kth(1, 1, m, cnt1 + 2);
      printf("%lld\n", lsh[*s1.rbegin()] + tot + query(1, 1, m, t, m));
    } else {
      long long t = kth(1, 1, m, cnt1 + 1);
      printf("%lld\n", tot + query(1, 1, m, t, m));
    }
  }
  return 0;
}
