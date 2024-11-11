#include <bits/stdc++.h>
using namespace std;
inline int read() {
  static char ch;
  bool sgn = false;
  while (ch = getchar(), ch < '0' || ch > '9')
    if (ch == '-') sgn = true;
  int res = ch - 48;
  while (ch = getchar(), ch >= '0' && ch <= '9') res = res * 10 + ch - 48;
  return sgn ? -res : res;
}
const int N = 2e5 + 10;
int cmp(int *r, int a, int b, int l) {
  return (r[a] == r[b]) && (r[a + l] == r[b + l]);
}
int wa[N], wb[N], wss[N], wv[N];
int Rank[N], height[N], f[N][20], d[20], Log[N];
void da(int *r, int *sa, int n, int m) {
  int i, j, p, *x = wa, *y = wb, *t;
  for (i = 0; i < m; i++) wss[i] = 0;
  for (i = 0; i < n; i++) wss[x[i] = r[i]]++;
  for (i = 1; i < m; i++) wss[i] += wss[i - 1];
  for (i = n - 1; i >= 0; i--) sa[--wss[x[i]]] = i;
  for (j = 1, p = 1; p < n; j *= 2, m = p) {
    for (p = 0, i = n - j; i < n; i++) y[p++] = i;
    for (i = 0; i < n; i++)
      if (sa[i] >= j) y[p++] = sa[i] - j;
    for (i = 0; i < n; i++) wv[i] = x[y[i]];
    for (i = 0; i < m; i++) wss[i] = 0;
    for (i = 0; i < n; i++) wss[wv[i]]++;
    for (i = 1; i < m; i++) wss[i] += wss[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--wss[wv[i]]] = y[i];
    for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
      x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
  }
}
void calheight(int *r, int *sa, int n) {
  int i, j, k = 0;
  for (i = 1; i <= n; i++) Rank[sa[i]] = i;
  for (i = 0; i < n; height[Rank[i++]] = k)
    for (k ? k-- : 0, j = sa[Rank[i] - 1]; r[i + k] == r[j + k]; k++)
      ;
}
void rmq_init(int n) {
  d[0] = 1;
  for (int i = 1; i < 20; i++) d[i] = d[i - 1] * 2;
  for (int i = 2; i < N; i++) Log[i] = Log[i >> 1] + 1;
  for (int i = 1; i <= n; i++) f[i][0] = height[i];
  for (int j = 1; j < 20; j++) {
    for (int i = 1; i <= n; i++) {
      if (i + d[j] - 1 > n) continue;
      f[i][j] = min(f[i][j - 1], f[i + d[j - 1]][j - 1]);
    }
  }
}
inline int ask_rmq(int l, int r) {
  int k = r - l + 1;
  k = Log[k];
  return min(f[l][k], f[r - d[k] + 1][k]);
}
struct Node {
  int l, r, sum;
  Node() {}
} tree[N * 30];
int str[N];
int n, m, q, ans, a[N], b[N], sa[N];
int l[N], r[N], l1[N], r1[N], l2[N], r2[N], root[N], tot;
void Ins(int k, int &kk, int l, int r, int p) {
  if (kk == 0) kk = ++tot;
  if (l == r) {
    tree[kk].sum = 1;
    return;
  }
  int mid = l + r >> 1;
  if (p > mid) {
    tree[kk].l = tree[k].l;
    Ins(tree[k].r, tree[kk].r, mid + 1, r, p);
  } else {
    tree[kk].r = tree[k].r;
    Ins(tree[k].l, tree[kk].l, l, mid, p);
  }
  tree[kk].sum = tree[tree[kk].l].sum + tree[tree[kk].r].sum;
}
int Query(int k, int l, int r, int p, int q) {
  if (k == 0 || p > r || q < l) return 0;
  if (l >= p && r <= q) return tree[k].sum;
  int mid = l + r >> 1;
  return Query(tree[k].l, l, mid, p, q) + Query(tree[k].r, mid + 1, r, p, q);
}
int main() {
  n = read();
  for (int i = 0; i < n; i++) a[i] = read();
  n--;
  for (int i = 0; i < n; i++) b[i] = a[i] - a[i + 1];
  for (int i = n; i < n + n; i++) b[i] = -b[i - n];
  for (int i = 0; i < n + n; i++) a[i] = b[i];
  sort(a, a + n + n);
  m = unique(a, a + n + n) - a;
  for (int i = 0; i < n + n; i++) str[i] = lower_bound(a, a + m, b[i]) - a + 1;
  str[2 * n] = 0;
  da(str, sa, n + n + 1, m + 1);
  calheight(str, sa, 2 * n);
  rmq_init(n + n);
  q = read();
  int L, R, len, pos, ll, rr, mid;
  for (int i = 1; i <= q; i++) {
    L = read(), R = read();
    L -= 1;
    R -= 2;
    len = R - L + 1;
    if (L > R) {
      l[i] = 1;
      continue;
    }
    pos = Rank[L + n];
    if (height[pos] < len)
      l[i] = pos;
    else {
      ll = 1;
      rr = pos;
      while (ll < rr) {
        mid = ll + rr >> 1;
        if (ask_rmq(mid, pos) >= len)
          rr = mid;
        else
          ll = mid;
        if (ll + 1 == rr) {
          if (ask_rmq(ll, pos) >= len)
            rr--;
          else
            ll++;
        }
      }
      l[i] = ll - 1;
    }
    if (height[pos + 1] < len)
      r[i] = pos;
    else {
      ll = pos;
      rr = n + n;
      while (ll < rr) {
        mid = ll + rr >> 1;
        if (ask_rmq(pos + 1, mid) >= len)
          ll = mid;
        else
          rr = mid;
        if (ll + 1 == rr) {
          if (ask_rmq(pos + 1, rr) >= len)
            ll++;
          else
            rr--;
        }
      }
      r[i] = ll;
    }
    l1[i] = 0;
    r1[i] = L - len - 1;
    l2[i] = R + 2;
    r2[i] = n - len;
  }
  tot = 1;
  root[0] = 1;
  for (int i = 1; i <= n + n; i++)
    Ins(root[i - 1], root[i], 0, n + n - 1, sa[i]);
  for (int i = 1; i <= q; i++) {
    if (l[i] > r[i]) {
      printf("%d\n", n);
      continue;
    }
    ans = 0;
    if (l1[i] <= r1[i]) ans += Query(root[r[i]], 0, n + n - 1, l1[i], r1[i]);
    if (l2[i] <= r2[i]) ans += Query(root[r[i]], 0, n + n - 1, l2[i], r2[i]);
    if (l1[i] <= r1[i])
      ans -= Query(root[l[i] - 1], 0, n + n - 1, l1[i], r1[i]);
    if (l2[i] <= r2[i])
      ans -= Query(root[l[i] - 1], 0, n + n - 1, l2[i], r2[i]);
    printf("%d\n", ans);
  }
}
