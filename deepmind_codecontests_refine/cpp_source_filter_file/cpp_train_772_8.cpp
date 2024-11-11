#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> s;
  int k;
  cin >> k;
  s += string(k, '.');
  int ans = 0;
  for (int n = 1; 2 * n <= s.length(); n++) {
    for (int i = 0; i + 2 * n <= s.length(); i++) {
      bool t = true;
      for (int k = 0; k < n; k++) {
        if ((s[i + k] == '.') || (s[i + k + n] == '.') ||
            (s[i + k] == s[i + k + n])) {
        } else {
          t = false;
          break;
        }
      }
      if (t = true) {
        ans = max(ans, 2 * n);
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
