#include <bits/stdc++.h>
using namespace std;
const int N = 200200;
const int mod = 1e9 + 7;
int n, q;
int a[N];
int ty, l1, r1, l2, r2;
long double t[8 * N];
long double add[8 * N];
long double mult[8 * N];
int nadd[8 * N];
int nmult[8 * N];
inline void build(int v, int tl, int tr) {
  if (tl == tr) {
    mult[v] = 1;
    t[v] = a[tl];
    add[v] = 0;
    return;
  }
  int tm = tl + tr >> 1;
  build(v + v, tl, tm);
  build(v + v + 1, tm + 1, tr);
  mult[v] = 1;
  add[v] = 0;
  t[v] = t[v + v] + t[v + v + 1];
}
inline void push(int v, int tl, int tr) {
  if (nmult[v]) {
    mult[v + v] *= mult[v];
    mult[v + v + 1] *= mult[v];
    add[v + v] *= mult[v];
    add[v + v + 1] *= mult[v];
    t[v + v] *= mult[v];
    t[v + v + 1] *= mult[v];
    mult[v] = 1;
    nmult[v + v] = nmult[v + v + 1] = 1;
    nmult[v] = 0;
  }
  if (nadd[v]) {
    add[v + v] += add[v];
    add[v + v + 1] = add[v];
    int tm = tl + tr >> 1;
    t[v + v] += add[v] * (tm - tl + 1);
    t[v + v + 1] += add[v] * (tr - tm);
    nadd[v + v] = nadd[v + v + 1] = 1;
    nadd[v] = 0;
    add[v] = 0;
  }
}
inline void upd2(int v, int tl, int tr, int l, int r, long double x) {
  if (l > r) return;
  if (tl == l && tr == r) {
    mult[v] *= x;
    nmult[v] = 1;
    t[v] *= x;
    add[v] *= x;
    return;
  }
  int tm = tl + tr >> 1;
  push(v, tl, tr);
  upd2(v + v, tl, tm, l, min(r, tm), x);
  upd2(v + v + 1, tm + 1, tr, max(tm + 1, l), r, x);
  t[v] = t[v + v] + t[v + v + 1];
}
inline void upd1(int v, int tl, int tr, int l, int r, long double x) {
  if (l > r) return;
  if (tl == l && tr == r) {
    nadd[v] = 1;
    add[v] += x;
    t[v] += x * (r - l + 1);
    return;
  }
  push(v, tl, tr);
  int tm = tl + tr >> 1;
  upd1(v + v, tl, tm, l, min(r, tm), x);
  upd1(v + v + 1, tm + 1, tr, max(tm + 1, l), r, x);
  t[v] = t[v + v] + t[v + v + 1];
}
inline long double get(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (tl == l && tr == r) return t[v];
  int tm = tl + tr >> 1;
  push(v, tl, tr);
  return get(v + v, tl, tm, l, min(r, tm)) +
         get(v + v + 1, tm + 1, tr, max(tm + 1, l), r);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  build(1, 1, n);
  cout.precision(8);
  for (int i = 1; i <= q; ++i) {
    cin >> ty;
    if (ty == 1) {
      cin >> l1 >> r1 >> l2 >> r2;
      int len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
      long double fi = get(1, 1, n, l1, r1);
      long double se = get(1, 1, n, l2, r2);
      upd2(1, 1, n, l1, r1, (len1 - 1.0L) / len1);
      upd2(1, 1, n, l2, r2, (len2 - 1.0L) / len2);
      upd1(1, 1, n, l1, r1, se / len1 / len2);
      upd1(1, 1, n, l2, r2, fi / len1 / len2);
    } else {
      cin >> l1 >> r1;
      cout << fixed << (double)get(1, 1, n, l1, r1) << '\n';
    }
  }
  return 0;
}
