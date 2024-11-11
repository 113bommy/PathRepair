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
void solve() {
  int n, r, avg;
  cin >> n >> r >> avg;
  vector<pair<int, int>> v(n);
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    v[i] = {b, a};
    sum += a;
  }
  sort(v.begin(), v.end());
  long long res = 0;
  int idx = 0;
  while (sum < 1LL * avg * n) {
    if (v[idx].second >= r) {
      idx++;
      continue;
    }
    if (r - v[idx].second < 1LL * n * avg - sum) {
      res += 1LL * (r - v[idx].second) * v[idx].first;
      sum += r - v[idx].second;
    } else {
      long long x = 1LL * n * avg - sum;
      sum += x;
      res += x * v[idx].first;
    }
    idx++;
  }
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt = 1;
  while (tt--) {
    solve();
  }
}
