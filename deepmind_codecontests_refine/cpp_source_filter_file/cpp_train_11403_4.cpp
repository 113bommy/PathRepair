#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-10;
inline int read() {
  static char ch;
  bool sgn = false;
  while (ch = getchar(), ch < '0' || ch > '9')
    if (ch == '-') sgn = true;
  int res = ch - 48;
  while (ch = getchar(), ch >= '0' && ch <= '9') res = res * 10 + ch - 48;
  return sgn ? -res : res;
}
const int N = 4e5 + 5;
struct Seg {
  int rt[N], ls[N * 20], rs[N * 20], mx[N * 20], sum;
  int f[N];
  inline int Max(int x, int y) {
    if (f[x] == f[y]) return x < y ? x : y;
    if (f[x] < f[y]) return y;
    return x;
  }
  void Ins(int k, int &kk, int l, int r, int p, int v) {
    kk = ++sum;
    mx[kk] = Max(mx[k], v);
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (p <= mid)
      rs[kk] = rs[k], Ins(ls[k], ls[kk], l, mid, p, v);
    else
      ls[kk] = ls[k], Ins(rs[k], rs[kk], mid + 1, r, p, v);
  }
  int Query(int k, int l, int r, int p) {
    if (k == 0) return 0;
    if (l > p) return 0;
    if (r <= p) return mx[k];
    int mid = (l + r) >> 1;
    return Max(Query(ls[k], l, mid, p), Query(rs[k], mid + 1, r, p));
  }
} Pre, Nxt;
int Val[N * 4];
void Ins(int k, int l, int r, int p, int q, int v) {
  if (l > q || r < p) return;
  if (l >= p && r <= q) {
    Val[k] = max(Val[k], v);
    return;
  }
  int mid = (l + r) >> 1;
  Ins(k << 1, l, mid, p, q, v);
  Ins(k << 1 | 1, mid + 1, r, p, q, v);
}
void push_down(int k, int l, int r) {
  if (l == r) return;
  Val[k << 1] = max(Val[k << 1], Val[k]);
  Val[k << 1 | 1] = max(Val[k << 1 | 1], Val[k]);
  int mid = (l + r) >> 1;
  push_down(k << 1, l, mid);
  push_down(k << 1 | 1, mid + 1, r);
}
int Query(int k, int l, int r, int p) {
  if (l > p || r < p) return 0;
  if (l == r) return Val[k];
  int mid = (l + r) >> 1;
  return max(Query(k << 1, l, mid, p), Query(k << 1 | 1, mid + 1, r, p));
}
int h[N], l[N * 2], a[N], b[N], pre[N], nxt[N];
int main() {
  int n = read(), m = read(), L = 0;
  for (int i = 1; i <= n; i++) {
    h[i] = read();
    l[++L] = h[i];
  }
  for (int i = 1; i <= m; i++) {
    a[i] = read();
    b[i] = read();
    l[++L] = b[i];
  }
  sort(l + 1, l + 1 + L);
  L = unique(l + 1, l + 1 + L) - l - 1;
  for (int i = 1; i <= n; i++) h[i] = lower_bound(l + 1, l + 1 + L, h[i]) - l;
  for (int i = 1; i <= m; i++) b[i] = lower_bound(l + 1, l + 1 + L, b[i]) - l;
  for (int i = 1; i <= n; i++) {
    if (h[i] > 1) pre[i] = Pre.Query(Pre.rt[i - 1], 1, L, h[i] - 1);
    Pre.f[i] = Pre.f[pre[i]] + 1;
    Pre.Ins(Pre.rt[i - 1], Pre.rt[i], 1, L, h[i], i);
  }
  for (int i = n; i >= 1; i--) {
    if (h[i] < L) nxt[i] = Nxt.Query(Nxt.rt[i + 1], 1, L, L - h[i]);
    if (nxt[i] == 0) nxt[i] = n + 1;
    Nxt.f[i] = Nxt.f[nxt[i]] + 1;
    Nxt.Ins(Nxt.rt[i + 1], Nxt.rt[i], 1, L, L - h[i] + 1, i);
  }
  for (int i = 1; i <= n; i++) {
    int x = Pre.f[i] + Nxt.f[i] - 1;
    if (pre[i] < i - 1) Ins(1, 1, n, pre[i] + 1, i - 1, x);
    if (nxt[i] > i + 1) Ins(1, 1, n, i + 1, nxt[i] - 1, x);
    Ins(1, 1, n, i, i, x - 1);
    if (pre[i] > 1) Ins(1, 1, n, 1, pre[i] - 1, x - 1);
    if (nxt[i] < n) Ins(1, 1, n, nxt[i] + 1, n, x - 1);
  }
  push_down(1, 1, n);
  for (int i = 1; i <= m; i++) {
    int ans = max(Query(1, 1, n, a[i]),
                  Pre.f[Pre.Query(Pre.rt[a[i] - 1], 1, L, b[i] - 1)] +
                      Nxt.f[Nxt.Query(Nxt.rt[a[i] + 1], 1, L, L - b[i])] + 1);
    printf("%d\n", ans);
  }
}
