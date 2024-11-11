#include <bits/stdc++.h>
using namespace std;
inline unsigned long long read() {
  unsigned long long t = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    c = getchar();
  }
  while (c <= '9' && c >= '0') t = t * 10 + c - 48, c = getchar();
  return t * f;
}
int n, q, t, in[500001], a[500001];
double p[500001];
struct tree {
  double mx, mi, ans;
  int t1, t2;
} tr[500001];
inline void solve(int x, int t) {
  tr[x].ans = min(1.0 * in[t] / (a[t] + in[t]) * p[t], p[t] / 2.0);
  if (in[t] >= a[t])
    tr[x].mx = 0;
  else
    tr[x].mx = p[t] * (1.0 * (in[t] + 1) / (in[t] + a[t] + 1) -
                       1.0 * in[t] / (in[t] + a[t]));
  if (in[t] == 0)
    tr[x].mi = 1e18;
  else if (in[t] > a[t])
    tr[x].mi = 0;
  else
    tr[x].mi = p[t] * (1.0 * in[t] / (in[t] + a[t]) -
                       1.0 * (in[t] - 1) / (in[t] + a[t] - 1));
  tr[x].t1 = tr[x].t2 = t;
}
inline void up(int x) {
  tr[x].ans = tr[x << 1].ans + tr[x << 1 | 1].ans;
  tr[x].mx = max(tr[x << 1].mx, tr[x << 1 | 1].mx);
  tr[x].mi = min(tr[x << 1].mi, tr[x << 1 | 1].mi);
  if (tr[x].mx == tr[x << 1].mx)
    tr[x].t1 = tr[x << 1].t1;
  else
    tr[x].t1 = tr[x << 1 | 1].t1;
  if (tr[x].mi == tr[x << 1].mi)
    tr[x].t2 = tr[x << 1].t2;
  else
    tr[x].t2 = tr[x << 1 | 1].t2;
}
inline void build(int x, int l, int r) {
  if (l == r) {
    solve(x, l);
    return;
  }
  int mid = l + r >> 1;
  build(x << 1, l, mid);
  build(x << 1 | 1, mid + 1, r);
  up(x);
}
inline void upd(int x, int l, int r, int to) {
  if (l == r) {
    solve(x, l);
    return;
  }
  int mid = l + r >> 1;
  if (to <= mid)
    upd(x << 1, l, mid, to);
  else
    upd(x << 1 | 1, mid + 1, r, to);
  up(x);
}
int main() {
  n = read();
  t = read();
  q = read();
  for (unsigned long long i = 1; i <= n; ++i) p[i] = 1.0 * read();
  for (unsigned long long i = 1; i <= n; ++i) a[i] = read();
  build(1, 1, n);
  for (unsigned long long i = 1; i <= t; ++i) {
    int now = tr[1].t1;
    in[now]++;
    upd(1, 1, n, now);
  }
  for (unsigned long long i = 1; i <= q; ++i) {
    int t = 0;
    if (read() == 2)
      a[t = read()]--;
    else
      a[t = read()]++;
    upd(1, 1, n, t);
    while (tr[1].mx - tr[1].mi > 1e-10) {
      int x = tr[1].t1, y = tr[1].t2;
      in[x]++;
      in[y]--;
      upd(1, 1, n, x);
      upd(1, 1, n, y);
    }
    printf("%.10lf\n", tr[1].ans);
  }
}
