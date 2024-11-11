#include <bits/stdc++.h>
using namespace std;
signed main() {
  int n, m, ta, tb, k;
  cin >> n >> m >> ta >> tb >> k;
  vector<int> arr1(n), arr2(m);
  for (int i = 0; i < n; i++) {
    cin >> arr1[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> arr2[i];
  }
  if (k >= min(n, m)) {
    cout << "-1" << endl;
    return 0;
  }
  int ans = INT_MIN;
  for (int i = 0; i <= k && i < arr1.size(); i++) {
    int t = arr1[i] + ta;
    auto itr = lower_bound(arr2.begin(), arr2.end(), t);
    itr += (k - i);
    if (itr >= arr2.end()) {
      cout << "-1" << endl;
      return 0;
    }
    t = tb + *itr;
    if (t > ans) ans = t;
  }
  cout << ans << endl;
}
