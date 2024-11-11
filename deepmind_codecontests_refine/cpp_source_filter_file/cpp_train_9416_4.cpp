#include <bits/stdc++.h>
using namespace std;
const int inf = 1e7;
struct segtree {
  vector<long long> mn, cnt, ind, add;
  segtree(int n) {
    mn.assign(4 * n, inf), cnt.assign(4 * n, 0);
    add.assign(4 * n, 0), ind.assign(4 * n, -1);
  }
  int ls(int v) { return 2 * v + 1; }
  int rs(int v) { return 2 * v + 2; }
  void push(int v) {
    if (ls(v) >= mn.size()) return;
    add[ls(v)] += add[v];
    add[rs(v)] += add[v];
    add[v] = 0;
  }
  void update(int v) {
    if (mn[ls(v)] + add[ls(v)] == mn[rs(v)] + add[rs(v)]) {
      mn[v] = mn[ls(v)] + add[ls(v)];
      ind[v] = ind[ls(v)], cnt[v] = cnt[ls(v)] + cnt[rs(v)];
    } else if (mn[ls(v)] + add[ls(v)] < mn[rs(v)] + add[rs(v)]) {
      mn[v] = mn[ls(v)] + add[ls(v)];
      ind[v] = ind[ls(v)];
      cnt[v] = cnt[ls(v)];
    } else {
      mn[v] = mn[rs(v)] + add[rs(v)];
      ind[v] = ind[rs(v)], cnt[v] = cnt[rs(v)];
    }
  }
  void build(int v, int l, int r, vector<long long>& a) {
    if (l == r - 1) {
      mn[v] = a[l], ind[v] = l, cnt[v] = 1;
      return;
    }
    int md = (l + r) / 2;
    build(ls(v), l, md, a);
    build(rs(v), md, r, a);
    update(v);
  }
  void add_val(int v, int l, int r, int ql, int qr, int x) {
    if (l >= qr || r <= ql) return;
    if (l >= ql && r <= qr) {
      add[v] += x;
      return;
    }
    push(v);
    int m = (l + r) / 2;
    add_val(ls(v), l, m, ql, qr, x);
    add_val(rs(v), m, r, ql, qr, x);
    update(v);
  }
  int get_cnt(int v, int l, int r, int ql, int qr, int mv) {
    if (l >= qr || r <= ql) return 0;
    if (l >= ql && r <= qr) {
      return (mn[v] + add[v] == mv ? cnt[v] : 0);
    }
    push(v);
    int m = (l + r) / 2;
    int q1 = get_cnt(ls(v), l, m, ql, qr, mv);
    int q2 = get_cnt(rs(v), m, r, ql, qr, mv);
    update(v);
    return q1 + q2;
  }
  int get_mn_ind() { return ind[0]; }
  int get_mn() { return mn[0]; }
  int get_val(int v, int l, int r, int i) {
    if (l == r - 1) {
      return mn[v] + add[v];
    }
    push(v);
    int m = (l + r) / 2;
    int res = 0;
    if (i < m) {
      res = get_val(ls(v), l, m, i);
    } else
      res = get_val(rs(v), m, r, i);
    update(v);
    return res;
  }
};
void print(segtree& sg, int n) {
  for (int i = 0; i < n; ++i) {
    cout << sg.get_val(0, 0, n, i) << " ";
  }
  cout << "\n\n";
}
int main() {
  int n, m, len;
  cin >> n >> m >> len;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  segtree sg(n + 1);
  sg.build(0, 0, n, a);
  for (int i = 0; i < m; ++i) {
    int ind = sg.get_mn_ind(), mn = sg.get_mn();
    int c1 = sg.get_cnt(0, 0, n, ind, min(ind + len, n), mn);
    int c2 = sg.get_cnt(0, 0, n, max(0, ind - len + 1), ind + 1, mn);
    if (c1 > c2) {
      sg.add_val(0, 0, n, ind, min(ind + len, n), 1);
    } else if (c1 < c2) {
      sg.add_val(0, 0, n, max(0, ind - len + 1), ind + 1, 1);
    } else if (min(n, ind + n) - ind > ind + 1 - max(0, ind - len + 1)) {
      sg.add_val(0, 0, n, ind, min(ind + len, n), 1);
    } else {
      sg.add_val(0, 0, n, max(0, ind - len + 1), ind + 1, 1);
    }
  }
  cout << sg.get_mn();
  return 0;
}
