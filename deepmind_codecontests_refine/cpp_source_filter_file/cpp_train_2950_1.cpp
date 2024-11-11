#include <bits/stdc++.h>
using namespace std;
int main() {
  srand(time(0));
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k, h;
  cin >> n >> k >> h;
  vector<tuple<int, int, int> > m(n);
  for (int i = 0; i < n; ++i) cin >> get<0>(m[i]);
  for (int i = 0; i < n; ++i) cin >> get<1>(m[i]);
  for (int i = 0; i < n; ++i) get<2>(m[i]) = i;
  sort(m.begin(), m.end());
  long double lo = 0.0;
  long double hi = 1.1e5;
  long double eps = 1e-12;
  auto Attempt = [&](long double mid) -> vector<int> {
    vector<int> res;
    int cur = 1;
    for (int i = 0; i < n; ++i) {
      if ((long double)cur < (long double)get<1>(m[i]) * mid + eps) {
        res.push_back(get<2>(m[i]));
        ++cur;
      }
    }
    return cur > k ? res : vector<int>{};
  };
  for (int it = 0; it < 100; ++it) {
    long double mid = (lo + hi) / 2.0;
    if (Attempt(mid).empty()) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  vector<int> ans = Attempt(lo + eps);
  for (int i = 0; i < k; ++i) cout << ans[i] + 1 << ' ';
  cout << '\n';
  return 0;
}
