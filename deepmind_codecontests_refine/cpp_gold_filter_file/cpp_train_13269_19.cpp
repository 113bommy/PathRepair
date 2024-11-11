#include <bits/stdc++.h>
using namespace std;
signed main() {
  int n;
  cin >> n;
  int a[100005], b[100005] = {};
  int ans = 0, ma = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) ans++;
    b[a[i]]++;
    ma = max(ma, a[i]);
  }
  for (int i = 1; i < ma; i++) {
    if (b[i] < b[i + 1]) {
      cout << -1;
      return 0;
    }
  }
  cout << ans << endl;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[a[i]]++;
    int an = mp[a[i]];
    cout << an << " ";
  }
  return 0;
}
