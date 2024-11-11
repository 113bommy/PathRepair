#include <bits/stdc++.h>
using namespace std;
int a[26];
int main() {
  string s;
  cin >> s;
  memset(a, 0, sizeof a);
  bool dp1 = 0, dp2 = 0, dp3 = 0, dp4 = 0, dp5 = 0, dp = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'h') dp1 = 1;
    if (s[i] == 'e' && dp1) dp2 = 1;
    if (s[i] == 'l' && dp2 && !dp3)
      dp3 = 1;
    else if (s[i] == 'l' && dp3)
      dp4 = 1;
    if (s[i] == 'o' && dp4) dp5 = 1;
  }
  if (dp5)
    cout << "YES\n";
  else
    cout << "NO\n";
}
