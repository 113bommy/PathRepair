#include <bits/stdc++.h>
using namespace std;
template <typename T>
void cmax(T& x, T y) {
  if (x < y) x = y;
}
template <typename T>
void cmin(T& x, T y) {
  if (x > y) x = y;
}
inline int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return f * x;
}
const int N = 100005, INF = 0x3f3f3f3f, M = 8e6 + 5;
int n, k, q, a[N], lg[N], h[N][20], b[N], c[N];
int rt, tot, ls[M], rs[M], tag[M], v[M];
inline int get(int l, int r) {
  int k = lg[r - l + 1];
  return min(h[l][k], h[r - (1 << k) + 1][k]);
}
inline int find(int l, int r) {
  if (r - l + 1 >= n) return b[n];
  int t1 = l % n, t2 = r % n;
  if (!t1) t1 = n;
  if (!t2) t2 = n;
  if (t1 <= t2) return get(t1, t2);
  return min(b[t2], c[t1]);
}
inline void pd(int rt) {
  if (tag[rt] > 0) {
    if (!ls[rt]) ls[rt] = ++tot;
    if (!rs[rt]) rs[rt] = ++tot;
    tag[ls[rt]] = tag[rs[rt]] = v[ls[rt]] = v[rs[rt]] = tag[rt], tag[rt] = 0;
  }
}
inline int al(int rt, int l, int r) {
  if (!rt || tag[rt] == -1) return find(l, r);
  return v[rt];
}
inline void cov(int& rt, int l, int r, int L, int R, int p) {
  if (!rt) rt = ++tot;
  if (L <= l && r <= R) return v[rt] = tag[rt] = p, void();
  pd(rt);
  int mid = (l + r) >> 1;
  if (L <= mid) cov(ls[rt], l, mid, L, R, p);
  if (mid < R) cov(rs[rt], mid + 1, r, L, R, p);
  v[rt] = min(al(ls[rt], l, mid), al(rs[rt], mid + 1, r));
  if (tag[rt] == -1) tag[rt] = 0;
}
inline int query(int rt, int l, int r, int L, int R) {
  if (!rt) return find(max(l, L), min(r, R));
  if (L <= l && r <= R) return al(rt, l, r);
  pd(rt);
  int mid = (l + r) >> 1, s = INF;
  if (L <= mid) cmin(s, query(ls[rt], l, mid, L, R));
  if (mid < R) cmin(s, query(rs[rt], mid + 1, r, L, R));
  return s;
}
int main() {
  n = read(), k = read(), b[0] = c[n + 1] = INF, memset(tag, -1, sizeof(tag));
  for (int i = (2), iend = (n); i <= iend; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = (1), iend = (n); i <= iend; i++) h[i][0] = a[i] = read();
  for (int i = (1), iend = (17); i <= iend; i++)
    for (int j = (1), jend = (n); j <= jend; j++)
      if (j + (1 << i) - 1 <= n)
        h[j][i] = min(h[j][i - 1], h[j + (1 << i - 1)][i - 1]);
  for (int i = (1), iend = (n); i <= iend; i++) b[i] = min(b[i - 1], a[i]);
  for (int i = (n), iend = (1); i >= iend; i--) c[i] = min(c[i + 1], a[i]);
  q = read();
  for (int i = (1), iend = (q); i <= iend; i++) {
    int o = read(), x = read(), y = read(), z;
    if (o == 1)
      z = read(), cov(rt, 1, n * k, x, y, z);
    else
      printf("%d\n", query(rt, 1, n * k, x, y));
  }
}
