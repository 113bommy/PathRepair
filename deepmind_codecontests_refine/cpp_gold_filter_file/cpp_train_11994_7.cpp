#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int flag = 1;
    for (int i = 0; i < s.length() - 1; i++) {
      if (s[i] == s[i + 1] && s[i] != '?') {
        flag = 0;
        break;
      }
    }
    if (!flag) {
      cout << -1 << "\n";
      continue;
    }
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '?')
        for (s[i] = 'a'; true; s[i]++)
          if ((i == 0 || s[i] != s[i - 1]) &&
              (i == s.length() - 1 || s[i] != s[i + 1]))
            break;
    }
    cout << s << "\n";
  }
  return 0;
}
