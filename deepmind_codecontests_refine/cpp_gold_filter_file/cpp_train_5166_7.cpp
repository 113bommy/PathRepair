#include <bits/stdc++.h>
using namespace std;
const int maxn = 100055;
int A[maxn], B[maxn];
struct SegTree {
  struct Node {
    int l, r;
    long long s[2], f;
    void upd(long long y) {
      f += y;
      int o = l & 1, k1 = (r - l) / 2 + 1, k2 = r - l + 1 - k1;
      s[o] += y * k1, s[o ^ 1] += y * k2;
    }
  } v[maxn << 2];
  void build(int l, int r, int x) {
    v[x].l = l, v[x].r = r, v[x].s[0] = v[x].s[1] = v[x].f = 0;
    if (l == r) {
      v[x].s[l & 1] = A[l];
      return;
    }
    int m = l + r >> 1;
    build(l, m, x << 1), build(m + 1, r, x << 1 | 1);
    up(x);
  }
  void pd(int x) {
    if (v[x].f) {
      v[x << 1].upd(v[x].f), v[x << 1 | 1].upd(v[x].f);
      v[x].f = 0;
    }
  }
  void up(int x) {
    for (int i = 0; i < (int)(2); ++i) {
      v[x].s[i] = v[x << 1].s[i] + v[x << 1 | 1].s[i];
    }
  }
  void mf(int l, int r, int y, int x) {
    if (v[x].l >= l && v[x].r <= r) {
      v[x].upd(y);
      return;
    }
    int m = v[x].l + v[x].r >> 1;
    pd(x);
    if (r <= m)
      mf(l, r, y, x << 1);
    else if (l > m)
      mf(l, r, y, x << 1 | 1);
    else
      mf(l, r, y, x << 1), mf(l, r, y, x << 1 | 1);
    up(x);
  }
} ds;
inline long long myabs(long long x) { return x >= 0 ? x : -x; }
long long getans(long long a, vector<long long> &b) {
  auto f = lower_bound((b).begin(), (b).end(), a);
  if (f == b.end()) return abs(*--f - a);
  long long r = *f - a;
  if (f != b.begin()) r = min(r, abs(*--f - a));
  return r;
}
int main() {
  int n, m, Q;
  scanf("%d%d%d", &n, &m, &Q);
  for (int i = 0; i < (int)(n); ++i) scanf("%d", A + i);
  for (int i = 0; i < (int)(m); ++i) scanf("%d", B + i);
  vector<long long> bs;
  long long s = 0;
  for (int i = 0; i < (int)(n); ++i) s += (i & 1 ? -1 : 1) * B[i];
  for (int i = 0; i + n - 1 < m; ++i) {
    bs.push_back(s);
    s -= B[i];
    if (i + n < m) s = -s + (((i + n) & 1) == (i & 1) ? -1 : 1) * B[i + n];
  }
  ds.build(0, n - 1, 1);
  sort((bs).begin(), (bs).end());
  long long as = ds.v[1].s[0] - ds.v[1].s[1];
  as = 0;
  for (int i = 0; i < (int)(n); ++i) as += (i & 1 ? -1 : 1) * A[i];
  long long res = getans(as, bs);
  printf("%lld\n", res);
  while (Q--) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    --l, --r;
    ds.mf(l, r, x, 1);
    long long as = ds.v[1].s[0] - ds.v[1].s[1];
    long long res = getans(as, bs);
    printf("%lld\n", res);
  }
  return 0;
}
