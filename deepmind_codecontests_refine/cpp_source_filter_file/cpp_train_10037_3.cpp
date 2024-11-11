#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  string ans = "";
  for (int i = 0; i < s.length(); i++) {
    if (ans.length() >= 2)
      if (s[i] == ans[ans.length() - 1] && s[i] == ans[ans.length() - 1])
        continue;
    if (ans.length() >= 3)
      if (s[i] == ans[ans.length() - 1] &&
          ans[ans.length() - 2] == ans[ans.length() - 3])
        continue;
    ans = ans + s[i];
  }
  cout << ans;
  return 0;
}
