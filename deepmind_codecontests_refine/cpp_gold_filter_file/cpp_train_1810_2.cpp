#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chkmin(T& a, T b) {
  return a > b ? a = b, true : false;
}
template <class T>
bool chkmax(T& a, T b) {
  return a < b ? a = b, true : false;
}
int gmax(int& v, int a, int b) { return a > b ? (v = a, 1) : (v = b, 0); }
int gmin(int& v, int a, int b) { return a < b ? (v = a, 1) : (v = b, 0); }
void _swap(int& a, int& b) {
  swap(a, b);
  a = -a;
  b = -b;
}
const int maxN = 1e5 + 4;
int a[maxN], n;
namespace seg {
const int SIZE = maxN << 2;
struct node {
  int pre_mx, pre_mx_p;
  int pre_mn, pre_mn_p;
  int suf_mn, suf_mn_p;
  int suf_mx, suf_mx_p;
  int mx, mx_l, mx_r;
  int mn, mn_l, mn_r;
  int sum;
  void init() {
    pre_mx = pre_mx_p = pre_mn = pre_mn_p = suf_mn = suf_mn_p = suf_mx =
        suf_mx_p = mx = mx_l = mx_r = mn = mn_l = mn_r = sum = 0;
  }
  friend node operator+(const node& a, const node& b) {
    static node ret;
    ret.init();
    ret.sum = a.sum + b.sum;
    ret.pre_mx_p =
        gmax(ret.pre_mx, b.pre_mx, a.pre_mx + b.sum) ? b.pre_mx_p : a.pre_mx_p;
    ret.pre_mn_p =
        gmin(ret.pre_mn, b.pre_mn, a.pre_mn + b.sum) ? b.pre_mn_p : a.pre_mn_p;
    ret.suf_mx_p =
        gmax(ret.suf_mx, a.suf_mx, b.suf_mx + a.sum) ? a.suf_mx_p : b.suf_mx_p;
    ret.suf_mn_p =
        gmin(ret.suf_mn, a.suf_mn, b.suf_mn + a.sum) ? a.suf_mn_p : b.suf_mn_p;
    bool flag = gmax(ret.mx, a.mx, b.mx);
    ret.mx_l = flag ? a.mx_l : b.mx_l;
    ret.mx_r = flag ? a.mx_r : b.mx_r;
    flag = gmin(ret.mn, a.mn, b.mn);
    ret.mn_l = flag ? a.mn_l : b.mn_l;
    ret.mn_r = flag ? a.mn_r : b.mn_r;
    if (chkmax(ret.mx, a.pre_mx + b.suf_mx))
      ret.mx_l = a.pre_mx_p, ret.mx_r = b.suf_mx_p;
    if (chkmin(ret.mn, a.pre_mn + b.suf_mn))
      ret.mn_l = a.pre_mn_p, ret.mn_r = b.suf_mn_p;
    return ret;
  }
} tr[SIZE];
bool lazy[SIZE];
int ql, qr, v;
void build_tree(int now, int l, int r) {
  if (l == r) {
    tr[now].mx = tr[now].mn = tr[now].pre_mx = tr[now].pre_mn = tr[now].suf_mx =
        tr[now].suf_mn = tr[now].sum = a[l];
    tr[now].mx_l = tr[now].mx_r = tr[now].mn_l = tr[now].mn_r =
        tr[now].pre_mx_p = tr[now].pre_mn_p = tr[now].suf_mx_p =
            tr[now].suf_mn_p = l;
    return;
  }
  build_tree((now << 1), l, ((l + r) >> 1));
  build_tree((now << 1 | 1), ((l + r) >> 1) + 1, r);
  tr[now] = tr[(now << 1)] + tr[(now << 1 | 1)];
}
void tagrev(int now) {
  _swap(tr[now].pre_mx, tr[now].pre_mn);
  _swap(tr[now].suf_mx, tr[now].suf_mn);
  _swap(tr[now].mx, tr[now].mn);
  swap(tr[now].pre_mx_p, tr[now].pre_mn_p);
  swap(tr[now].suf_mx_p, tr[now].suf_mn_p);
  swap(tr[now].mx_l, tr[now].mn_l);
  swap(tr[now].mx_r, tr[now].mn_r);
  tr[now].sum = -tr[now].sum;
  lazy[now] ^= 1;
}
void pushdown(int now) {
  if (lazy[now]) {
    tagrev((now << 1));
    tagrev((now << 1 | 1));
    lazy[now] = 0;
  }
}
node query(int now, int l, int r) {
  if (ql <= l && qr >= r) return tr[now];
  pushdown(now);
  node ret;
  if (ql <= ((l + r) >> 1)) ret = query((now << 1), l, ((l + r) >> 1));
  if (qr > ((l + r) >> 1)) {
    if (ql <= ((l + r) >> 1)) {
      ret = ret + query((now << 1 | 1), ((l + r) >> 1) + 1, r);
    } else
      ret = query((now << 1 | 1), ((l + r) >> 1) + 1, r);
  }
  return ret;
}
void _modify(int now, int l, int r) {
  if (ql <= l && qr >= r) {
    tagrev(now);
    return;
  }
  pushdown(now);
  if (ql <= ((l + r) >> 1)) _modify((now << 1), l, ((l + r) >> 1));
  if (qr > ((l + r) >> 1)) _modify((now << 1 | 1), ((l + r) >> 1) + 1, r);
  tr[now] = tr[(now << 1)] + tr[(now << 1 | 1)];
}
void _change(int now, int l, int r) {
  if (l == r) {
    tr[now].mx = v;
    tr[now].mn = v;
    tr[now].pre_mn = v;
    tr[now].pre_mx = v;
    tr[now].suf_mn = v;
    tr[now].suf_mx = v;
    tr[now].sum = v;
    return;
  }
  pushdown(now);
  if (ql <= ((l + r) >> 1))
    _change((now << 1), l, ((l + r) >> 1));
  else
    _change((now << 1 | 1), ((l + r) >> 1) + 1, r);
  tr[now] = tr[(now << 1)] + tr[(now << 1 | 1)];
}
inline pair<int, pair<int, int> > getmax(int l, int r) {
  ql = l;
  qr = r;
  node ret = query(1, 1, n);
  return make_pair(ret.mx, make_pair(ret.mx_l, ret.mx_r));
}
inline void modify(int l, int r) {
  ql = l;
  qr = r;
  _modify(1, 1, n);
}
inline void change(int first, int val) {
  ql = qr = first;
  v = val;
  _change(1, 1, n);
}
}  // namespace seg
int main() {
  scanf("%d", &n);
  for (int i = (1), _ = (n); i <= _; ++i) scanf("%d", &a[i]);
  seg::build_tree(1, 1, n);
  static pair<int, int> stk[maxN];
  int m, tp = 0;
  scanf("%d", &m);
  for (int i = (1), _ = (m); i <= _; ++i) {
    int type, l, r, k, ans = 0;
    scanf("%d", &type);
    if (type) {
      scanf("%d%d%d", &l, &r, &k);
      tp = 0;
      for (int j = (1), _ = (k); j <= _; ++j) {
        pair<int, pair<int, int> > ret = seg::getmax(l, r);
        if (ret.first <= 0) break;
        ans += ret.first;
        stk[++tp] = make_pair(ret.second.first, ret.second.second);
        seg::modify(stk[tp].first, stk[tp].second);
      }
      while (tp) {
        seg::modify(stk[tp].first, stk[tp].second);
        --tp;
      }
      printf("%d\n", ans);
    } else {
      int u, first;
      scanf("%d%d", &u, &first);
      seg::change(u, first);
    }
  }
  return 0;
}
