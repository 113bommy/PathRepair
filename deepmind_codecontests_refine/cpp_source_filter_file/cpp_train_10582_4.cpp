#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return x;
}
const int maxn = 1e5 + 10;
int n, Q, blo = 2154, a[maxn], b[maxn];
struct Query {
  int l, r, t, id;
  bool operator<(const Query &x) const {
    if (l / blo == x.l / blo) {
      if (r / blo == x.r / blo) return r / blo & 1 ? t < x.t : t > x.t;
      return r < x.r;
    }
    return l < x.l;
  }
} q[maxn];
struct Change {
  int pos, val;
} c[maxn];
int cnt[maxn], tot[maxn], ans[maxn];
inline void add(int x) { tot[cnt[x]]--, tot[++cnt[x]]++; }
inline void del(int x) { tot[cnt[x]]--, tot[--cnt[x]]++; }
inline void work(int x, int i) {
  if (c[x].pos >= q[i].l && c[x].pos <= q[i].r) del(a[c[x].pos]), add(c[x].val);
  swap(c[x].val, a[c[x].pos]);
}
inline int calc() {
  for (int i = 1;; i++)
    if (!tot[i]) return i;
}
int main() {
  n = read(), Q = read();
  int tot = 0;
  for (int i = 1; i <= n; i++) b[++tot] = a[i] = read();
  int nq = 0, nc = 0;
  for (int i = 1; i <= Q; i++) {
    int opt = read(), x = read(), y = read();
    if (opt == 1)
      q[++nq].l = x, q[nq].r = y, q[nq].t = nc, q[nq].id = nq;
    else
      c[++nc].pos = x, b[++tot] = c[nc].val = y;
  }
  sort(b + 1, b + tot + 1);
  tot = unique(b + 1, b + tot + 1) - b - 1;
  for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + tot + 1, a[i]) - b;
  for (int i = 1; i <= nc; i++)
    c[i].val = lower_bound(b + 1, b + tot + 1, c[i].val) - b;
  sort(q + 1, q + nq + 1);
  int l = 1, r = 0, t = 0;
  for (int i = 1; i <= nq; i++) {
    while (l > q[i].l) add(a[--l]);
    while (r < q[i].r) add(a[++r]);
    while (l < q[i].l) del(a[l++]);
    while (r > q[i].r) del(a[r--]);
    while (t < q[i].t) work(++t, i);
    while (t > q[i].t) work(t--, i);
    ans[q[i].id] = calc();
  }
  for (int i = 1; i <= nq; i++) printf("%d\n", ans[i]);
  return 0;
}
