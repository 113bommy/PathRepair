#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  string s, t;
  cin >> s;
  t = s;
  vector<long long int> ans;
  for (__typeof(n - 1) i = (0) - ((0) > (n - 1));
       i != (n - 1) - ((0) > (n - 1)); i += 1 - 2 * ((0) > (n - 1))) {
    if (t[i] != 'B') {
      t[i] = 'B';
      if (t[i + 1] == 'B')
        t[i + 1] = 'W';
      else
        t[i + 1] = 'B';
      ans.push_back(i);
    }
  }
  if (t[n - 1] == 'W') {
    ans.clear();
    for (__typeof(n - 1) i = (0) - ((0) > (n - 1));
         i != (n - 1) - ((0) > (n - 1)); i += 1 - 2 * ((0) > (n - 1))) {
      if (s[i] != 'W') {
        s[i] = 'W';
        if (s[i + 1] == 'W')
          s[i + 1] = 'B';
        else
          s[i + 1] = 'W';
        ans.push_back(i);
      }
    }
    if (s[n - 1] == 'B') {
      cout << -1;
      return;
    }
  }
  cout << ans.size() << '\n';
  for (auto it : ans) cout << it << " ";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int T;
  T = 1;
  while (T--) {
    solve();
  }
}
