#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct Query {
  int op, l, r;
} a[N];
int n, q, num[N * 2], f[N], lp[N], rp[N];
inline int getf(int v) { return f[v] == v ? v : f[v] = getf(f[v]); }
inline bool in(int x, int l, int r) { return l < x && x < r; }
struct TNode {
  int l, r;
  vector<int> v;
} t[N << 2];
inline int lc(int pos) { return pos << 1; }
inline int rc(int pos) { return pos << 1 | 1; }
void build(int pos, int l, int r) {
  t[pos].l = l;
  t[pos].r = r;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(lc(pos), l, mid);
  build(rc(pos), mid + 1, r);
}
void modify(int pos, int l, int r, int v) {
  if (t[pos].l == l && t[pos].r == r) {
    t[pos].v.push_back(v);
    return;
  }
  int mid = (t[pos].l + t[pos].r) >> 1;
  if (r <= mid)
    modify(lc(pos), l, r, v);
  else if (l > mid)
    modify(rc(pos), l, r, v);
  else
    modify(lc(pos), l, mid, v), modify(rc(pos), mid + 1, r, v);
}
void query(int pos, int p, int v) {
  if (!t[pos].v.empty()) {
    for (auto &i : t[pos].v) {
      int t = getf(i);
      f[t] = v;
      lp[v] = min(lp[v], lp[t]);
      rp[v] = max(rp[v], rp[t]);
    }
    t[pos].v.clear();
    t[pos].v.push_back(v);
  }
  if (t[pos].l == t[pos].r) return;
  int mid = (t[pos].l + t[pos].r) >> 1;
  if (p <= mid)
    query(lc(pos), p, v);
  else
    query(rc(pos), p, v);
}
int main() {
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> a[i].op >> a[i].l >> a[i].r;
    if (a[i].op == 1) num[++n] = a[i].l, num[++n] = a[i].r;
  }
  sort(num + 1, num + n + 1);
  n = unique(num + 1, num + n + 1) - num - 1;
  build(1, 1, n);
  int idx = 0;
  for (int i = 1; i <= q; i++)
    if (a[i].op == 1) {
      a[i].l = lower_bound(num + 1, num + n + 1, a[i].l) - num;
      a[i].r = lower_bound(num + 1, num + n + 1, a[i].r) - num;
      ++idx;
      f[idx] = idx;
      lp[idx] = a[i].l;
      rp[idx] = a[i].r;
      query(1, a[i].l, idx);
      query(1, a[i].r, idx);
      if (a[i].l < a[i].r - 1) modify(1, a[i].l + 1, a[i].r - 1, idx);
    } else {
      int t1 = getf(a[i].l), t2 = getf(a[i].r);
      cout << (t1 == t2 || in(lp[t1], lp[t2], rp[t2]) ||
                       in(lp[t2], lp[t1], rp[t1])
                   ? "YES"
                   : "NO")
           << endl;
    }
  return 0;
}
