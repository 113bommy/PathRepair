#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 1e9 + 7;
    for (int i = 0; i < n - d + 1; ++i) {
      set<int> cnt;
      for (int j = i; j < i + d; ++j) cnt.insert(a[j]);
      ans = min(ans, (int)cnt.size());
    }
    cout << ans << '\n';
  }
  return 0;
}
