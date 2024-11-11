#include <bits/stdc++.h>
using namespace std;
void fre() {
  freopen("c://test//input.in", "r", stdin);
  freopen("c://test//output.out", "w", stdout);
}
template <class T>
inline void gmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline void gmin(T &a, T b) {
  if (b < a) a = b;
}
const int N = 1e5 + 10, M = 0, Z = 1e9 + 7, ms63 = 1061109567;
int n, m;
int l, r;
int vv[N], v[N];
struct A {
  int l, r, max;
} a[1 << 18];
void build(int o, int l, int r) {
  a[o].l = l;
  a[o].r = r;
  if (l == r) {
    a[o].max = v[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(o << 1, l, mid);
  build(o << 1 | 1, mid + 1, r);
  a[o].max = max(a[o << 1].max, a[o << 1 | 1].max);
}
int V;
int trylft(int o, int l, int r) {
  if (a[o].max < V)
    return l;
  else if (a[o].l == a[o].r)
    return r + 1;
  int mid = (a[o].l + a[o].r) >> 1;
  if (a[o].l == l && a[o].r == r) {
    if (a[o << 1 | 1].max < V)
      return trylft(o << 1, l, mid);
    else
      return trylft(o << 1 | 1, mid + 1, r);
  }
  if (r <= mid)
    return trylft(o << 1, l, r);
  else if (l > mid)
    return trylft(o << 1 | 1, l, r);
  else {
    int pos = trylft(o << 1 | 1, mid + 1, r);
    if (pos > mid + 1)
      return pos;
    else
      return trylft(o << 1, l, mid);
  }
}
int tryrgt(int o, int l, int r) {
  if (a[o].max <= V)
    return r;
  else if (a[o].l == a[o].r)
    return l - 1;
  int mid = (a[o].l + a[o].r) >> 1;
  if (a[o].l == l && a[o].r == r) {
    if (a[o << 1].max >= V)
      return tryrgt(o << 1 | 1, mid + 1, r);
    else
      return tryrgt(o << 1, l, mid);
  }
  if (r <= mid)
    return tryrgt(o << 1, l, r);
  else if (l > mid)
    return tryrgt(o << 1 | 1, l, r);
  else {
    int pos = tryrgt(o << 1, l, mid);
    if (pos < mid)
      return pos;
    else
      return tryrgt(o << 1 | 1, mid + 1, r);
  }
}
int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= n; ++i) scanf("%d", &vv[i]);
    --n;
    for (int i = 1; i <= n; ++i) v[i] = abs(vv[i + 1] - vv[i]);
    build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
      scanf("%d%d", &l, &r);
      --r;
      long long ans = 0;
      for (int j = l; j <= r; j++) {
        V = v[j];
        long long lft = j;
        if (l < j) lft = trylft(1, l, j - 1);
        long long rgt = j;
        if (r > j) rgt = tryrgt(1, j, r);
        ans += (j + 1 - lft) * (rgt + 1 - j) * V;
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}
