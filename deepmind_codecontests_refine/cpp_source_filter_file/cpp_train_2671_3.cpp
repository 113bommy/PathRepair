#include <bits/stdc++.h>
using namespace std;
int64_t N = 1e18;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t q;
  cin >> q;
  set<int64_t> s;
  for (int64_t i = 2; i <= 1e6; i++) {
    for (int64_t j = i * i * i; j <= N; j *= i) {
      if ((int64_t)sqrt(j) * sqrt(j) != j) s.insert(j);
      if (1e18 / i < j) break;
    }
  }
  vector<int64_t> vec;
  for (auto it : s) vec.push_back(it);
  while (q--) {
    int64_t l, r;
    cin >> l >> r;
    auto it = lower_bound(vec.begin(), vec.end(), l);
    auto it2 = upper_bound(vec.begin(), vec.end(), r);
    int64_t ans = it2 - it;
    ans += (int64_t)sqrt(r) - (int64_t)sqrt(l - 1);
    cout << ans << endl;
  }
  return 0;
}
