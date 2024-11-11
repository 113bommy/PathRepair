#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
vector<int64_t> subarray(vector<int64_t> a) {
  int64_t n = a.size();
  vector<int64_t> res(n + 1, 0);
  int64_t i = 0;
  while (i < n) {
    if (a[i] == 0) {
      i++;
      continue;
    }
    int64_t j = i;
    while (j < n && a[j] == 1) {
      j++;
    }
    for (int64_t len = 1; len <= (j - i); len++) {
      res[len] += j - i - len + 1;
    }
    i = j;
  }
  return res;
}
inline void solve() {
  int64_t n, m, k;
  cin >> n >> m >> k;
  vector<int64_t> a(n), b(m);
  for (int64_t i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int64_t i = 0; i < m; i++) {
    cin >> b[i];
  }
  auto sa = subarray(a);
  auto sb = subarray(b);
  int64_t ans = 0;
  for (int64_t i = 1; i <= sa.size(); i++) {
    if (k % i == 0 && (k / i) <= m) {
      ans += (sa[i] * sb[k / i]);
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
