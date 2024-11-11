#include <bits/stdc++.h>
const int N = 1000007, inf = 0x3f3f3f3f;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  auto _solve = []() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (k == 1) {
      cout << s << '\n';
      return;
    }
    char c = s[0];
    char cc = s[0];
    for (int i = 0; i < k; ++i) {
      cc = max(cc, s[i]);
    }
    if (cc != c) {
      cout << cc << '\n';
      return;
    }
    string ans;
    ans += c;
    s = s.substr(k);
    c = s[0];
    cc = c;
    for (int i = 0; i < n; ++i) {
      cc = max(cc, s[i]);
    }
    if (cc != c) {
      cout << ans + s << '\n';
      return;
    }
    for (int i = 0; i < s.size(); i += k) {
      ans += s[i];
    }
    cout << ans << '\n';
  };
  int t;
  cin >> t;
  while (t--) _solve();
}
