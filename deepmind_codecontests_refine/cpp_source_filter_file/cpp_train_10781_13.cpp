#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long a = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) a = (a << 3) + (a << 1) + ch - '0';
  return a * f;
}
const long long mod = 1e9 + 7;
const long long N = 3e5 + 5;
const long long inf = 0x3f3f3f3f;
const long long INF = 2147483647;
const double PI = acos(-1);
namespace segment_tree {
struct node {
  long long len, ls, rs, lmax, rmax;
  long long data, l_line, r_line;
  inline friend node operator+(const node& a, const node& b) {
    node ans;
    ans.len = a.len + b.len;
    ans.ls = a.ls;
    ans.rs = b.rs;
    ans.l_line = a.l_line;
    if (a.l_line == a.len && a.rs > b.ls) ans.l_line += b.l_line;
    ans.r_line = b.r_line;
    if (b.r_line == b.len && a.rs < b.ls) ans.r_line += a.r_line;
    ans.lmax = a.lmax;
    ans.rmax = b.rmax;
    if (a.lmax == a.len && a.rs > b.ls)
      ans.lmax = max(ans.lmax, a.lmax + b.l_line);
    if (a.r_line == a.len && a.rmax < b.len)
      ans.lmax = max(ans.lmax, a.r_line + b.lmax);
    if (ans.rmax == b.len && a.rs < b.ls) ans.rmax += a.r_line;
    if (b.l_line == b.len && a.rs > b.ls)
      ans.rmax = max(ans.rmax, b.l_line + a.rmax);
    ans.data = max(a.data, b.data);
    if (a.rs > b.ls) ans.data = max(ans.data, a.rmax + b.l_line);
    if (a.rs < b.ls) ans.data = max(ans.data, b.lmax + a.r_line);
    return ans;
  }
} tr[N << 2];
long long tag[N << 2], a[N], n, m;
inline long long ls(long long pos) { return pos << 1; }
inline long long rs(long long pos) { return pos << 1 | 1; }
void build(long long pos, long long l, long long r) {
  if (l == r) {
    tr[pos].len = tr[pos].lmax = tr[pos].rmax = 1;
    tr[pos].data = tr[pos].l_line = tr[pos].r_line = 1;
    tr[pos].ls = tr[pos].rs = a[l];
    return;
  }
  long long mid = (l + r) >> 1;
  build(ls(pos), l, mid);
  build(rs(pos), mid + 1, r);
  tr[pos] = tr[ls(pos)] + tr[rs(pos)];
}
inline void push_down(long long pos) {
  tr[ls(pos)].ls += tag[pos];
  tr[rs(pos)].rs += tag[pos];
  tr[ls(pos)].rs += tag[pos];
  tr[rs(pos)].ls += tag[pos];
  tag[ls(pos)] += tag[pos];
  tag[rs(pos)] += tag[pos];
  tag[pos] = 0;
  return;
}
void update(long long pos, long long l, long long r, long long L, long long R,
            long long val) {
  if (L <= l && r <= R) {
    tr[pos].ls += val;
    tr[pos].rs += val;
    tag[pos] += val;
    return;
  }
  push_down(pos);
  long long mid = (l + r) >> 1;
  if (L <= mid) update(ls(pos), l, mid, L, R, val);
  if (R > mid) update(rs(pos), mid + 1, r, L, R, val);
  tr[pos] = tr[ls(pos)] + tr[rs(pos)];
}
node query(long long pos, long long l, long long r, long long L, long long R) {
  if (L <= l && r <= R) return tr[pos];
  push_down(pos);
  long long mid = (l + r) >> 1;
  if (R <= mid) return query(ls(pos), l, mid, L, R);
  if (L > mid) return query(rs(pos), mid + 1, r, L, R);
  node a = query(ls(pos), l, mid, L, R);
  node b = query(rs(pos), mid + 1, r, L, R);
  return a + b;
}
}  // namespace segment_tree
using namespace segment_tree;
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  build(1, 1, n);
  m = read();
  for (long long i = 1; i <= m; i++) {
    long long l = read(), r = read(), val = read();
    update(1, 1, n, l, r, val);
    printf("%lld\n", tr[1].data);
  }
  return 0;
}
