#include <bits/stdc++.h>
using namespace std;
signed main() {
  int q;
  cin >> q;
  while (q--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int mm = a[n - 1] + k, mn = a[n - 1] - k;
    int lm = a[0] + k, ln = a[0] - k;
    if (mn > lm) {
      cout << "-1" << endl;
      continue;
    }
    cout << lm << endl;
  }
}
