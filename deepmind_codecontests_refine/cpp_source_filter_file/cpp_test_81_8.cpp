#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + c - '0';
  x *= f;
}
int n, d;
int a[N], s[N];
int b[N], tot;
int v[N], f[N];
int bit[N];
vector<int> T1[N], T2[N], T3[N], T4[N];
void upd(int o, int x) {
  for (; o <= tot; o += o & -o) bit[o] += x;
}
int ask(int l, int r) {
  int res = 0;
  for (int o = r; o; o -= o & -o) res += bit[o];
  for (int o = l - 1; o; o -= o & -o) res -= bit[o];
  return res;
}
struct misaka {
  int tagmax, tagadd;
} seg[N << 2];
void pushdown(int u) {
  seg[(u << 1)].tagmax =
      max(seg[(u << 1)].tagmax, seg[u].tagmax - seg[(u << 1)].tagadd);
  seg[(u << 1)].tagadd += seg[u].tagadd;
  seg[(u << 1 | 1)].tagmax =
      max(seg[(u << 1 | 1)].tagmax, seg[u].tagmax - seg[(u << 1 | 1)].tagadd);
  seg[(u << 1 | 1)].tagadd += seg[u].tagadd;
  seg[u].tagadd = seg[u].tagmax = 0;
}
void build(int u, int l, int r, int k) {
  if (l == r) {
    seg[u].tagmax = k;
    return;
  }
  int mid = l + r >> 1;
  build((u << 1), l, mid, k);
  build((u << 1 | 1), mid + 1, r, k);
}
void update(int u, int l, int r, int ql, int qr, int k) {
  if (l >= ql && r <= qr) {
    seg[u].tagadd += k;
    return;
  }
  pushdown(u);
  int mid = l + r >> 1;
  if (ql <= mid) update((u << 1), l, mid, ql, qr, k);
  if (qr > mid) update((u << 1 | 1), mid + 1, r, ql, qr, k);
}
void modify(int u, int l, int r, int ql, int qr, int k) {
  if (l >= ql && r <= qr) {
    seg[u].tagmax = max(seg[u].tagmax, k - seg[u].tagadd);
    return;
  }
  pushdown(u);
  int mid = l + r >> 1;
  if (ql <= mid) modify((u << 1), l, mid, ql, qr, k);
  if (qr > mid) modify((u << 1 | 1), mid + 1, r, ql, qr, k);
}
int query(int u, int l, int r, int x) {
  if (l == r) return seg[u].tagadd + seg[u].tagmax;
  pushdown(u);
  int mid = l + r >> 1;
  if (x <= mid)
    return query((u << 1), l, mid, x);
  else
    return query((u << 1 | 1), mid + 1, r, x);
}
int main() {
  read(n), read(d);
  for (int i = 1; i <= n; i++) read(s[i]), read(a[i]);
  for (int i = 1; i <= n; i++) b[++tot] = s[i];
  for (int i = 1; i <= n; i++) b[++tot] = a[i];
  b[++tot] = d;
  sort(b + 1, b + tot + 1);
  tot = unique(b + 1, b + tot + 1) - b - 1;
  for (int i = 1; i <= n; i++) s[i] = lower_bound(b + 1, b + tot + 1, s[i]) - b;
  for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + tot + 1, a[i]) - b;
  d = lower_bound(b + 1, b + tot + 1, d) - b;
  for (int i = 1; i <= n; i++) {
    if (s[i] < a[i]) {
      T1[a[i]].push_back(i);
      T2[s[i]].push_back(i);
    } else
      T3[a[i]].push_back(i);
    T4[s[i]].push_back(i);
  }
  int w;
  for (int i = tot; i >= 1; i--) {
    for (int j = 0; j < T4[i].size(); j++) upd(a[T4[i][j]], 1);
    for (int j = 0; j < T1[i].size(); j++)
      v[T1[i][j]] = ask(s[T1[i][j]] + 1, a[T1[i][j]]);
    if (i == d) w = ask(1, i);
  }
  build(1, 1, tot, w);
  for (int i = d + 1; i <= tot; i++) {
    for (int j = 0; j < T2[i - 1].size(); j++)
      f[a[T2[i - 1][j]]] =
          max(f[a[T2[i - 1][j]]],
              query(1, 1, tot, a[T2[i - 1][j]]) + v[T2[i - 1][j]] + 1);
    for (int j = 0; j < T3[i].size(); j++) update(1, 1, tot, 1, s[T3[i][j]], 1);
    f[i] = max(f[i], query(1, 1, tot, i));
    modify(1, 1, tot, i, tot, f[i]);
  }
  int ans = 0;
  for (int i = 1; i <= tot; i++) ans = max(ans, f[i]);
  printf("%d\n", ans);
  return 0;
}
