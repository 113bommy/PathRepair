#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  long long n = s.length();
  reverse(s.begin(), s.end());
  set<string> ans;
  vector<bool> dp2(n + 1, 0), dp3(n + 1, 0);
  dp2[1] = 1;
  dp3[2] = 1;
  for (long long i = 3; i < n - 5; ++i) {
    dp2[i] = dp3[i - 2] ||
             (dp2[i - 2] && !(s[i] == s[i - 2] && s[i - 1] != s[i - 3]));
    dp3[i] = dp3[i] || dp2[i - 3];
    if (i - 5 >= 0)
      dp3[i] =
          dp3[i] || (dp2[i - 3] && !(s[i] == s[i - 3] && s[i - 1] == s[i - 4] &&
                                     s[i - 2] == s[i - 5]));
  }
  for (long long i = 0; i < n - 5; ++i) {
    if (dp2[i]) {
      string temp = s.substr(i - 1, 2);
      reverse(temp.begin(), temp.end());
      ans.insert(temp);
    }
    if (dp3[i]) {
      string temp = s.substr(i - 2, 3);
      reverse(temp.begin(), temp.end());
      ans.insert(temp);
    }
  }
  cout << ans.size() << '\n';
  for (string i : ans) cout << i << "\n";
  return 0;
}
