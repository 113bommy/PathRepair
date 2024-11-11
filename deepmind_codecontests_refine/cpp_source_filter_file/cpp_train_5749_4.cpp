#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = (1LL << 61);
ll mod = 1000000007;
struct UnionFind {
  vector<long long> par, vsize, esize;
  UnionFind(long long sz_) : par(sz_), vsize(sz_, 1), esize(sz_, 0) {
    for (long long i = 0; i < sz_; i++) par[i] = i;
  }
  void init(long long sz_) {
    par.resize(sz_);
    vsize.resize(sz_, 1);
    esize.resize(sz_, 0);
    for (long long i = 0; i < sz_; i++) par[i] = i;
  }
  long long root(long long x) {
    if (par[x] == x)
      return x;
    else
      return par[x] = root(par[x]);
  }
  bool merge(long long x, long long y) {
    x = root(x), y = root(y);
    if (x == y) {
      esize[x]++;
      return false;
    }
    if (vsize[x] < vsize[y]) swap(x, y);
    vsize[x] += vsize[y];
    esize[x] += esize[y] + 1;
    par[y] = x;
    return true;
  }
  bool issame(long long x, long long y) { return root(x) == root(y); }
  long long vs(long long x) { return vsize[root(x)]; }
  long long es(long long x) { return esize[root(x)]; }
};
void solve() {
  long long n;
  cin >> n;
  vector<vector<long long>> G(n);
  vector<long long> a(n), b;
  UnionFind uf(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
    if (a[i] != -1) {
      G[i].push_back(a[i]);
      uf.merge(i, a[i]);
    }
  }
  b = a;
  vector<long long> ind(n);
  for (long long i = 0; i < n; i++) {
    for (auto e : G[i]) {
      ind[e]++;
    }
  }
  set<long long> v;
  for (long long i = 0; i < n; i++) {
    if (ind[i] == 0) {
      v.insert(i);
    }
  }
  for (long long i = 0; i < n; i++) {
    if (a[i] == -1 && ind[i] > 0) {
      for (auto x : v) {
        if (i != x && !uf.issame(i, x)) {
          a[i] = x;
          v.erase(x);
          break;
        }
      }
    }
  }
  for (long long i = n - 1; i >= 0; i--) {
    if (a[i] == -1 && ind[i] == 0) {
      for (auto x : v) {
        if (i != x && !uf.issame(i, x)) {
          a[i] = x;
          v.erase(x);
          break;
        }
      }
    }
  }
  bool ok = true;
  for (long long i = 0; i < n; i++) {
    if (a[i] == -1) {
      a = b;
      ok = false;
    }
  }
  if (ok) {
    for (long long i = 0; i < n; i++) {
      cout << a[i] + 1 << " ";
    }
    cout << endl;
  } else {
    v.clear();
    for (long long i = 0; i < n; i++) {
      if (ind[i] == 0) {
        v.insert(i);
      }
    }
    for (long long i = 0; i < n; i++) {
      if (a[i] == -1 && ind[i] > 0) {
        for (auto x : v) {
          if (i != x && !uf.issame(i, x)) {
            a[i] = x;
            v.erase(x);
            break;
          }
        }
      }
    }
    for (long long i = 0; i < n; i++) {
      if (a[i] == -1 && ind[i] == 0) {
        for (auto x : v) {
          if (i != x && !uf.issame(i, x)) {
            a[i] = x;
            v.erase(x);
            break;
          }
        }
      }
    }
    for (long long i = 0; i < n; i++) {
      cout << a[i] + 1 << " ";
    }
    cout << endl;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  t = 1;
  for (long long _ = 0; _ < t; _++) {
    solve();
  }
  return 0;
}
