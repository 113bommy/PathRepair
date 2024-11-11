#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = "abacaba";
    int fa = 0, num = 0, c = 0;
    for (int i = 0; i < n; i++) {
      if (s.substr(i, t.size()) == t) {
        fa = 2;
        num = i;
        break;
      }
    }
    if (fa == 0) {
      for (int i = 0; i < n; i++) {
        string a = s;
        for (int j = 0; j < t.size(); j++) {
          if (s[i + j] != t[j] && s[i + j] != '?') {
            break;
          }
          if (j == t.size() - 1) {
            fa = 2;
            num = i;
          }
        }
        if (fa == 2) {
          for (int j = num; j < num + t.size(); j++) {
            a[j] = t[j - num];
          }
          for (int j = 0; j < n; j++) {
            if (s.substr(j, t.size()) == t && j != num) {
              fa = 1;
              break;
            }
          }
        }
        if (fa == 2) break;
      }
    }
    if (fa == 2) {
      for (int i = num + 1; i < n; i++) {
        if (s.substr(i, t.size()) == t) {
          fa = 1;
          break;
        }
      }
    }
    if (fa == 2) {
      for (int i = 0; i < n; i++) {
        if (s[i] == '?') s[i] = 'e';
      }
      for (int i = num; i < num + t.size(); i++) {
        s[i] = t[i - num];
      }
      cout << "Yes" << endl;
      cout << s << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
