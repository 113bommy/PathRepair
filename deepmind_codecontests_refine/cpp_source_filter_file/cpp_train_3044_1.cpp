#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(NULL);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
      long long x, y;
      cin >> x >> y;
      a[i] = x, b[i] = y;
    }
    long long ans = max(0ll, a[0] - b[n - 1]), temp = min(a[0], b[n - 1]);
    for (int i = 1; i < n; i++) {
      ans = max(ans, a[i] - b[i - 1]);
      temp = min(temp, min(a[i], b[i - 1]));
    }
    cout << ans + temp << "\n";
  }
  return 0;
}
