#include <bits/stdc++.h>
using namespace std;
bool all_left(string s) {
  for (int i = 0; i < s.length(); i++)
    if (s[i] == 'R') return 0;
  return 1;
}
bool all_right(string s) {
  for (int i = 0; i < s.length(); i++)
    if (s[i] == 'L') return 0;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int a = -1, b = -1;
  if (all_left(s)) {
    bool b = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
      if (s[i] == 'L' && !b) {
        cout << (i + 1) << " ";
        for (int j = 0; j < s.length(); j++) {
          if (s[j] == 'L') {
            cout << (j + 1);
            return 0;
          }
        }
      }
    }
  } else if (all_right(s)) {
    bool b = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'R' && !b) {
        cout << (i + 1) << " ";
        for (int j = s.length() - 1; j >= 0; j--) {
          if (s[j] == 'R') {
            cout << (j + 2);
            return 0;
          }
        }
      }
    }
  } else {
    bool b = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'R' && !b) {
        cout << (i + 1) << " ";
        b = 1;
      }
      if (s[i] == 'L' && b) {
        cout << (i + 1);
        return 0;
      }
    }
  }
  return 0;
}
