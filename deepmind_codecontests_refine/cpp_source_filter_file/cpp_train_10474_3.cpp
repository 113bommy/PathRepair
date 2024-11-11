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
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
const long long mxn = 2e5 + 10;
vector<long long> g[mxn];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long& i : a) cin >> i;
  long long idx = -1;
  for (long long i = 0; i < n; i++) {
    long long l = 0, r = idx;
    long long index = -1;
    while (l <= r) {
      long long m = (l + r) / 2;
      if (g[m].back() < a[i]) {
        index = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    debug() << " ["
            << "index"
               ": "
            << (index)
            << "] "
               " ["
            << "a[i]"
               ": "
            << (a[i]) << "] ";
    if (index == -1) index = idx + 1;
    g[index].push_back(a[i]);
    idx = max(idx, index);
  }
  for (long long i = 0; i <= idx; i++) {
    for (long long each : g[i]) cout << each << " ";
    cout << "\n";
  }
  return 0;
}
