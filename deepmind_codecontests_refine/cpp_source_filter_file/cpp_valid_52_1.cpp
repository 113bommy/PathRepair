#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }
    double ans = -1e30;
    for (int i = 0; i < n - 1; i++) {
      double x = (double)pref[i + 1] / (i + 1);
      double y = (double)(pref[n] - pref[i + 1]) / (n - i - 1);
      ans = max(ans, x + y);
    }
    cout << fixed << setprecision(17) << ans << '\n';
  }
  return 0;
}
