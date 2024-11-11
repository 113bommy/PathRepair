#include <bits/stdc++.h>
using namespace std;
long long inf = 4e18, mod = 1e9 + 7;
void solve() {
  vector<string> v[12];
  v[0] = {"ab", "bc", "ca"};
  v[1] = {"ac", "cb", "ba"};
  v[2] = {"ba", "ac", "cb"};
  v[3] = {"bc", "ca", "ab"};
  v[4] = {"ca", "ab", "bc"};
  v[5] = {"cb", "ba", "ac"};
  v[6] = {"aa", "bb", "cc", "ab", "bc"};
  v[7] = {"aa", "bb", "cc", "ac", "cb"};
  v[8] = {"aa", "bb", "cc", "ba", "ac"};
  v[9] = {"aa", "bb", "cc", "bc", "ca"};
  v[10] = {"aa", "bb", "cc", "ca", "ab"};
  v[11] = {"aa", "bb", "cc", "cb", "ba"};
  string st[12] = {"abc", "acb", "bac", "bca", "cab", "cba",
                   "abc", "acb", "bac", "bca", "cab", "cba"};
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < 12; i++) {
    bool see = 1;
    for (auto kt : v[i]) {
      if (kt == s || kt == t) see = 0;
    }
    if (see) {
      cout << "YES\n";
      char a = st[i][0], b = st[i][1], c = st[i][2];
      if (i < 6) {
        for (int j = 1; j <= n; j++) cout << a << b << c;
      } else {
        for (int j = 1; j <= n; j++) cout << a;
        for (int j = 1; j <= n; j++) cout << b;
        for (int j = 1; j <= n; j++) cout << c;
      }
      cout << endl;
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
}
