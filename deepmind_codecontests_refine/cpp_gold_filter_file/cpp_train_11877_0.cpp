#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, s; cin >> n >> s;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  V<lint> c(n + 1); for (int i = 0; i < n; ++i) c[i + 1] = c[i] + a[i];
  int res = 1e9;
  for (int i = 0; i < n; ++i) {
    auto itr = lower_bound(begin(c), end(c), s + c[i]);
    if (itr != end(c)) res = min<int>(res, distance(next(begin(c), i), itr));
  }
  cout << (res != 1e9 ? res : 0) << '\n';
}
