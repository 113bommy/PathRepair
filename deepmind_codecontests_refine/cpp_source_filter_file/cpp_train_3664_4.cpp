#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long f = 1, x = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
const int N = 100005;
struct Tree {
  long long left, right, mn;
} tree[N << 2];
long long n, p, t[N], ans[N];
inline void pushup(long long x) {
  tree[x].mn = min(tree[x << 1].mn, tree[x << 1 | 1].mn);
}
void build(long long x, long long l, long long r) {
  tree[x].left = l;
  tree[x].right = r;
  tree[x].mn = 1e9;
  if (r == l)
    tree[x].mn = t[l];
  else {
    long long mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    pushup(x);
  }
}
void update(long long x, long long l, long long r, long long delta) {
  if (l <= tree[x].left && r >= tree[x].right)
    tree[x].mn = t[l] = delta;
  else {
    long long mid = (tree[x].left + tree[x].right) >> 1;
    if (l <= mid) update(x << 1, l, r, delta);
    if (r > mid) update(x << 1 | 1, l, r, delta);
    pushup(x);
  }
}
long long query(long long x, long long delta) {
  if (tree[x].left == tree[x].right) return tree[x].left;
  if (tree[x << 1].mn <= delta)
    return query(x << 1, delta);
  else
    return query(x << 1 | 1, delta);
}
long long query2(long long x, long long r) {
  if (tree[x].left > r) return -1;
  if (tree[x].left == tree[x].right) return tree[x].left;
  if (tree[x << 1].mn <= tree[x << 1 | 1].mn) return query2(x << 1, r);
  long long rt = query2(x << 1 | 1, r);
  if (rt == -1 || t[rt] >= tree[x << 1].mn) return query2(x << 1, r);
  return rt;
}
signed main() {
  n = read();
  p = read();
  for (long long i = 1; i <= n; i++) t[i] = read();
  build(1, 1, n + 1);
  for (long long i = 0, cur = 0; i < n;) {
    cur = max(cur, tree[1].mn);
    long long x = query(1, cur);
    ans[x] = cur += p;
    i++;
    update(1, x, x, 1e18);
    for (; x > 0;) {
      x = query2(1, x);
      if (t[x] > cur) break;
      ans[x] = cur += p;
      i++;
      update(1, x, x, 1e18);
    }
  }
  for (long long i = 1; i <= n; i++) printf("%lld ", ans[i]);
  return 0;
}
