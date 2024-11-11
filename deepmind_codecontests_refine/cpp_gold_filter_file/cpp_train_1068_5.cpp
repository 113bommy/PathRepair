#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int d = unique(a.begin(), a.end()) - a.begin();
    if (k > d)
      cout << 1 << '\n';
    else if (k == 1) {
      if (d == 1)
        cout << 1 << '\n';
      else
        cout << -1 << '\n';
    } else {
      int ans = 1;
      d -= k;
      ans += (d + k - 2) / (k - 1);
      cout << ans << '\n';
    }
  }
  return 0;
}
