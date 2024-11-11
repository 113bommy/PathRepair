#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmax(T &x, T y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, T y) {
  x = x > y ? y : x;
}
template <typename T>
void upd(T &x, T y, T mod) {
  x = x + y > mod ? x + y - mod : x + y;
}
template <typename T>
void sub(T &x, T y, T mod) {
  x = x - y < 0 ? x - y + mod : x - y;
}
template <typename T>
void multi(T &x, T y, T mod) {
  x = 1ll * x * y % mod;
}
const int INF = (1ll << 30);
template <typename T>
void read(T &x) {
  x = 0;
  bool f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = 0;
  } while (ch > '9' || ch < '0');
  do {
    x = x * 10 + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  x = f ? x : -x;
}
template <typename T>
void write(T x) {
  if (x < 0) x = ~x + 1, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const long long N = 2e5 + 7;
long long n, m, a[N], ans[N];
stack<long long> s1, s2;
struct Query {
  long long l, id;
};
struct Segment_Tree {
  long long l, r, mn, cnt, sum, add, tag;
} t[N << 2];
inline void pushup(long long p) {
  t[p].mn = min(t[(p << 1)].mn, t[(p << 1 | 1)].mn);
  t[p].cnt = 0;
  if (t[p].mn == t[(p << 1)].mn) t[p].cnt += t[(p << 1)].cnt;
  if (t[p].mn == t[(p << 1 | 1)].mn) t[p].cnt += t[(p << 1 | 1)].cnt;
  t[p].sum = t[(p << 1)].sum + t[(p << 1 | 1)].sum;
}
inline void pushdown(long long p) {
  if (t[p].add) {
    t[(p << 1)].mn += t[p].add;
    t[(p << 1)].add += t[p].add;
    t[(p << 1 | 1)].mn += t[p].add;
    t[(p << 1 | 1)].add += t[p].add;
    t[p].add = 0;
  }
  if (t[p].tag) {
    if (t[(p << 1)].mn == t[p].mn)
      t[(p << 1)].sum += t[p].tag * t[(p << 1)].cnt,
          t[(p << 1)].tag += t[p].tag;
    if (t[(p << 1 | 1)].mn == t[p].mn)
      t[(p << 1 | 1)].sum += t[p].tag * t[(p << 1 | 1)].cnt,
          t[(p << 1 | 1)].tag += t[p].tag;
    t[p].tag = 0;
  }
}
inline void build(long long p, long long l, long long r) {
  t[p].l = l;
  t[p].r = r;
  t[p].mn = l;
  t[p].cnt = 1;
  if (l == r) return;
  long long mid = (t[p].l + t[p].r) >> 1;
  build((p << 1), l, mid);
  build((p << 1 | 1), mid + 1, r);
}
inline void modify(long long p, long long l, long long r, long long v) {
  if (l <= t[p].l && t[p].r <= r) {
    t[p].mn += v;
    t[p].add += v;
    return;
  }
  pushdown(p);
  long long mid = (t[p].l + t[p].r) >> 1;
  if (l <= mid) modify((p << 1), l, r, v);
  if (r > mid) modify((p << 1 | 1), l, r, v);
  pushup(p);
}
inline long long query(long long p, long long l, long long r) {
  if (l <= t[p].l && t[p].r <= r) return t[p].sum;
  pushdown(p);
  long long mid = (t[p].l + t[p].r) >> 1, ans = 0;
  if (l <= mid) ans += query((p << 1), l, r);
  if (r > mid) ans += query((p << 1 | 1), l, r);
  return ans;
}
vector<Query> q[N];
signed main() {
  read(n);
  for (long long i = 1; i <= n; i++) read(a[i]);
  read(m);
  for (long long i = 1, l, r; i <= m; i++) {
    read(l);
    read(r);
    q[r].push_back((Query){l, i});
  }
  build(1, 1, n);
  s1.push(0);
  s2.push(0);
  for (long long i = 1; i <= n; i++) {
    t[1].mn--;
    t[1].add--;
    while (s1.size() > 1 && a[s1.top()] < a[i]) {
      long long tt = s1.top();
      s1.pop();
      modify(1, s1.top() + 1, tt, a[i] - a[tt]);
    }
    s1.push(i);
    while (s2.size() > 1 && a[s2.top()] > a[i]) {
      long long tt = s2.top();
      s2.pop();
      modify(1, s2.top() + 1, tt, a[tt] - a[i]);
    }
    s2.push(i);
    t[1].sum += t[1].cnt, t[1].tag++;
    for (long long j = 0; j < q[i].size(); j++) {
      long long id = q[i][j].id, l = q[i][j].l;
      ans[id] = query(1, l, i);
    }
  }
  for (long long i = 1; i <= m; i++) printf("%lld\n", ans[i]);
  return 0;
}
