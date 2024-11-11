#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int maxn = 4e5 + 1e2;
long long f[4 * maxn];
long long add[4 * maxn];
int n, m;
int pos, ans;
long long sum[maxn], a[maxn];
void up(int root) { f[root] = max(f[root << 1], f[root << 1 | 1]); }
void pushdown(int root, int l, int r) {
  if (add[root]) {
    add[root << 1] += add[root];
    add[root << 1 | 1] += add[root];
    f[root << 1] += add[root];
    f[root << 1 | 1] += add[root];
    add[root] = 0;
  }
}
void build(int root, int l, int r) {
  if (l == r) {
    f[root] = sum[l];
    return;
  }
  int mid = l + r >> 1;
  build(root << 1, l, mid);
  build(root << 1 | 1, mid + 1, r);
  up(root);
}
void update(int root, int l, int r, int x, int y, long long p) {
  if (x <= l && r <= y) {
    f[root] += p;
    add[root] += p;
    return;
  }
  pushdown(root, l, r);
  int mid = l + r >> 1;
  if (x <= mid) update(root << 1, l, mid, x, y, p);
  if (y > mid) update(root << 1 | 1, mid + 1, r, x, y, p);
  up(root);
}
long long query(int root, int l, int r, int x) {
  if (x == 0) return 0;
  if (l == r) {
    return f[root];
  }
  pushdown(root, l, r);
  int mid = l + r >> 1;
  long long ans = -1e18;
  if (x <= mid) ans = max(ans, query(root << 1, l, mid, x));
  if (x > mid) ans = max(ans, query(root << 1 | 1, mid + 1, r, x));
  return ans;
}
long long kachang;
int getpos(int root, int l, int r, long long lim) {
  if (l == r) {
    kachang = f[root];
    return l;
  }
  pushdown(root, l, r);
  int mid = l + r >> 1;
  if (f[root << 1] >= lim)
    return getpos(root << 1, l, mid, lim);
  else
    return getpos(root << 1 | 1, mid + 1, r, lim);
}
int solve() {
  int now = 0;
  while (now != n) {
    long long uu = query(1, 1, n, now);
    int nxt = getpos(1, 1, n, 2 * uu);
    if (kachang == 2 * a[nxt]) return nxt;
    now = nxt;
  }
  return -1;
}
signed main() {
  n = read();
  m = read();
  for (register int i = 1; i <= n; ++i) a[i] = read();
  for (register int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    update(1, 1, n, x, n, y - a[x]);
    a[x] = y;
    cout << solve() << "\n";
  }
  return 0;
}
