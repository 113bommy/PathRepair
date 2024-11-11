#include <bits/stdc++.h>
int tms = clock();
using namespace std;
inline int read() {
  int x;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    ;
  for (x = c - '0'; (c = getchar()) >= '0' && c <= '9';) x = x * 10 + c - '0';
  return x;
}
struct node {
  int l, r, s;
} t[200000 * 19 + 5];
int a[200000 + 5], c[200000 + 5], p[200000 + 5], tn, rt[200000 + 5],
    s[200000 / 50 + 5], sc[200000 / 1000 + 5][200000 / 50 + 5], lp[200000 + 5],
    rp[200000 + 5], f[200000 / 50 + 5], fc[200000 / 1000 + 5][200000 / 50 + 5];
vector<int> v[200000 / 50 + 5], z[200000 / 50 + 5];
int add(int k, int l, int r, int x) {
  int p = ++tn;
  t[p].s = t[k].s + 1;
  if (l == r) return p;
  int mid = l + r >> 1;
  if (x <= mid)
    t[p].l = add(t[k].l, l, mid, x), t[p].r = t[k].r;
  else
    t[p].l = t[k].l, t[p].r = add(t[k].r, mid + 1, r, x);
  return p;
}
struct tree {
  int mx, mk;
} T[10000];
void build(int k, int l, int r) {
  if (T[k].mx = T[k].mk = 0, l == r) return;
  int mid = l + r >> 1;
  build((k << 1), l, mid);
  build((k << 1 | 1), mid + 1, r);
}
inline void up(int k) { T[k].mx = min(T[(k << 1)].mx, T[(k << 1 | 1)].mx); }
inline void add(int k, int x) {
  T[k].mx += x;
  T[k].mk += x;
}
inline void down(int k) {
  if (T[k].mk) add((k << 1), T[k].mk), add((k << 1 | 1), T[k].mk), T[k].mk = 0;
}
void add(int k, int l, int r, int ql, int qr) {
  if (ql <= l && qr >= r) {
    add(k, 1);
    return;
  }
  int mid = l + r >> 1;
  down(k);
  if (qr <= mid)
    add((k << 1), l, mid, ql, qr);
  else if (ql > mid)
    add((k << 1 | 1), mid + 1, r, ql, qr);
  else
    add((k << 1), l, mid, ql, mid), add((k << 1 | 1), mid + 1, r, mid + 1, qr);
  up(k);
}
int query(int k, int l, int r, int x) {
  if (!k) return 0;
  if (r <= x) return t[k].s;
  int mid = l + r >> 1;
  if (x <= mid) return query(t[k].l, l, mid, x);
  return t[t[k].l].s + query(t[k].r, mid + 1, r, x);
}
bool CMP(int x, int y) { return a[x] < a[y]; }
int main() {
  int n, m, q, i, j, l, r, lk, rk, ans = 0;
  n = read();
  m = read();
  for (i = 1; i <= n; ++i) a[i] = read(), c[i] = i;
  sort(c + 1, c + n + 1, CMP);
  sort(a + 1, a + n + 1);
  for (i = 1; i <= n; ++i) p[c[i]] = i;
  for (i = 1; i <= n; ++i) {
    rt[i] = add(rt[i - 1], 1, n, p[i]);
    lp[i] = max(0, i - m) / 50;
    rp[i] = (r - 1) / 50;
    v[lp[i]].push_back(p[i]);
    if (rp[i] > lp[i]) v[rp[i]].push_back(p[i]);
  }
  for (i = 1; i <= n; ++i) {
    ++f[lp[c[i]]];
    rp[c[i]] > lp[c[i]] ? ++f[rp[c[i]]] : 0;
    for (j = lp[c[i]]; ++j < rp[c[i]];) ++s[j];
    if (i % 1000 == 0)
      for (j = 0; j <= (n - 1) / 50; ++j)
        sc[i / 1000][j] = s[j], fc[i / 1000][j] = f[j];
  }
  for (i = 0; i <= (n - 1) / 50; ++i) {
    sort(v[i].begin(), v[i].end());
    build(1, i * 50 + 1, min(i * 50 + 50, n));
    for (j = 0; j < v[i].size(); ++j) {
      add(1, i * 50 + 1, min(i * 50 + 50, n), c[v[i][j]] - m + 1, c[v[i][j]]);
      z[i].push_back(T[1].mx);
    }
  }
  for (q = read(); q--;) {
    l = read();
    r = read();
    a[0] = lower_bound(a + 1, a + n + 1, ans ^ read()) - a - 1;
    ans = 200000;
    if (!a[0]) {
      ans = 0;
      puts("0");
      continue;
    }
    lk = (l - 1) / 50;
    rk = (r - 1) / 50;
    for (i = l; i <= r && i <= lk * 50 + 50; ++i)
      ans = min(
          ans, query(rt[i + m - 1], 1, n, a[0]) - query(rt[i - 1], 1, n, a[0]));
    if (lk != rk)
      for (i = r; i > rk * 50; --i)
        ans = min(ans, query(rt[i + m - 1], 1, n, a[0]) -
                           query(rt[i - 1], 1, n, a[0]));
    memset(s, 0, sizeof(s));
    for (i = lk; ++i < rk;) f[i] = fc[(a[0] - 1) / 1000][i];
    for (i = (a[0] - 1) / 1000 * 1000; ++i <= a[0];)
      ++f[lp[c[i]]], rp[c[i]] > lp[c[i]] ? ++s[lp[c[i]] + 1], --s[rp[c[i]]],
          ++f[rp[c[i]]] : 0;
    for (i = 1; i < rk; ++i) s[i] += s[i - 1];
    for (i = lk; ++i < rk;)
      ans = min(ans,
                (f[i] ? z[i][f[i] - 1] : 0) + sc[(a[0] - 1) / 1000][i] + s[i]);
    printf("%d\n", ans);
  }
}
