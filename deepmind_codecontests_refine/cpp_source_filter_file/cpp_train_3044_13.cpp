#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  auto solve = [&]() {
    int n;
    cin >> n;
    vector<int64_t> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
    }
    if (n == 1) {
      cout << a[0] << "\n";
      return;
    }
    vector<int64_t> suf(n);
    if (b[n - 2] < a[n - 1]) {
      suf[n - 1] = a[n - 1] - b[n - 2];
    }
    for (int i = n - 2; i > 0; --i) {
      suf[i] = suf[i + 1];
      if (b[i - 1] < a[i]) {
        suf[i] += a[i] - b[i - 1];
      }
    }
    int64_t sum = 0;
    int64_t ans = 1e18;
    for (int i = 0; i < n; ++i) {
      ans = min(ans, sum + a[i] + suf[i + 1]);
      int j = i ? i - 1 : n - 1;
      if (b[j] < a[i]) {
        sum += a[i] - b[j];
      }
    }
    cout << min(ans, sum + a[n - 1]) << "\n";
  };
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
