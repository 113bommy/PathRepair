#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    if (s[i] == '@') {
      long long cnt1 = 0, cnt2 = 0;
      bool ok = 1, t = 0, had = 0;
      for (int j = i - 1; j >= 0; j--) {
        if (s[j] == '@' || s[j] == '.') break;
        if (isalpha(s[j])) cnt1++;
      }
      for (int j = i + 1; j < n; j++) {
        if (isalpha(s[j]) || s[j] >= '1' && s[j] <= '9') had = 1;
        if (t) {
          if (isalpha(s[j]))
            cnt2++;
          else
            break;
        }
        if (s[j] == '.') {
          if (!t && had)
            t = 1;
          else
            break;
        } else if (s[j] == '@' || s[j] == '_') {
          if (!t) ok = 0;
          break;
        }
      }
      if (ok) ans += cnt1 * cnt2;
    }
  }
  cout << ans;
}
