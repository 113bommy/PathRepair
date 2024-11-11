#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans[15] = {0};
  int l = s.length();
  for (int i = 0; i < l; i++) {
    if (s[i] == 'L') {
      for (int st = 0;; st++)
        if (!ans[st]) {
          ans[st] = 1;
          break;
        }
    } else if (s[i] == 'R') {
      for (int st = 9;; st--) {
        if (!ans[st]) {
          ans[st] = 1;
          break;
        }
      }
    } else {
      ans[s[i] - '0'] = 0;
    }
  }
  for (int i = 0; i < 9; i++) cout << ans[i];
}
