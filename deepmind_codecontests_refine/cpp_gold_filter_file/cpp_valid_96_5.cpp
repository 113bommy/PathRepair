#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long a = 0;
  long long d = 1;
  char c;
  while (c = getchar(), c < '0' || c > '9')
    if (c == '-') d = -1;
  a = a * 10 + c - 48;
  while (c = getchar(), c >= '0' && c <= '9') a = a * 10 + c - 48;
  a *= d;
  return a;
}
long long a[1005000];
long long val[1005000];
long long n, q;
long long ed;
void init() {
  for (long long i = 1; i <= n; i++) val[i] = val[i - 1] + i;
}
struct node {
  long long l, r;
  long long pre, sul;
  long long mid;
  bool all;
} c[1005000];
vector<long long> qq;
bool cmp(long long a, long long b) {
  if (c[a].l == c[b].l) return c[a].r < c[b].r;
  return c[a].l < c[b].l;
}
inline long long ls(long long x) { return x << 1; }
inline long long rs(long long x) { return x << 1 | 1; }
inline void pushup(long long p, long long lss, long long rss) {
  if (c[lss].all && c[rss].all) {
    c[p].mid = 0;
    if (a[c[lss].r] <= a[c[rss].l]) {
      c[p].all = true;
      c[p].pre = c[lss].pre + c[rss].pre;
      c[p].sul = c[p].pre;
    } else {
      c[p].all = false;
      c[p].pre = c[lss].pre;
      c[p].sul = c[rss].pre;
    }
  } else if (c[lss].all && !c[rss].all) {
    c[p].all = false;
    c[p].sul = c[rss].sul;
    if (a[c[lss].r] <= a[c[rss].l]) {
      c[p].pre = c[lss].pre + c[rss].pre;
      c[p].mid = c[rss].mid;
    } else {
      c[p].pre = c[lss].pre;
      c[p].mid = c[rss].mid + val[c[rss].pre];
    }
  } else if (!c[lss].all && c[rss].all) {
    c[p].all = false;
    c[p].pre = c[lss].pre;
    if (a[c[lss].r] <= a[c[rss].l]) {
      c[p].sul = c[lss].sul + c[rss].pre;
      c[p].mid = c[lss].mid;
    } else {
      c[p].sul = c[rss].pre;
      c[p].mid = c[lss].mid + val[c[lss].sul];
    }
  } else {
    c[p].all = false;
    c[p].pre = c[lss].pre;
    c[p].sul = c[rss].sul;
    if (a[c[lss].r] <= a[c[rss].l])
      c[p].mid = c[lss].mid + c[rss].mid + val[c[lss].sul + c[rss].pre];
    else
      c[p].mid = c[lss].mid + c[rss].mid + val[c[lss].sul] + val[c[rss].pre];
  }
}
void build(long long p, long long l, long long r) {
  c[p].l = l;
  c[p].r = r;
  if (l == r) {
    c[p].all = true;
    c[p].pre = 1;
    c[p].sul = 1;
    c[p].mid = 0;
    return;
  }
  long long mid = (l + r) >> 1;
  build(ls(p), l, mid);
  build(rs(p), mid + 1, r);
  pushup(p, ls(p), rs(p));
}
void update(long long p, long long x, long long z) {
  if (c[p].l == c[p].r) {
    a[c[p].l] = z;
    return;
  }
  long long mid = (c[p].l + c[p].r) >> 1;
  if (x <= mid)
    update(ls(p), x, z);
  else
    update(rs(p), x, z);
  pushup(p, ls(p), rs(p));
}
void query(long long p, long long x, long long y) {
  if (x <= c[p].l && y >= c[p].r) {
    qq.push_back(p);
    return;
  }
  long long mid = (c[p].l + c[p].r) >> 1;
  if (x <= mid) query(ls(p), x, y);
  if (y > mid) query(rs(p), x, y);
}
signed main() {
  n = read();
  q = read();
  init();
  for (long long i = 1; i <= n; i++) a[i] = read();
  build(1, 1, n);
  ed = (n << 2) + 10;
  while (q--) {
    long long op = read();
    long long x = read();
    long long y = read();
    if (op == 1)
      update(1, x, y);
    else {
      qq.clear();
      query(1, x, y);
      sort(qq.begin(), qq.end(), cmp);
      c[ed] = c[qq[0]];
      for (long long i = 1; i < qq.size(); i++) {
        c[ed + 1].l = c[ed].l;
        c[ed + 1].r = c[qq[i]].r;
        pushup(ed + 1, ed, qq[i]);
        c[ed] = c[ed + 1];
      }
      long long ans = 0;
      if (c[ed].all)
        ans = val[c[ed].pre];
      else
        ans = val[c[ed].pre] + val[c[ed].sul] + c[ed].mid;
      printf("%lld\n", ans);
    }
  }
  return 0;
}
