#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
    }
    vector<long long int> pos(n);
    for (long long int i = 0; i < n; i++) {
      pos[a[i]] = i;
    }
    long long int mnpos = pos[0];
    long long int mx = pos[0];
    vector<long long int> ans(n);
    for (long long int i = 0; i < n; i++) {
      mnpos = min(mnpos, pos[i]);
      mx = max(mx, pos[i]);
      if (mx - mnpos == i) {
        ans[i] = 1;
      } else {
        ans[i] = 0;
      }
    }
    for (long long int x : ans) cout << x << " ";
    cout << "\n";
  }
  return 0;
}
