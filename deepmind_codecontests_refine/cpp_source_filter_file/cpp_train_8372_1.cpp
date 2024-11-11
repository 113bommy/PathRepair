#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  string s;
  getline(cin, s);
  int n = s.length();
  int ans = 0;
  for (int i = 1; i < n - 3; ++i) {
    if (s[i] == '@') {
      int r = i + 1;
      while (r < n && (isalnum(s[r]))) {
        ++r;
      }
      if (r == n) {
        break;
      }
      if (s[r] != '.' || r == i + 1) {
        continue;
      }
      int r1 = r + 1;
      while (r1 < n && isalpha(s[r1])) {
        ++r1;
      }
      int add = r1 - r - 1;
      int l = i - 1;
      while (l >= 0 && (isalnum(s[l]) || s[l] == '_')) {
        if (isalpha(s[l])) {
          ans += add;
        }
        --l;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
