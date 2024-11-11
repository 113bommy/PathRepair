#include <bits/stdc++.h>
using namespace std;
const int64_t maxn = 1e5 + 1;
void solve() {
  int64_t n, k;
  cin >> n >> k;
  int64_t m = n;
  int64_t ans = 1;
  int64_t pw = 1;
  vector<int64_t> d, p, rp;
  set<int64_t> st;
  for (; n; n /= 10) {
    d.push_back(n % 10);
    p.push_back(pw);
    rp.push_back(ans);
    st.insert(n % 10);
    pw *= 10;
    ans += pw;
  }
  if (st.size() <= k) {
    cout << m << '\n';
    return;
  }
  st.clear();
  reverse(d.begin(), d.end());
  reverse(p.begin(), p.end());
  reverse(rp.begin(), rp.end());
  int64_t x = 0;
  for (int64_t i = 0; i < d.size(); i++) {
    for (int64_t cd = d[i] + 1; cd <= 9; cd++) {
      if (st.size() == k && !st.count(cd)) continue;
      int64_t nx = x + p[i] * cd;
      if (st.size() + (!st.count(cd)) + (!st.count(0)) > k)
        nx += (rp[i] / 10) * (st.empty() ? cd : *st.begin());
      ans = min(ans, nx);
      break;
    }
    st.insert(d[i]);
    if (st.size() > k) break;
    x += p[i] * d[i];
  }
  cout << ans << '\n';
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int64_t t;
  cin >> t;
  while (t--) solve();
  return 0;
}
