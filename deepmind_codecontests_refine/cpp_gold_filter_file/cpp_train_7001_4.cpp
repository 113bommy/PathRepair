#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int _ = 0; _ < (T); ++_) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ok = 0;
    string t = "abacaba";
    string anss;
    for (int i = 0; i < (n - 6); ++i) {
      string ans;
      int flag = 0;
      for (int j = 0; j < (n); ++j) {
        if (s[j] != '?') {
          ans += s[j];
        } else {
          if (j == i)
            ans += 'a';
          else if (j == i + 1)
            ans += 'b';
          else if (j == i + 2)
            ans += 'a';
          else if (j == i + 3)
            ans += 'c';
          else if (j == i + 4)
            ans += 'a';
          else if (j == i + 5)
            ans += 'b';
          else if (j == i + 6)
            ans += 'a';
          else
            ans += 'z';
        }
      }
      if (flag == -1) {
        continue;
      }
      for (int j = 0; j < (n - 6); ++j) {
        if (ans.substr(j, 7) == t) flag++;
      }
      if (flag == 1) {
        ok = 1;
        anss = ans;
        break;
      }
    }
    if (ok) {
      cout << "Yes" << endl;
      cout << anss << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
