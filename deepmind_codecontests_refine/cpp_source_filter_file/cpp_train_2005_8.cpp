#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug &operator<<(const c &) {
    return *this;
  }
};
void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  vector<int> res;
  for (int i = 0; i < a.length(); ++i) {
    if (a[i] != b[i]) {
      if (i > 0) res.push_back(i + 1);
      res.push_back(i + 1);
      if (i > 0) res.push_back(i + 1);
    }
  }
  cout << (int)res.size() << ' ';
  for (long long i = 0; i < int((int)res.size()); i++) cout << res[i] << ' ';
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
