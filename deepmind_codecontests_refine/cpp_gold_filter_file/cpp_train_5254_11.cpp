#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());
  n = a.size();
  int const maxa = 2e6;
  vector<int> first(maxa + 1);
  int it = 0;
  for (int i = 0; i <= maxa; ++i) {
    while (it < n && a[it] < i) {
      ++it;
    }
    first[i] = it - 1;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 2 * a[i]; j <= maxa; j += a[i]) {
      int pos = first[j];
      if (pos != -1) {
        ans = max(ans, a[pos] % a[i]);
      }
    }
  }
  cout << ans;
  return 0;
}
