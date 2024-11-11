#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  bool t = false;
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == s[i - 1]) {
      s.erase(i);
      i--;
    }
  }
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'h') {
      for (int j = i + 1; j < s.length(); j++) {
        if (s[j] == 'e') {
          for (int k = j + 1; k < s.length(); k++) {
            if (s[k] == 'i') {
              for (int l = k + 1; l < s.length(); l++) {
                if (s[l] == 'd') {
                  for (int m = l + 1; m < s.length(); m++) {
                    if (s[m] == 'i') {
                      t = true;
                      break;
                    }
                  }
                }
                if (t) {
                  break;
                }
              }
            }
            if (t) {
              break;
            }
          }
        }
        if (t) {
          break;
        }
      }
    }
    if (t) {
      break;
    }
  }
  (t) ? cout << "YES" : cout << "NO";
}
