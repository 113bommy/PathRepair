#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  cin >> s;
  if (s.length() < 5) return cout << "NO", 0;
  while (s[0] != 'h') {
    s.erase(0, 1);
  }
  if (s.length() < 5) return cout << "NO", 0;
  int p = 0;
  while (p + 1 != s.length()) {
    if (s[p] == s[p + 1] && s[p] != 'l')
      s.erase(p, 1);
    else
      p++;
  }
  if (s.length() < 5) return cout << "NO", 0;
  p = 0;
  while (p + 1 != s.length()) {
    if (s[p] == 'l' && s[p + 1] == 'l' && s[p + 2] == 'l')
      s.erase(p, 1);
    else
      p++;
  }
  if (s.length() < 5) return cout << "NO", 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'h') {
      for (int i1 = i + 1; i1 < s.length(); i1++) {
        if (s[i1] == 'e') {
          for (int j = i1 + 1; j < s.length(); j++) {
            if (s[j] == 'l') {
              for (int j1 = j + 1; j1 < s.length(); j1++) {
                if (s[j1] == 'l') {
                  for (int k1 = j1 + 1; k1 < s.length(); k1++) {
                    if (s[k1] == 'o') {
                      return cout << "YES", 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  cout << "NO";
}
