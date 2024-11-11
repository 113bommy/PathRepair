#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;
  string ans = "";
  for (int i = 0; i < n; ++i) {
    int dig = s[i] - '0';
    if (dig == 1 || dig == 0)
      continue;
    else if (dig == 4)
      ans += "223";
    else if (dig == 6)
      ans += "53";
    else if (dig == 8)
      ans += "2227";
    else if (dig == 9)
      ans += "7332";
    else
      ans = ans + s[i];
  }
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}
