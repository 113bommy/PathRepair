#include <bits/stdc++.h>
using namespace std;
string change(string s, int n, int k) {
  string prefix = s.substr(0, k - 1);
  string suffix = s.substr(k - 1, n - k + 1);
  if (n % k == 0) {
    reverse(prefix.begin(), prefix.end());
  }
  return suffix + prefix;
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string best = change(s, n, 1);
  int ans = 1;
  for (int k = 2; k < n; k++) {
    string cand = change(s, n, k);
    if (cand < best) {
      best = cand;
      ans = k;
    }
  }
  cout << best << endl;
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
