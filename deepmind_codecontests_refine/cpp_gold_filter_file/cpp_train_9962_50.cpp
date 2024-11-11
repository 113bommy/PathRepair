#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
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
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int64_t t = 1;
  while (t--) {
    int64_t n;
    cin >> n;
    int64_t a[12] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};
    if (n <= 11)
      cout << a[n] << '\n';
    else
      cout << a[11] + (49 * (n - 11)) << '\n';
  }
  return 0;
}
