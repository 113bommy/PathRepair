#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    map<char, int> m;
    int r = 1, i = 0;
    int c;
    for (; i < s.length() - 1; i++) {
      if (s[i] == s[i + 1]) {
        c = 2;
        for (i = i + 2; i < s.length(); i++) {
          if (s[i] != s[i - 1]) break;
          c++;
        }
        if (c % 2 != 0) {
          m[s[i - 1]] = r;
        }
        i--;
      } else
        m[s[i]] = r;
    }
    if (i != s.length()) {
      m[s[i]] = r;
    }
    map<char, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) cout << it->first;
    cout << endl;
  }
}
