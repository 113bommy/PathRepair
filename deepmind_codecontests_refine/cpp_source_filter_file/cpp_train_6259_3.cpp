#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    bool ok = 1;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] != a[i + 1] && 2 * a[i] < a[i + 1]) ok = 0;
    }
    cout << ((ok) ? "NO" : "YES") << "\n";
  }
}
