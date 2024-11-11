#include <bits/stdc++.h>
using namespace std;
const long long maxn = 100000 + 5;
long long n, m, l[maxn << 3], r[maxn << 3], sum[maxn << 3], rev[maxn << 3],
    op[maxn], tag[maxn << 3], a[maxn << 3];
void chkmax(long long &a, long long b) {
  if (a < b) a = b;
}
void chkmin(long long &a, long long b) {
  if (a > b) a = b;
}
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > 57 || ch < 48) {
    if (ch == 45) f = -1;
    ch = getchar();
  }
  while (ch <= 57 && ch >= 48) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
namespace segment_tree {
void pushup(long long k) { sum[k] = sum[k << 1] + sum[k << 1 | 1]; }
void build(long long k, long long l, long long r) {
  tag[k] = -1;
  if (l == r) return;
  long long Mid = (l + r) >> 1;
  build(k << 1, l, Mid);
  build(k << 1 | 1, Mid + 1, r);
  pushup(k);
}
void pushdown(long long k, long long l, long long r) {
  long long Mid = (l + r) >> 1;
  if (tag[k] != -1) {
    tag[k << 1] = tag[k];
    tag[k << 1 | 1] = tag[k];
    rev[k << 1] = rev[k << 1 | 1] = 0;
    if (tag[k]) {
      sum[k << 1] = Mid - l + 1;
      sum[k << 1 | 1] = r - Mid;
    } else
      sum[k << 1] = sum[k << 1 | 1] = 0;
    tag[k] = -1;
  }
  if (rev[k]) {
    if (tag[k << 1] != -1)
      tag[k << 1] ^= 1;
    else
      rev[k << 1] ^= 1;
    if (tag[k << 1 | 1] != -1)
      tag[k << 1 | 1] ^= 1;
    else
      rev[k << 1 | 1] ^= 1;
    sum[k << 1] = Mid - l + 1 - sum[k << 1];
    sum[k << 1 | 1] = r - Mid - sum[k << 1 | 1];
    rev[k] = 0;
  }
}
void update(long long k, long long l, long long r, long long ql, long long qr,
            long long op) {
  if (l > qr || r < ql) return;
  if (l >= ql && r <= qr) {
    if (l == r) {
      if (op == 1)
        sum[k] = 1;
      else if (op == 2)
        sum[k] = 0;
      else
        sum[k] ^= 1;
    } else {
      if (op == 1) {
        sum[k] = r - l + 1;
        tag[k] = 1;
        rev[k] = 0;
      } else if (op == 2) {
        sum[k] = 0;
        tag[k] = 0;
        rev[k] = 0;
      } else {
        if (tag[k] != -1)
          tag[k] ^= 1;
        else
          rev[k] ^= 1;
        sum[k] = r - l + 1 - sum[k];
      }
    }
    return;
  }
  long long Mid = (l + r) >> 1;
  pushdown(k, l, r);
  update(k << 1, l, Mid, ql, qr, op);
  update(k << 1 | 1, Mid + 1, r, ql, qr, op);
  pushup(k);
}
long long query(long long k, long long l, long long r) {
  if (l == r) return l;
  long long Mid = (l + r) >> 1;
  pushdown(k, l, r);
  if (sum[k << 1] == Mid - l + 1)
    return query(k << 1 | 1, Mid + 1, r);
  else
    return query(k << 1, l, Mid);
}
}  // namespace segment_tree
using namespace segment_tree;
signed main() {
  m = read();
  a[++n] = 1;
  for (long long i = 1; i <= m; i++) {
    op[i] = read();
    l[i] = read();
    r[i] = read();
    a[++n] = l[i];
    a[++n] = r[i];
    a[++n] = r[i] + 1;
  }
  sort(a + 1, a + 1 + n);
  n = unique(a + 1, a + 1 + n) - (a + 1);
  build(1, 1, n);
  for (long long i = 1; i <= m; i++) {
    l[i] = lower_bound(a + 1, a + 1 + n, l[i]) - a;
    r[i] = lower_bound(a + 1, a + 1 + n, r[i]) - a;
    update(1, 1, n, l[i], r[i], op[i]);
    cout << a[query(1, 1, n)] << endl;
  }
  return 0;
}
