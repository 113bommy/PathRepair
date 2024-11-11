#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
const int MOD = 1e9 + 7;
int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
  return a;
}
int mul(int a, int b) { return 1LL * a * b % MOD; }
const int N = 2e5 + 3;
int n;
ll tree[4 * N], mtree[4 * N];
void build(int v, int tl, int tr, vector<ll>& a, vector<ll>& b) {
  if (tl == tr) {
    tree[v] = a[tl];
    mtree[v] = mul(a[tl], b[tl]);
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm, a, b);
    build(2 * v + 1, tm + 1, tr, a, b);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
    mtree[v] = add(mtree[2 * v], mtree[2 * v + 1]);
  }
}
void update(int v, int tl, int tr, int pos, ll x, vector<ll>& b) {
  if (tl == tr) {
    tree[v] = x;
    mtree[v] = mul(b[tl], x);
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      update(2 * v, tl, tm, pos, x, b);
    else
      update(2 * v + 1, tm + 1, tr, pos, x, b);
    tree[v] = tree[2 * v] + tree[2 * v + 1];
    mtree[v] = add(mtree[2 * v], mtree[2 * v + 1]);
  }
}
ll get(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (tl == l && tr == r)
    return tree[v];
  else {
    int tm = (tl + tr) / 2;
    return get(2 * v, tl, tm, l, min(r, tm)) +
           get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
  }
}
ll getm(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (tl == l && tr == r)
    return mtree[v];
  else {
    int tm = (tl + tr) / 2;
    return add(getm(2 * v, tl, tm, l, min(r, tm)),
               getm(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
  }
}
int find(int v, int tl, int tr, int l, int r, ll x) {
  if (l > r) return -1;
  if (tl == tr)
    return tl;
  else {
    int tm = (tl + tr) / 2;
    ll s = get(1, 0, n - 1, l, tm);
    if (s >= x)
      return find(2 * v, tl, tm, l, min(r, tm), x);
    else
      return find(2 * v + 1, tm + 1, tr, max(tm + 1, l), r, x - s);
  }
}
void solve() {
  int q;
  cin >> n >> q;
  vector<ll> a(n), w(n), y(n);
  for (int i = 0; i < n; ++i) cin >> a[i], y[i] = add(a[i], -i);
  for (int i = 0; i < n; ++i) cin >> w[i];
  build(1, 0, n - 1, w, y);
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (l < 0) {
      update(1, 0, n - 1, -l - 1, r, y);
    } else {
      --l;
      --r;
      ll s = get(1, 0, n - 1, l, r);
      int pos = find(1, 0, n - 1, l, r, s / 2);
      assert(pos != -1);
      ll x = y[pos];
      ll res =
          add(-getm(1, 0, n - 1, l, pos - 1), getm(1, 0, n - 1, pos + 1, r));
      res = add(res, mul(add(get(1, 0, n - 1, l, pos - 1) % MOD,
                             -(get(1, 0, n - 1, pos + 1, r) % MOD)),
                         x));
      cout << res << '\n';
    }
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
