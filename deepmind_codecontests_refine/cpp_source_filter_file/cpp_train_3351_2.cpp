#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s, t;
  cin >> s >> t;
  long long a[26] = {0}, b[26] = {0};
  for (long long i = 0; i < (long long)s.length(); ++i) {
    ++a[s[i] - 'a'];
    ++b[s[i] - 'b'];
  }
  for (long long i = 0; i < (long long)26; ++i)
    if (a[i] && b[i]) {
      cout << "YES\n";
      return;
    }
  cout << "NO\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  for (long long i = 0; i < (long long)q; ++i) solve();
  return 0;
}
