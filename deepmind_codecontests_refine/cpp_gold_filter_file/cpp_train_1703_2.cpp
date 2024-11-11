#include <bits/stdc++.h>
const int inf = 1500000000;
const int d = 1e9 + 7;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    cin >> s;
    if (k == 2) {
      int c1, c2;
      c1 = c2 = 0;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'A' + (i % 2)) {
          c1++;
        }
        if (s[i] != 'A' + (1 - (i % 2))) {
          c2++;
        }
      }
      cout << min(c1, c2) << endl;
      if (c1 < c2) {
        for (int i = 0; i < s.size(); i++) {
          cout << (char)('A' + (i % 2));
        }
      } else {
        for (int i = 0; i < s.size(); i++) {
          cout << (char)('A' + (1 - i % 2));
        }
      }
      continue;
    }
    int ctr = 0;
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == s[i + 1]) {
        ctr++;
        bool choice[26];
        for (int i = 0; i < 26; i++) {
          choice[i] = true;
        }
        choice[s[i] - 'A'] = false;
        if (i + 2 < s.size()) choice[s[i + 2] - 'A'] = false;
        for (int j = 0; j < 3; j++) {
          if (choice[j] == true) {
            s[i + 1] = 'A' + j;
            break;
          }
        }
      }
    }
    cout << ctr << endl;
    cout << s << endl;
  }
  return 0;
}
