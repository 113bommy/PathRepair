#include <bits/stdc++.h>
using namespace std;
map<char, int> m;
char t[50];
int main() {
  int k;
  cin >> k >> k;
  string s;
  cin >> s;
  for (int i = 97; i < 123; i++) {
    char c = i;
    m[c] = i - 96;
    t[i - 96] = c;
  }
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    if (k == 0) {
      cout << s;
      return 0;
    }
    int d = max(m[c] - 1, 26 - m[c]);
    if (k >= d) {
      k -= d;
      if (m[c] - 1 > 26 - m[c])
        s[i] = 'a';
      else
        s[i] = 'z';
    } else {
      if (m[c] + k <= 26)
        s[i] = t[m[c] + k];
      else
        s[i] = t[m[c] - k];
      k = 0;
    }
  }
  if (k == 0)
    cout << s;
  else
    cout << -1;
}
