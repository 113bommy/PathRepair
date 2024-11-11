#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <typename T>
using lim = numeric_limits<T>;
template <typename T>
istream& operator>>(istream& is, vector<T>& a) {
  for (T& x : a) {
    is >> x;
  }
  return is;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  set<pair<int, int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edges.insert({u, v});
  }
  vector<int> p(n + 1);
  iota(p.begin(), p.end(), 0);
  auto rng = default_random_engine();
  for (int i = 0; i < 100; i++) {
    shuffle(p.begin() + 1, p.end(), rng);
    bool valid = true;
    for (int i = 1; i <= m; i++) {
      valid &= not edges.count({p[i], p[i % n + 1]}) and
               not edges.count({p[i % n + 1], p[i]});
    }
    if (valid) {
      for (int i = 1; i <= m; i++) {
        cout << p[i] << " " << p[i % n + 1] << endl;
      }
      return 0;
    }
  };
  cout << -1 << endl;
  return 0;
}
