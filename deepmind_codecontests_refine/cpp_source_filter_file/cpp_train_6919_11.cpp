#include <bits/stdc++.h>
using namespace std;
inline long long max(long long x, long long y) { return (x > y ? x : y); }
inline long long min(long long x, long long y) { return (x < y ? x : y); }
inline long long read() {
  long long x = 0;
  char c = getchar();
  bool y = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') y = 0;
  for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + c - 48;
  if (y) return x;
  return -x;
}
long long n, m, r, K, val[200010], v[200010], tot;
long long A[200010], B[200010], C[200010], D[200010], cnt, opt;
struct data {
  long long fi, se, th, fo;
  data(const long long X = 0, const long long Y = 0, const long long Z = 0,
       const long long W = 0)
      : fi(X), se(Y), th(Z), fo(W) {}
  bool operator<(const data &X) const { return th < X.th; }
} S[200010];
struct Segment_Tree {
  long long T[200010 << 2], len[200010 << 2], U[200010 << 2];
  inline void pushup(long long x) {
    if (U[x])
      T[x] = len[x];
    else
      T[x] = T[(x << 1)] + T[(x << 1 | 1)];
    return;
  }
  inline void pusht(long long x, long long val) {
    U[x] += val;
    return pushup(x);
  }
  void build(long long x, long long l, long long r) {
    if (l == r) {
      len[x] = val[l];
      return;
    }
    long long mid = (l + r) >> 1;
    build((x << 1), l, mid);
    build((x << 1 | 1), mid + 1, r);
    len[x] = len[(x << 1)] + len[(x << 1 | 1)];
    return;
  }
  void modify(long long x, long long l, long long r, long long lx, long long rx,
              long long val) {
    if (lx <= l && r <= rx) return pusht(x, val);
    long long mid = (l + r) >> 1;
    if (lx <= mid) modify((x << 1), l, mid, lx, rx, val);
    if (rx > mid) modify((x << 1 | 1), mid + 1, r, lx, rx, val);
    pushup(x);
    return;
  }
  long long Gval() { return T[1]; }
  inline void clear() {
    memset(T, 0, sizeof(T));
    memset(len, 0, sizeof(len));
    memset(U, 0, sizeof(U));
    return;
  }
} tree;
inline long long Calc(long long id) {
  tot = 0;
  long long ret = 0;
  for (register long long i = 1; i <= m; ++i) {
    long long l1 = (A[i] - 1 >> id) + 1, l2 = (B[i] - 1 >> id) + 1,
              r1 = (C[i] >> id), r2 = (D[i] >> id);
    if (l1 > r1 || l2 > r2) continue;
    S[++tot] = data(l1, r1 + 1, l2, 1);
    val[tot] = l1;
    S[++tot] = data(l1, r1 + 1, r2 + 1, -1);
    val[tot] = r1 + 1;
  }
  if (!tot) return 0;
  sort(val + 1, val + tot + 1);
  sort(S + 1, S + tot + 1);
  cnt = unique(val + 1, val + tot + 1) - val - 1;
  for (register long long i = 1; i <= tot; ++i)
    S[i].fi = lower_bound(val + 1, val + cnt + 1, S[i].fi) - val,
    S[i].se = lower_bound(val + 1, val + cnt + 1, S[i].se) - val - 1;
  for (register long long i = 1; i <= cnt; ++i) val[i] = val[i + 1] - val[i];
  val[cnt] = 0;
  --cnt;
  tree.clear();
  tree.build(1, 1, cnt);
  for (register long long i = 1; i < tot; ++i) {
    tree.modify(1, 1, cnt, S[i].fi, S[i].se, S[i].fo);
    ret += tree.Gval() * (S[i + 1].th - S[i].th);
  }
  return ret;
}
inline long long Val(long long x) {
  if (!x) return 0;
  long long ret = 0;
  while (x) x >>= 1, ++ret;
  return ret;
}
inline void Input() {
  n = read(), m = read(), K = read();
  for (register long long i = 1; i <= m; ++i)
    A[i] = read(), B[i] = read(), C[i] = read(), D[i] = read();
  return;
}
inline void solve() {
  r = Val(K);
  v[0] = Calc(0);
  for (register long long i = 1; i <= r; ++i) v[i] = Calc(i), v[i - 1] -= v[i];
  for (register long long i = 0; i <= r; ++i)
    if (v[i] & 1) opt = 1;
  puts(opt ? "Hamed" : "Malek");
  return;
}
signed main() {
  Input();
  solve();
  return 0;
}
