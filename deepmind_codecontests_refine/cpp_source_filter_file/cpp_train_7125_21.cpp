#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  if (n <= 2) {
    cout << n << endl;
    return 0;
  }
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<int> pref(n), suf(n);
  for (int i = 0; i < n; i++) {
    pref[i] = 1;
    if (i > 1)
      if (a[i - 1] < a[i]) pref[i] = max(pref[i], pref[i - 1] + 1);
  }
  for (int i = n - 1; i >= 0; i--) {
    suf[i] = 1;
    if (i < n - 1)
      if (a[i + 1] > a[i]) suf[i] = max(suf[i], suf[i + 1] + 1);
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    if (i < n - 1) ans = max(ans, suf[i + 1] + 1);
    if (i > 0) ans = max(ans, pref[i - 1] + 1);
    if (i < n - 1 and i > 0) {
      if (a[i + 1] > a[i - 1] + 1) ans = max(ans, pref[i - 1] + 1 + suf[i + 1]);
    }
  }
  cout << ans << endl;
}
