#include <bits/stdc++.h>
using namespace std;
long long a[200005];
struct Seg_tree {
  struct node {
    long long v, lazy, mn, mx;
  } nd[4 * 200005];
  inline void push_up(int c) {
    nd[c].mn = min(nd[(c) << 1].mn, nd[(((c) << 1) | 1)].mn);
    nd[c].mx = max(nd[(c) << 1].mx, nd[(((c) << 1) | 1)].mx);
    nd[c].v = nd[(c) << 1].v + nd[(((c) << 1) | 1)].v;
  }
  inline void push_down(int c, int l, int r) {
    int mid = l + r >> 1;
    nd[(c) << 1].v = nd[c].lazy * (mid - l + 1);
    nd[(((c) << 1) | 1)].v = nd[c].lazy * (r - mid);
    nd[(c) << 1].mx = nd[(((c) << 1) | 1)].mx = nd[(c) << 1].lazy =
        nd[(((c) << 1) | 1)].lazy = nd[(((c) << 1) | 1)].mn = nd[(c) << 1].mn =
            nd[c].lazy;
    nd[c].lazy = 0;
  }
  void build(int c, int l, int r) {
    if (l == r) {
      nd[c].v = nd[c].mn = nd[c].mx = a[l];
      nd[c].lazy = 0;
      return;
    }
    int mid = l + r >> 1;
    build((c) << 1, l, mid);
    build((((c) << 1) | 1), mid + 1, r);
    push_up(c);
  }
  void modify_seg(int c, int l, int r, int L, int R, long long v) {
    if (nd[c].mn >= v) return;
    if (L <= l && R >= r && nd[c].mx <= v) {
      nd[c].mn = nd[c].mx = v;
      nd[c].v = v * (l - r + 1);
      nd[c].lazy = v;
      return;
    }
    if (nd[c].lazy) push_down(c, l, r);
    int mid = l + r >> 1;
    if (L <= mid) modify_seg((c) << 1, l, mid, L, R, v);
    if (R > mid) modify_seg((((c) << 1) | 1), mid + 1, r, L, R, v);
    push_up(c);
    return;
  }
  long long query(int c, int l, int r, int loc) {
    if (l == r) return nd[c].v;
    if (nd[c].lazy) push_down(c, l, r);
    int mid = l + r >> 1;
    if (loc <= mid)
      return query((c) << 1, l, mid, loc);
    else
      return query((((c) << 1) | 1), mid + 1, r, loc);
  }
  int sol(int c, int l, int r, int L, long long &v) {
    if (l >= L && nd[c].v <= v) {
      v -= nd[c].v;
      return r - l + 1;
    }
    if (nd[c].mn > v) return 0;
    if (nd[c].lazy) push_down(c, l, r);
    int mid = l + r >> 1, res = 0;
    if (mid >= L) res += sol((c) << 1, l, mid, L, v);
    res += sol((((c) << 1) | 1), mid + 1, r, L, v);
    return res;
  }
} T;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  T.build(1, 1, n);
  while (q--) {
    int op, x;
    long long y;
    cin >> op >> x >> y;
    if (op == 1) {
      T.modify_seg(1, 1, n, 1, x, y);
    } else {
      cout << T.sol(1, 1, n, x, y) << '\n';
    }
  }
  return 0;
}
