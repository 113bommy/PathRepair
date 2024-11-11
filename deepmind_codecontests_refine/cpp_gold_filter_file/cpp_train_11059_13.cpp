#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int ans = -1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'R') {
        ans = i + 1;
        break;
      }
    }
    if (ans == -1) {
      cout << s.size() + 1 << endl;
      continue;
    } else {
      int last = ans - 1;
      for (int i = ans; i < s.size(); i++) {
        if (s[i] == 'R') {
          ans = max(i - last, ans);
          last = i;
        }
      }
      ans = max(ans, int(s.size()) - last);
    }
    cout << ans << endl;
  }
  return 0;
}
