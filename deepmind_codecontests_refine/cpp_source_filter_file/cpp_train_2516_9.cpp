#include <bits/stdc++.h>
using namespace std;
struct node {
  long long in, out;
} o[200010];
struct tree {
  long long mi, num;
  friend tree operator+(tree a, tree b) {
    tree ret;
    ret.mi = min(a.mi, b.mi);
    if (a.mi == b.mi)
      ret.num = (a.num + b.num) % 1000000007;
    else if (a.mi < b.mi)
      ret.num = a.num;
    else
      ret.num = b.num;
    return ret;
  }
} tr[200010 << 3];
bool cmp(const node& a, const node& b) { return a.out > b.out; }
long long n, q, t[200010 << 1], tt[200010 << 1], ys[200010 << 1], dp[200010],
    f[200010];
long long ls(long long id) { return id << 1; }
long long rs(long long id) { return id << 1 | 1; }
void up(long long id) { tr[id] = tr[ls(id)] + tr[rs(id)]; }
void build(long long l, long long r, long long id) {
  if (l == r) {
    tr[id] = (tree){2000000000000000000ll, 0};
    return;
  }
  long long mid = l + r >> 1;
  build(l, mid, ls(id)), build(mid + 1, r, rs(id));
  up(id);
}
void Mod(long long l, long long r, long long id, long long x, tree w) {
  if (l == r) {
    tr[id] = tr[id] + w;
    return;
  }
  long long mid = l + r >> 1;
  if (x <= mid)
    Mod(l, mid, ls(id), x, w);
  else
    Mod(mid + 1, r, rs(id), x, w);
  up(id);
}
tree query(long long l, long long r, long long id, long long L, long long R) {
  if (L <= l && r <= R) return tr[id];
  long long mid = l + r >> 1;
  tree ret = (tree){2000000000000000000ll, 0};
  if (L <= mid) ret = ret + query(l, mid, ls(id), L, R);
  if (R > mid) ret = ret + query(mid + 1, r, rs(id), L, R);
  return ret;
}
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    t[i * 2 - 1] = a, t[i * 2] = b;
  }
  memcpy(tt, t, sizeof(tt));
  sort(t + 1, t + 1 + n * 2);
  q = unique(t + 1, t + 1 + n * 2) - t - 1;
  for (long long i = 1; i <= n * 2; i++) {
    long long e = lower_bound(t + 1, t + 1 + q, tt[i]) - t;
    if (i & 1)
      o[i + 1 >> 1].out = e;
    else
      o[i >> 1].in = e;
    ys[e] = tt[i];
  }
  sort(o + 1, o + 1 + n, cmp);
  build(1, q, 1);
  for (long long i = 1; i <= n; i++) {
    tree tt = query(1, q, 1, o[i].out, n);
    if (tt.mi == 2000000000000000000ll)
      dp[i] = ys[o[i].in], f[i] = 1;
    else
      dp[i] = tt.mi - ys[o[i].out] + ys[o[i].in], f[i] = tt.num;
    Mod(1, q, 1, o[i].in, (tree){dp[i], f[i]});
  }
  printf("%lld", query(1, q, 1, 1, q).num);
  return 0;
}
