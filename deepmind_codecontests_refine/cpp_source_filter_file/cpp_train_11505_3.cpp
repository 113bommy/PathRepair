#include <bits/stdc++.h>
using namespace std;
const int maxn = 101111;
struct node {
  int a[33];
  int x, t;
  node() {
    x = 0;
    t = 0;
  }
} seg[maxn << 2], tmp;
int n, q;
int a[maxn];
node Merge(node l, node r) {
  node ret;
  for (int _ = 0; _ < 2; _++) {
    for (int i = 0; i < l.t; i++) {
      int val = l.a[i];
      for (int j = 0; j < ret.t; j++) {
        if (val & ret.a[j] & -ret.a[j]) val ^= ret.a[j];
      }
      if (val) ret.a[ret.t++] = val;
    }
    swap(l, r);
  }
  return ret;
}
void PushDown(int rt) {
  if (!seg[rt].x) return;
  int nw = rt << 1;
  for (int _ = 0; _ < 2; _++) {
    seg[nw].x ^= seg[rt].x;
    for (int i = 0; i < seg[nw].t; i++) {
      if (seg[nw].a[i] & 1) seg[nw].a[i] ^= seg[rt].x;
    }
    nw |= 1;
  }
  seg[nw].x = 0;
}
void Update(int L, int R, int p, int l, int r, int rt) {
  if (L <= l && r <= R) {
    seg[rt].x ^= p;
    for (int i = 0; i < seg[rt].t; i++) {
      if (seg[rt].a[i] & 1) seg[rt].a[i] ^= p;
    }
    return;
  }
  int m = (l + r) >> 1;
  PushDown(rt);
  if (L <= m) Update(L, R, p, l, m, rt << 1);
  if (R > m) Update(L, R, p, m + 1, r, rt << 1 | 1);
  seg[rt] = Merge(seg[rt << 1], seg[rt << 1 | 1]);
}
node Query(int L, int R, int l, int r, int rt) {
  if (L <= l && r <= R) return seg[rt];
  PushDown(rt);
  int m = (l + r) >> 1;
  node ret;
  if (L <= m) ret = Merge(ret, Query(L, R, l, m, rt << 1));
  if (R > m) ret = Merge(ret, Query(L, R, m + 1, r, rt << 1 | 1));
  return ret;
}
void Build(int l, int r, int rt) {
  if (l == r) {
    seg[rt].a[0] = a[l];
    seg[rt].t = 1;
    return;
  }
  int m = (l + r) >> 1;
  Build(l, m, rt << 1);
  Build(m + 1, r, rt << 1 | 1);
  seg[rt] = Merge(seg[rt << 1], seg[rt << 1 | 1]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = a[i] * 2 + 1;
  }
  Build(1, n, 1);
  while (q--) {
    int t;
    int l, r, val;
    cin >> t;
    if (t == 1) {
      cin >> l >> r >> val;
      Update(l, r, val * 2, 1, n, 1);
    } else {
      cin >> l >> r;
      node ans = Query(l, r, 1, n, 1);
      for (int i = 0; i < ans.t; i++)
        if (ans.a[i] & 1) ans.a[i]--;
      cout << (1 << Merge(ans, tmp).t) << "\n";
    }
  }
  return 0;
}
