#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, s1, t;
  cin >> s >> t;
  map<char, int> m;
  int y = 0, w = 0;
  for (int i = 0; i < t.length(); i++) {
    m[t[i]]++;
  }
  for (int i = 0; i < s.length(); i++) {
    if (m[s[i]] > 0) {
      y++;
      m[s[i]]--;
    } else
      s1 += s[i];
  }
  for (int i = 0; i < s1.length(); i++) {
    if (isupper(s1[i])) {
      s1[i] = tolower(s1[i]);
      if (m[s1[i]] > 0) {
        w++;
        m[s1[i]]--;
      }
    } else {
      s1[i] = toupper(s1[i]);
      if (m[s1[i]] > 0) {
        w++;
        m[s1[i]]--;
      }
    }
  }
  cout << y << " " << w;
}
