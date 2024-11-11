#include <bits/stdc++.h>
using namespace std;
class dsu {
 public:
  vector<int> p;
  int n;
  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) { return (x == p[x] ? x : (p[x] = get(p[x]))); }
  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int t = 1, n, m, i, j, k, u, to, w;
  while (t--) {
    cin >> n;
    dsu uf(n);
    int ans = 0;
    vector<pair<int, int>> ed;
    for (i = 0; i < n - 1; i++) {
      cin >> u >> to;
      u--, to--;
      if (!uf.unite(u, to)) {
        ed.emplace_back(u, to);
        ans++;
      }
    }
    vector<int> p;
    for (i = 0; i < n; i++) {
      if (uf.get(i) == i) {
        p.push_back(i);
      }
    }
    cout << ans << '\n';
    assert(ans == p.size() - 1);
    for (i = 0; i < p.size() - 1; i++) {
      cout << ed[i].first + 1 << ' ' << ed[i].second + 1 << ' ';
      cout << p[i] + 1 << ' ' << p[i + 1] + 1 << '\n';
    }
  }
}
