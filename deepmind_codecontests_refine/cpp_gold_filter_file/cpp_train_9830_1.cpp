#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int v_, l_, r_;
} tnode_t;
tnode_t lstree[1 << 22];
char s[1000002];
int n, m;
void build(int nidx, int left, int right) {
  if (left == right) {
    lstree[nidx].v_ = 0;
    lstree[nidx].l_ = s[left] == ')' ? 1 : 0;
    lstree[nidx].r_ = s[left] == '(' ? 1 : 0;
  } else {
    int mid = ((left + right) >> 1), ln = (nidx << 1), rn = (nidx << 1) + 1;
    build(ln, left, mid);
    build(rn, mid + 1, right);
    lstree[nidx].l_ = lstree[ln].l_ + max(0, lstree[rn].l_ - lstree[ln].r_);
    lstree[nidx].r_ = lstree[rn].r_ + max(0, lstree[ln].r_ - lstree[rn].l_);
    lstree[nidx].v_ =
        lstree[ln].v_ + lstree[rn].v_ + min(lstree[ln].r_, lstree[rn].l_);
  }
}
void adjust(int nidx, int l, int r, int p) {
  if (l == r) {
    s[p] = s[p] == ')' ? '(' : ')';
    lstree[nidx].v_ = 0;
    lstree[nidx].l_ = s[p] == ')' ? 1 : 0;
    lstree[nidx].r_ = s[p] == '(' ? 1 : 0;
  } else {
    int mid = (l + r) >> 1, ln = (nidx << 1), rn = (nidx << 1) + 1;
    if (p > mid)
      adjust(rn, mid + 1, r, p);
    else
      adjust(ln, l, mid, p);
    lstree[nidx].l_ = lstree[ln].l_ + max(0, lstree[rn].l_ - lstree[ln].r_);
    lstree[nidx].r_ = lstree[rn].r_ + max(0, lstree[ln].r_ - lstree[rn].l_);
    lstree[nidx].v_ =
        lstree[ln].v_ + lstree[rn].v_ + min(lstree[ln].r_, lstree[rn].l_);
  }
}
tnode_t query(int nidx, int l, int r, int ql, int qr) {
  if (l == ql && r == qr) return lstree[nidx];
  int mid = (l + r) >> 1, ln = (nidx << 1), rn = (nidx << 1) + 1;
  if (ql > mid) return query(rn, mid + 1, r, ql, qr);
  if (qr <= mid) return query(ln, l, mid, ql, qr);
  tnode_t lr = query(ln, l, mid, ql, mid),
          rr = query(rn, mid + 1, r, mid + 1, qr), res;
  res.l_ = lr.l_ + max(0, rr.l_ - lr.r_);
  res.r_ = rr.r_ + max(0, lr.r_ - rr.l_);
  res.v_ = lr.v_ + rr.v_ + min(lr.r_, rr.l_);
  return res;
}
int main(int argc, char **argv) {
  std::ios::sync_with_stdio(false);
  cin >> (s + 1) >> m;
  n = strlen(s + 1);
  build(1, 1, n);
  for (int i = 1, l, r; i <= m; i++) {
    cin >> l >> r;
    if (l == 0)
      adjust(1, 1, n, r);
    else
      cout << (query(1, 1, n, l, r).v_ << 1) << endl;
  }
  return 0;
}
