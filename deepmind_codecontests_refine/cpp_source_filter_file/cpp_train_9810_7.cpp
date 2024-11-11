#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string s;
  cin >> n >> s;
  string ans = s;
  int t = 1;
  for (int k = 1; k <= n; k++) {
    string temp;
    for (int i = k - 1; i < n; i++) temp += s[i];
    if (k % 2 == 0) {
      for (int i = k - 2; i >= 0; i--) temp += s[i];
    } else {
      for (int i = 0; i <= k - 2; i++) temp += s[i];
    }
    if (temp < ans) {
      ans = temp;
      t = k;
    }
  }
  cout << ans << '\n' << t << '\n';
}
void run() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
signed main() {
  cout.setf(ios::fixed);
  cout.precision(10);
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  run();
  return 0;
}
