#include <bits/stdc++.h>
using namespace std;
struct pt {
  int x, y, id;
  friend pt operator+(const pt& a, const pt& b) {
    return {a.x + b.x, a.y + b.y};
  }
  friend pt operator-(const pt& a, const pt& b) {
    return {a.x - b.x, a.y - b.y};
  }
  friend long long operator*(const pt& a, const pt& b) {
    return 1LL * a.x * b.y - 1LL * a.y * b.x;
  }
  friend long long operator%(const pt& a, const pt& b) {
    return 1LL * a.x * b.x + 1LL * a.y * b.y;
  }
};
struct SegTree {
  int n;
  SegTree() {}
};
const int N = 500005;
int r, n, t[N], x[N], y[N], sz;
pt a[N];
int ps[N];
pt tree[4 * N], lf, rt;
pt up(const pt& a, const pt& b) { return (a - rt) * (b - rt) > 0 ? a : b; }
void build(int v, int tl, int tr) {
  if (tl == tr) {
    tree[v] = lf;
    return;
  }
  int tm = (tl + tr) / 2;
  build(2 * v, tl, tm);
  build(2 * v + 1, tm + 1, tr);
  tree[v] = up(tree[2 * v], tree[2 * v + 1]);
}
pt go(int v, int tl, int tr, int l, int r) {
  if (l > r || l > tr || r < tl) return lf;
  if (l <= tl && r >= tr) return tree[v];
  int tm = (tl + tr) / 2;
  return up(go(2 * v, tl, tm, l, r), go(2 * v + 1, tm + 1, tr, l, r));
}
void update(int v, int tl, int tr, int pos, pt val) {
  if (tl == tr) {
    tree[v] = val;
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos <= tm) {
    update(2 * v, tl, tm, pos, val);
  } else {
    update(2 * v + 1, tm + 1, tr, pos, val);
  }
  tree[v] = up(tree[2 * v], tree[2 * v + 1]);
}
void add(int id) { update(1, 0, sz - 1, ps[id], a[ps[id]]); }
void remove(int id) { update(1, 0, sz - 1, ps[id], lf); }
bool go(int x, int y) {
  pt f = a[ps[x]];
  pt s = a[ps[y]];
  pt lf = {-r, 0};
  pt rt = {+r, 0};
  pt first = (f - lf) * (s - lf) > 0 ? (f - lf) : (s - lf);
  pt second = (f - rt) * (s - rt) < 0 ? (f - rt) : (s - rt);
  if (first % second < 0) return false;
  int l = -1, r = sz;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (first * (a[m] - lf) < 0)
      l = m;
    else
      r = m;
  }
  remove(x);
  remove(y);
  auto here = go(1, 0, sz - 1, r, sz - 1);
  here = here - rt;
  add(x);
  add(y);
  if (here * second >= 0) return false;
  return true;
}
void solve() {
  cin >> r >> n;
  for (int i = 0; i < (n); ++i) {
    cin >> t[i] >> x[i];
    if (t[i] != 2) cin >> y[i];
    if (t[i] == 1) {
      a[sz] = {x[i], y[i], sz};
      ++sz;
      x[i] = sz;
    }
    --x[i];
    --y[i];
  }
  lf = {-r, 0};
  rt = {+r, 0};
  sort(a, a + sz,
       [](const pt& a, const pt& b) { return (a - lf) * (b - lf) > 0; });
  for (int i = 0; i < (sz); ++i) ps[a[i].id] = i;
  build(1, 0, sz - 1);
  for (int i = 0; i < (n); ++i) {
    if (t[i] == 1) {
      add(x[i]);
    }
    if (t[i] == 2) {
      remove(x[i]);
    }
    if (t[i] == 3) {
      cout << (go(x[i], y[i]) ? "YES" : "NO") << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  for (int i = 0; i < (t); ++i) solve();
  return 0;
}
