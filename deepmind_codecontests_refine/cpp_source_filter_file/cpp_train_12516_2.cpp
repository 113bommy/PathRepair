#include <bits/stdc++.h>
using namespace std;
const int base = 1331;
const int MOD = 998244353;
const long long INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6 + 10, M = 20000010;
inline long long read() {
  char ch = getchar();
  long long f = 1, x = 0;
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m, p;
long long mx[N << 2], lz[N << 2];
struct node {
  long long v, w;
  bool operator<(const node& rhs) const {
    if (v == rhs.v) return w < rhs.w;
    return v < rhs.v;
  }
} a[N], b[N];
struct Monster {
  long long x, y, w;
  bool operator<(const Monster& rhs) const {
    if (x == rhs.x) return y < rhs.y;
    return x < rhs.x;
  }
} mst[N];
void up(int o) { mx[o] = max(mx[(o << 1)], mx[(o << 1 | 1)]); }
void build(int o, int l, int r) {
  if (l == r) {
    mx[o] = -b[l].w;
    return;
  }
  int mid = l + r >> 1;
  build((o << 1), l, mid);
  build((o << 1 | 1), mid + 1, r);
  up(o);
}
void pushdown(int o, int l, int r) {
  if (lz[o]) {
    mx[(o << 1)] += lz[o];
    mx[(o << 1 | 1)] += lz[o];
    lz[(o << 1)] += lz[o];
    lz[(o << 1 | 1)] += lz[o];
    lz[o] = 0;
  }
}
void upd(int o, int l, int r, int ql, int qr, long long val) {
  if (ql <= l && r <= qr) {
    mx[o] += val;
    lz[o] += val;
    return;
  }
  int mid = l + r >> 1;
  pushdown(o, l, r);
  if (ql <= mid) upd((o << 1), l, mid, ql, qr, val);
  if (mid < qr) upd((o << 1 | 1), mid + 1, r, ql, qr, val);
  up(o);
}
int main() {
  n = read(), m = read(), p = read();
  for (int i = 1; i <= n; i++) a[i].v = read(), a[i].w = read();
  for (int i = 1; i <= m; i++) b[i].v = read(), b[i].w = read();
  for (int i = 1; i <= p; i++)
    mst[i].x = read(), mst[i].y = read(), mst[i].w = read();
  long long ans = -2e9;
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + m);
  sort(mst + 1, mst + 1 + p);
  build(1, 1, m);
  for (int i = 1, j = 1; i <= n; i++) {
    while (j <= p && a[i].v > mst[j].x) {
      int pos = upper_bound(b + 1, b + 1 + m, (node){mst[j].y, 0}) - b;
      if (pos <= m) upd(1, 1, m, pos, m, mst[j].w);
      ++j;
    }
    ans = max(ans, mx[1] - a[i].w);
  }
  cout << ans << endl;
  return 0;
}
