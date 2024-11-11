#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int s = a[0];
    int ans = 0;
    for (int i = 1; i < n; i++) {
      ans += (k - a[i]) / s;
    }
    cout << ans << endl;
  }
  return 0;
}
