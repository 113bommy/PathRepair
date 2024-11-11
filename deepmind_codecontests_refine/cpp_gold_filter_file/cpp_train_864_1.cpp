#include <bits/stdc++.h>
using namespace std;
int m[28][28];
string s;
int dp[100004][28];
int solve(int i, int prevchar) {
  if (i >= s.size()) return 0;
  if (dp[i][prevchar - 'a'] != -1)
    return dp[i][prevchar - 'a'];
  else {
    if (m[s[i] - 'a'][prevchar - 'a'] == 1) {
      return dp[i][prevchar - 'a'] = 1 + solve(i + 1, prevchar);
    } else {
      return dp[i][prevchar - 'a'] =
                 min(1 + solve(i + 1, prevchar), solve(i + 1, s[i]));
    }
  }
}
int main() {
  cin.tie(NULL);
  cin >> s;
  memset(m, 0, sizeof(m[0][0]) * 28 * 28);
  memset(dp, -1, sizeof(dp[0][0]) * 100004 * 28);
  int k;
  cin >> k;
  char a, b;
  for (int i = 0; i < k; ++i) {
    cin >> a >> b;
    m[a - 'a'][b - 'a'] = 1;
    m[b - 'a'][a - 'a'] = 1;
  }
  cout << solve(0, 'z' + 1) << endl;
  return 0;
}
