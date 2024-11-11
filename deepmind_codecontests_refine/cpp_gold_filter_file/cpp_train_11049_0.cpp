#include <bits/stdc++.h>
using namespace std;
template <typename Head>
inline void dout(Head in) {
  cerr << in << '\n';
}
struct dsu {
  vector<int> par;
  vector<int> _sz;
  int n;
  dsu(int N) : n(N) {
    par.resize(n);
    _sz.resize(n);
    fill(_sz.begin(), _sz.end(), 1);
    iota(par.begin(), par.end(), 0);
  }
  inline int get(int x) { return (x == par[x] ? x : (par[x] = get(par[x]))); }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      par[x] = y;
      _sz[y] += _sz[x];
      return true;
    }
    return false;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  function<bool(int)> lucky = [](int x) {
    bool ok = true;
    while (x) {
      ok &= x % 10 == 7 or x % 10 == 4;
      x /= 10;
    }
    return ok;
  };
  int n;
  cin >> n;
  dsu d(n);
  for (int i = 0; i < n - 1; i++) {
    int v, u, w;
    cin >> v >> u >> w;
    v--;
    u--;
    if (!lucky(w)) {
      d.unite(v, u);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int sz = d._sz[d.get(i)];
    ans += 1LL * (n - sz) * (n - sz - 1);
  }
  cout << ans;
  return 0;
}
