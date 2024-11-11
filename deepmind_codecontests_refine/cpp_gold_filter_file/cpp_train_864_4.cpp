#include <bits/stdc++.h>
using namespace std;
bool clash[30][30];
int dp[100001][27];
string s;
int solve(int index, int lastchar) {
  if (index == s.size()) {
    return 0;
  }
  int mn = (1 << 30);
  if (dp[index][lastchar] != -1) {
    return dp[index][lastchar];
  }
  if (!clash[s[index] - 'a'][lastchar])
    mn = min(mn, solve(index + 1, s[index] - 'a'));
  mn = min(mn, solve(index + 1, lastchar) + 1);
  return dp[index][lastchar] = mn;
}
int main() {
  cin >> s;
  int n;
  cin >> n;
  string s2;
  int sum = 0;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++) {
    cin >> s2;
    clash[s2[0] - 'a'][s2[1] - 'a'] = true;
    clash[s2[1] - 'a'][s2[0] - 'a'] = true;
  }
  cout << solve(0, 26) << endl;
  return 0;
}
