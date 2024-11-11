#include <bits/stdc++.h>
using namespace std;
int gi() {
  int x = 0, w = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') w = 0, ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return w ? x : -x;
}
const int N = 2e5 + 5;
struct edge {
  int u, v, w;
  bool operator<(const edge &b) const { return u < b.u; }
} p[N];
int n, m, q, A[N], B[N];
long long mn[N << 2], tag[N << 2], cut[N];
void build1(int x, int l, int r) {
  if (l == r) {
    mn[x] = B[l];
    return;
  }
  int mid = l + r >> 1;
  build1(x << 1, l, mid);
  build1(x << 1 | 1, mid + 1, r);
  mn[x] = min(mn[x << 1], mn[x << 1 | 1]) + tag[x];
}
void build2(int x, int l, int r) {
  tag[x] = 0;
  if (l == r) {
    mn[x] = cut[l] + A[l];
    return;
  }
  int mid = l + r >> 1;
  build2(x << 1, l, mid);
  build2(x << 1 | 1, mid + 1, r);
  mn[x] = min(mn[x << 1], mn[x << 1 | 1]) + tag[x];
}
void modify(int x, int l, int r, int ql, int qr, int v) {
  if (l >= ql && r <= qr) {
    mn[x] += v;
    tag[x] += v;
    return;
  }
  int mid = l + r >> 1;
  if (ql <= mid) modify(x << 1, l, mid, ql, qr, v);
  if (qr > mid) modify(x << 1 | 1, mid + 1, r, ql, qr, v);
  mn[x] = min(mn[x << 1], mn[x << 1 | 1]) + tag[x];
}
int main() {
  n = gi();
  m = gi();
  q = gi();
  for (int i = 1; i < n; ++i) A[i] = gi(), B[i + 1] = gi();
  for (int i = 1; i <= m; ++i) p[i] = (edge){gi(), gi(), gi()};
  sort(p + 1, p + m + 1);
  build1(1, 1, n);
  for (int i = 1, j = 1; i <= n; ++i) {
    while (j <= m && p[j].u <= i) modify(1, 1, n, 1, p[j].v, p[j].w), ++j;
    cut[i] = mn[1];
  }
  build2(1, 1, n);
  printf("%I64d\n", mn[1]);
  while (q--) {
    int u = gi(), v = gi();
    modify(1, 1, n, u, u, v - A[u]);
    A[u] = v;
    printf("%I64d\n", mn[1]);
  }
  return 0;
}
