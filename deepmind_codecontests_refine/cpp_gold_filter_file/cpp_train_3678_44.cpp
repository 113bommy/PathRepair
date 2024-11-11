#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
class union_find {
 public:
  union_find(int n) : par_(n, -1) {}
  void init(int n) { par_.assign(n, -1); }
  int root(int x) { return par_[x] < 0 ? x : par_[x] = root(par_[x]); }
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) {
      return false;
    } else {
      if (par_[x] < par_[y]) {
        par_[x] += par_[y];
        par_[y] = x;
      } else {
        par_[y] += par_[x];
        par_[x] = y;
      }
      return true;
    }
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return -par_[root(x)]; }

 private:
  std::vector<int> par_;
};
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  union_find uf(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    uf.unite(a - 1, b - 1);
  }
  set<pii> s;
  for (int i = 0; i < n; ++i) {
    s.emplace(uf.root(i), uf.size(i));
  }
  const int c = s.size();
  if (c == 1) {
    cout << (1 % k) << endl;
    return 0;
  }
  ll ans = 1;
  for (int i = 0; i < c - 2; ++i) {
    ans = (ans * n) % k;
  }
  for (auto p : s) {
    ans = (ans * p.second) % k;
  }
  cout << ans << endl;
}
