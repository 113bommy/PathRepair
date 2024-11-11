#include <bits/stdc++.h>
using namespace std;
int main() {
  string str, good, pat;
  int n;
  cin >> good;
  cin >> pat;
  cin >> n;
  map<char, bool> isgood;
  for (int i = 0; i < good.size(); i++) {
    isgood[good[i]] = true;
  }
  for (int it = 0; it < n; it++) {
    cin >> str;
    int a = pat.size(), b = str.size();
    if (b < a - 1) {
      cout << "NO\n";
      continue;
    }
    int pos = -1;
    for (int i = 0; i < a; i++) {
      if (pat[i] == '*') {
        pos = i;
        break;
      }
    }
    if (pos == -1) {
      if (a == b) {
        bool fl = false;
        for (int i = 0; i < a; i++) {
          if (pat[i] == '?') {
            if (!isgood[str[i]]) {
              cout << "NO\n";
              fl = true;
              break;
            }
          } else {
            if (pat[i] != str[i]) {
              cout << "NO\n";
              fl = true;
              break;
            }
          }
        }
        if (!fl) cout << "YES\n";
      } else
        cout << "NO\n";
      continue;
    }
    bool fl = false;
    for (int i = 0; i < pos; i++) {
      if (pat[i] == '?') {
        if (!isgood[str[i]]) {
          cout << "NO\n";
          fl = true;
          break;
        }
      } else {
        if (str[i] != pat[i]) {
          cout << "NO\n";
          fl = true;
          break;
        }
      }
    }
    if (fl) continue;
    int j = b - 1, count = 0;
    while (count < a - pos - 1) {
      if (pat[a - 1 - count] == '?') {
        if (!isgood[str[j]]) {
          cout << "NO\n";
          fl = true;
          break;
        }
      } else {
        if (str[j] != pat[a - 1 - count]) {
          cout << "NO\n";
          fl = true;
          break;
        }
      }
      j--;
      count++;
    }
    if (fl) continue;
    int r = a - pos;
    for (int i = pos; i < b - r; i++) {
      if (isgood[str[i]]) {
        cout << "NO\n";
        fl = true;
        break;
      }
    }
    if (!fl) cout << "YES\n";
  }
  return 0;
}
