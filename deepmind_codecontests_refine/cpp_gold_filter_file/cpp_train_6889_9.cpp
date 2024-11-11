#include <bits/stdc++.h>
using namespace std;
void read(long long &x) {
  x = 0;
  long long f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -f;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  x *= f;
}
void print(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (!x) return;
  print(x / 10), putchar(x % 10 + 48);
}
void write(long long x) {
  if (!x)
    putchar('0');
  else
    print(x);
  putchar('\n');
}
const long long maxn = 2e6 + 10;
const long long inf = 1e9;
const double eps = 1e-8;
const long long mod = 1e9 + 7;
long long a[maxn], k, n, w;
struct segment_tree {
  long long t[maxn << 2], tag[maxn << 2];
  void update(long long p) { t[p] = t[p << 1] + t[p << 1 | 1]; }
  void push_tag(long long p, long long l, long long r, long long v) {
    tag[p] += v, t[p] += v * (r - l + 1);
  }
  void pushdown(long long p, long long l, long long r) {
    if (tag[p])
      push_tag(p << 1, l, ((l + r) >> 1), tag[p]),
          push_tag(p << 1 | 1, ((l + r) >> 1) + 1, r, tag[p]), tag[p] = 0;
  }
  void modify(long long p, long long l, long long r, long long x, long long y,
              long long v) {
    if (x <= l && r <= y) return push_tag(p, l, r, v), void();
    pushdown(p, l, r);
    if (x <= ((l + r) >> 1)) modify(p << 1, l, ((l + r) >> 1), x, y, v);
    if (y > ((l + r) >> 1)) modify(p << 1 | 1, ((l + r) >> 1) + 1, r, x, y, v);
    update(p);
  }
  void print(long long p, long long l, long long r) {
    if (l == r) return printf("%lld ", t[p]), void();
    pushdown(p, l, r);
    print(p << 1, l, ((l + r) >> 1)), print(p << 1 | 1, ((l + r) >> 1) + 1, r);
  }
} T;
struct segment_tree2 {
  long long t[maxn << 2];
  void build(long long p, long long l, long long r) {
    if (l == r) return t[p] = a[l], void();
    build(p << 1, l, ((l + r) >> 1)), build(p << 1 | 1, ((l + r) >> 1) + 1, r);
    t[p] = max(t[p << 1], t[p << 1 | 1]);
  }
  long long query(long long p, long long l, long long r, long long x,
                  long long y) {
    if (x <= l && r <= y) return t[p];
    long long ans = -inf;
    if (x <= ((l + r) >> 1))
      ans = max(ans, query(p << 1, l, ((l + r) >> 1), x, y));
    if (y > ((l + r) >> 1))
      ans = max(ans, query(p << 1 | 1, ((l + r) >> 1) + 1, r, x, y));
    return ans;
  }
} s;
void solve() {
  read(k);
  long long mx = -inf, l = 0, r = 0;
  for (long long i = 1; i <= k; i++) read(a[i]), mx = max(mx, a[i]);
  for (long long i = 1; i <= k; i++)
    if (a[i] == mx) {
      if (!l) l = i, r = i;
    }
  s.build(1, 1, k);
  if (mx < 0) {
    if (k * 2 <= w) return;
    for (long long i = w - k + 1; i <= k; i++) {
      long long l = max(1ll, k - (w - i)), r = i;
      T.modify(1, 1, w, i, i, s.query(1, 1, k, l, r));
    }
    return;
  }
  if (l <= w - (k - r)) T.modify(1, 1, w, l, w - (k - r), mx);
  deque<long long> q;
  long long x = w - k;
  for (long long i = 1; i < l; i++) {
    while ((!q.empty()) && a[q.back()] <= a[i]) q.pop_back();
    q.push_back(i);
    while ((!q.empty()) && q.front() < i - x) q.pop_front();
    long long xx = a[q.front()];
    if (k + i <= w) xx = max(0ll, xx);
    T.modify(1, 1, w, i, i, xx);
  }
  while (!q.empty()) q.pop_back();
  for (long long i = k; i > r; i--) {
    while ((!q.empty()) && a[q.back()] <= a[i]) q.pop_back();
    q.push_back(i);
    while ((!q.empty()) && q.front() > i + x) q.pop_front();
    long long xx = a[q.front()];
    if (k - i + 1 + k <= w) xx = max(0ll, xx);
    T.modify(1, 1, w, w - (k - i), w - (k - i), xx);
  }
}
signed main() {
  read(n), read(w);
  for (long long i = 1; i <= n; i++) solve();
  T.print(1, 1, w);
  puts("");
  return 0;
}
