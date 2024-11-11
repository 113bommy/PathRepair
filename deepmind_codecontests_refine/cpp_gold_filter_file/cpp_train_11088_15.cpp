#include <bits/stdc++.h>
using namespace std;
void solve();
signed main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    char t;
    cin >> t;
    a[i] = t - '0';
  }
  int l = 1;
  int prev = a[0];
  int mx = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] != prev) {
      l++;
      prev = a[i];
    }
  }
  {
    cout << (min(l + 2, n)) << endl;
    return;
  };
}
