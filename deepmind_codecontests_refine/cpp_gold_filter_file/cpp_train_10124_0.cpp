#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  vector<long long> c(3, 0);
  long long it = 0, ans = 9e18, n = s.size();
  for (int i = 0; i < n; i++) {
    while (it <= n) {
      bool ok = true;
      for (long long i = 0; i < 3; i++) ok &= (c[i] > 0);
      if (ok) {
        ans = min(ans, it - i);
        break;
      }
      c[s[it] - '1']++;
      it++;
    }
    c[s[i] - '1']--;
  }
  if (ans == 9e18)
    cout << 0 << "\n";
  else
    cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
