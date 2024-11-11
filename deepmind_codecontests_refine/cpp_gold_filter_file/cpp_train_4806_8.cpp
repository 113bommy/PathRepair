#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
const int mod = 998244353;
int deep[maxn];
struct Tree {
  int mxdp[maxn << 2], mndp[maxn << 2], lazy[maxn << 2], val[maxn << 2],
      chl[maxn << 2], chr[maxn << 2];
  void push(int rt) {
    if (lazy[rt] == 0) return;
    mxdp[(rt << 1)] += lazy[rt], mxdp[(rt << 1 | 1)] += lazy[rt];
    mndp[(rt << 1)] += lazy[rt], mndp[(rt << 1 | 1)] += lazy[rt];
    chl[(rt << 1)] -= lazy[rt], chl[(rt << 1 | 1)] -= lazy[rt];
    chr[(rt << 1)] -= lazy[rt], chr[(rt << 1 | 1)] -= lazy[rt];
    lazy[(rt << 1)] += lazy[rt], lazy[(rt << 1 | 1)] += lazy[rt];
    lazy[rt] = 0;
  }
  void maintain(int rt) {
    mxdp[rt] = max(mxdp[(rt << 1)], mxdp[(rt << 1 | 1)]);
    mndp[rt] = min(mndp[(rt << 1)], mndp[(rt << 1 | 1)]);
    chl[rt] = max(chl[(rt << 1)], chl[(rt << 1 | 1)]);
    chl[rt] = max(chl[rt], mxdp[(rt << 1)] - 2 * mndp[(rt << 1 | 1)]);
    chr[rt] = max(chr[(rt << 1)], chr[(rt << 1 | 1)]);
    chr[rt] = max(chr[rt], mxdp[(rt << 1 | 1)] - 2 * mndp[(rt << 1)]);
    val[rt] = max(val[(rt << 1)], val[(rt << 1 | 1)]);
    val[rt] = max(val[rt], max(chl[(rt << 1)] + mxdp[(rt << 1 | 1)],
                               mxdp[(rt << 1)] + chr[(rt << 1 | 1)]));
  }
  void update(int l, int r, int rt, int ql, int qr, int v) {
    if (ql <= l && qr >= r) {
      lazy[rt] += v;
      mxdp[rt] += v, mndp[rt] += v;
      chl[rt] -= v, chr[rt] -= v;
    } else {
      push(rt);
      int mid = l + r >> 1;
      if (ql <= mid) update(l, mid, (rt << 1), ql, qr, v);
      if (qr > mid) update(mid + 1, r, (rt << 1 | 1), ql, qr, v);
      maintain(rt);
    }
  }
  void build(int l, int r, int rt) {
    lazy[rt] = val[rt] = 0;
    if (l == r) {
      chl[rt] = chr[rt] = -deep[l];
      mxdp[rt] = mndp[rt] = deep[l];
      return;
    }
    int mid = l + r >> 1;
    build(l, mid, (rt << 1));
    build(mid + 1, r, (rt << 1 | 1));
    maintain(rt);
  }
  void pushAll(int l, int r, int rt) {
    if (l == r) {
    } else {
      int mid = l + r >> 1;
      push(rt);
      pushAll(l, mid, (rt << 1));
      pushAll(mid + 1, r, (rt << 1 | 1));
    }
  }
} T;
char s[maxn];
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, q, sz;
  cin >> n >> q;
  cin >> s + 1;
  sz = 2 * n - 2;
  int sum = 1;
  for (int i = 1; i <= sz; ++i) {
    sum += s[i] == '(' ? 1 : -1;
    deep[i] = sum;
  }
  T.build(1, sz, 1);
  cout << T.val[1] << '\n';
  while (q--) {
    int v, l, r;
    cin >> l >> r;
    v = s[l] == '(' ? -2 : 2;
    T.update(1, sz, 1, l, sz, v);
    v = s[r] == '(' ? -2 : 2;
    T.update(1, sz, 1, r, sz, v);
    swap(s[l], s[r]);
    cout << T.val[1] << '\n';
  }
  return 0;
}
