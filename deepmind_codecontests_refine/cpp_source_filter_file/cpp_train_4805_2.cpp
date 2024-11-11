#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node {
  int mn, mx, pre, suf, ans;
};
int n, q, x, y;
int a[N], lazy[4 * N];
string s;
node st[4 * N];
void push_down(int id, int l, int r) {
  if (lazy[id] != 0) {
    st[id].mn += lazy[id];
    st[id].mx += lazy[id];
    st[id].pre -= lazy[id];
    st[id].suf -= lazy[id];
    if (l < r) {
      lazy[2 * id] += lazy[id];
      lazy[2 * id + 1] += lazy[id];
    }
    lazy[id] = 0;
  }
}
node merge(node a, node b) {
  node res;
  res.mn = min(a.mn, b.mn);
  res.mx = max(a.mx, b.mx);
  res.pre = max(a.mx - 2 * b.mn, max(a.pre, b.pre));
  res.suf = max(-2 * a.mn + a.mx, max(a.suf, b.suf));
  res.ans = max(a.pre + b.mx, max(a.mx + b.suf, max(a.ans, b.ans)));
  return res;
}
void build(int id, int l, int r) {
  if (l == r) {
    st[id].mn = st[id].mx = a[l];
    st[id].pre = st[id].suf = -a[l];
    st[id].ans = -1e9;
    return;
  }
  int mid = (l + r) / 2;
  build(2 * id, l, mid);
  build(2 * id + 1, mid + 1, r);
  st[id] = merge(st[2 * id], st[2 * id + 1]);
}
void update(int id, int l, int r, int i, int j, int x) {
  push_down(id, l, r);
  if (l > j || r < i || i > j) {
    return;
  }
  if (l >= i && r <= j) {
    st[id].mn += x;
    st[id].mx += x;
    st[id].pre -= x;
    st[id].suf -= x;
    if (l < r) {
      lazy[2 * id] += x;
      lazy[2 * id + 1] += x;
    }
    return;
  }
  int mid = (l + r) / 2;
  update(2 * id, l, mid, i, j, x);
  update(2 * id + 1, mid + 1, r, i, j, x);
  st[id] = merge(st[2 * id], st[2 * id + 1]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q >> s;
  n = 2 * (n - 1);
  s = " " + s;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '(') {
      a[i] = a[i - 1] + 1;
    } else {
      a[i] = a[i - 1] - 1;
    }
  }
  build(1, 1, n);
  cout << st[1].ans << "\n";
  for (int i = 1; i <= q; i++) {
    cin >> x >> y;
    if (s[x] == '(') {
      update(1, 1, n, x, n, -1);
      update(1, 1, n, y, n, 1);
    } else {
      update(1, 1, n, x, n, 1);
      update(1, 1, n, y, n, -1);
    }
    if (s[y] == '(') {
      update(1, 1, n, y, n, -1);
      update(1, 1, n, x, n, 1);
    } else {
      update(1, 1, n, y, n, 1);
      update(1, 1, n, x, n, -1);
    }
    swap(s[x], s[y]);
    cout << st[1].ans << "\n";
  }
}
