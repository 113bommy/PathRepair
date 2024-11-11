#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  long long int cnt = 0;
  long long int ans = 0;
  long long int mn = 0, mx = 0;
  for (long long int i = 0; i < (long long int)(n); i++) {
    if (s[i] == '0' && t[i] == '1')
      cnt++;
    else if (s[i] == '1' && t[i] == '0')
      cnt--;
    ans = max(ans, abs(cnt));
    ans = max({ans, abs(cnt - mx), abs(cnt - mn)});
    mn = min(mn, cnt);
    mn = max(mx, cnt);
  }
  if (cnt != 0) {
    cout << -1 << '\n';
    return;
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  for (long long int i = 0; i < (long long int)(t); i++) {
    solve();
  }
}
