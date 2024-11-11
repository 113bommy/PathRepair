#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  string alphabets = "abcdefghijklmnopqrstuvwxyz";
  while (T--) {
    string s;
    cin >> s;
    set<char> g[200];
    for (int i = 0; i < s.length(); i++) {
      char c = s[i];
      if (i != 0 && i != s.length() - 1) {
        g[c].insert(s[i - 1]);
        g[c].insert(s[i + 1]);
      } else if (i == 0 && s.length() > 1) {
        g[c].insert(s[i + 1]);
      } else if (s.length() > 1) {
        g[c].insert(s[i - 1]);
      }
    }
    bool k = true;
    for (char ch : alphabets) {
      if (g[ch].size() != 0) {
        k = false;
      }
    }
    if (k) {
      cout << "YES\n";
      cout << alphabets;
      continue;
    }
    bool b = true;
    bool d = false;
    char start = 'A';
    for (char c : alphabets) {
      if (g[c].size() > 2) {
        b = false;
      }
      if (g[c].size() == 1) {
        d = true;
        start = c;
      }
      for (char ch : g[c]) {
        if (g[ch].find(c) == g[ch].end()) {
          b = false;
        }
      }
    }
    if (!b || !d) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    bool a[200] = {false};
    while (true) {
      if (a[start]) {
        break;
      }
      cout << start;
      a[start] = true;
      for (char ch : g[start]) {
        if (!a[ch]) {
          start = ch;
        }
      }
    }
    for (char ch : alphabets) {
      if (!a[ch]) {
        cout << ch;
      }
    }
    cout << "\n";
  }
}
