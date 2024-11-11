#include <bits/stdc++.h>
using namespace std;
class kruskals {
 public:
  vector<int> p;
  vector<int> sz;
  kruskals(int n) {
    p.resize(n);
    sz.resize(n, 1);
    iota(p.begin(), p.end(), 0);
  }
  inline int find(int x) { return (x == p[x] ? x : (p[x] = find(p[x]))); }
  inline void unite(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (sz[a] > sz[b]) {
      p[b] = a;
      sz[a] += sz[b];
    } else {
      p[a] = b;
      sz[b] += sz[a];
    }
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  kruskals g(n);
  vector<tuple<int, int, int> > e;
  int u1, v1;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    if (i == 0)
      u1 = u, v1 = v;
    else
      e.push_back(make_tuple(w, u, v));
  }
  sort(e.begin(), e.end());
  for (auto x : e) {
    if (g.find(get<1>(x)) != g.find(get<2>(x))) {
      g.unite(get<1>(x), get<2>(x));
    }
    if (g.find(u1) == g.find(v1)) {
      cout << get<0>(x);
      return 0;
    }
  }
  cout << 1000000000;
  return 0;
}
