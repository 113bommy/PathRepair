#include <bits/stdc++.h>
#pragma GCC optimize("Ofast, unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native,avx2")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getrnd(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
template <typename T1, typename T2>
bool relax(T1& a, const T2& b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
bool strain(T1& a, const T2& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
const int N = 1e5 + 3;
int a[N], tree[4 * N], lazy[4 * N];
void upd(int v, int x) {
  tree[v] += x;
  lazy[v] += x;
}
void push(int v) {
  if (lazy[v]) {
    upd(2 * v, lazy[v]);
    upd(2 * v + 1, lazy[v]);
    lazy[v] = 0;
  }
}
void update(int v, int tl, int tr, int l, int r, int x) {
  if (l > r) return;
  if (tl == l && tr == r)
    upd(v, x);
  else {
    int tm = (tl + tr) / 2;
    push(v);
    update(2 * v, tl, tm, l, min(l, tm), x);
    update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, x);
    tree[v] = max(tree[2 * v], tree[2 * v + 1]);
  }
}
int get(int v, int tl, int tr) {
  if (tl == tr)
    return tree[v] > 0 ? tl : -1;
  else {
    int tm = (tl + tr) / 2;
    push(v);
    if (tree[2 * v] > 0)
      return get(2 * v, tl, tm);
    else if (tree[2 * v + 1] > 0)
      return get(2 * v + 1, tm + 1, tr);
    else
      return -1;
  }
}
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int p, t;
    cin >> p >> t;
    p = n - p;
    if (t == 0) {
      update(1, 0, n - 1, p, n - 1, -1);
    } else {
      int x;
      cin >> x;
      a[p] = x;
      update(1, 0, n - 1, p, n - 1, 1);
    }
    int pos = get(1, 0, n - 1);
    cout << (pos == -1 ? -1 : a[pos]) << '\n';
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  srand(time(0));
  int t = 1;
  while (t--) solve();
  return 0;
}
