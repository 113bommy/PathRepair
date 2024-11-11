#include <bits/stdc++.h>
using namespace std;
string s;
int k;
int main() {
  cin >> s >> k;
  vector<vector<bool> > bad(28, vector<bool>(28, false));
  for (int i = 1; i <= k; ++i) {
    string t;
    cin >> t;
    bad[t[0] - 'a'][t[1] - 'a'] = bad[t[1] - 'a'][t[0] - 'a'] = true;
  }
  vector<int> dp(26, 0);
  int ans = 0;
  for (int i = 0; i < (int)((s).size()); ++i) {
    vector<int> next(26, 0);
    for (int j = 0; j < 26; ++j) next[j] = dp[j] + 1;
    for (int j = 0; j < 26; ++j)
      if (!bad[s[i] - 'a'][j] && !bad[j][s[i] - 'a'])
        next[s[i] - 'a'] = min(next[s[i] - 'a'], dp[j]);
    for (int j = 0; j < 26; ++j) dp[j] = next[j];
  }
  ans = *min_element((dp).begin(), (dp).end());
  printf("%d\n", ans);
  return 0;
}
