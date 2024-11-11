#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
struct ST {
  int l, r, num;
  ST() {}
  ST(int _l, int _r, int _num) {
    l = _l;
    r = _r;
    num = _num;
  }
};
int q, n;
string in;
ST st[4 * MAXN + 5];
void build(int id = 1, int l = 1, int r = n) {
  if (l > r) return;
  if (l == r) {
    if (in[l] == '(')
      st[id].l = 1;
    else if (in[l] == ')')
      st[id].r = 1;
    return;
  }
  int mid = (l + r) / 2;
  build(2 * id, l, mid);
  build(2 * id + 1, mid + 1, r);
  int l1 = st[2 * id].l, r1 = st[2 * id].r, num1 = st[2 * id].num;
  int l2 = st[2 * id + 1].l, r2 = st[2 * id + 1].r, num2 = st[2 * id + 1].num;
  int newNum = num1 + num2 + min(l1, r2);
  int newL = l1 + l2 - min(l1, r2);
  int newR = r1 + r2 - min(l1, r2);
  st[id] = ST(newL, newR, newNum);
  return;
}
ST get(int ls, int rs, int id = 1, int l = 1, int r = n) {
  if (l > rs || r < ls)
    return ST(0, 0, 0);
  else if (l >= ls && r <= rs)
    return st[id];
  int mid = (l + r) / 2;
  ST fi = get(ls, rs, 2 * id, l, mid), se = get(ls, rs, 2 * id + 1, mid + 1, r);
  int l1 = fi.l, r1 = fi.r, num1 = fi.num;
  int l2 = se.l, r2 = se.r, num2 = se.num;
  int newNum = num1 + num2 + min(l1, r2);
  int newL = l1 + l2 - min(l1, r2);
  int newR = r1 + r2 - min(l1, r2);
  return ST(newL, newR, newNum);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string tmp;
  cin >> tmp;
  in = '_' + tmp;
  n = in.length();
  build();
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    cout << 2 * get(l, r).num << endl;
  }
  return 0;
}
