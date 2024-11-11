#include <bits/stdc++.h>
using namespace std;
char a[11111];
string s, t;
vector<char> b, c;
bool u[11111];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> s >> t;
  for (int i = 0; i < 26; i++) a[i] = '_';
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != t[i]) {
      if (a[s[i] - 'a'] == '_' && a[t[i] - 'a'] == '_') {
        a[s[i] - 'a'] = t[i];
        a[t[i] - 'a'] = s[i];
      } else if (a[s[i] - 'a'] != t[i] || a[t[i] - 'a'] != s[i]) {
        cout << -1;
        return 0;
      } else if (a[t[i] - 'a'] != s[i]) {
        cout << -1;
        return 0;
      }
    } else {
      if ((a[s[i] - 'a'] == '_' && a[t[i] - 'a'] == '_') ||
          (a[s[i] - 'a'] == a[t[i] - 'a'])) {
        a[s[i] - 'a'] = t[i];
        a[t[i] - 'a'] = s[i];
      } else {
        cout << -1;
        return 0;
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    if (a[i] != '_' && !u[i] && a[i] != a[a[i] - 'a']) {
      b.push_back(a[i]);
      c.push_back(a[a[i] - 'a']);
      u[i] = true;
      u[a[i] - 'a'] = true;
    }
  }
  if (b.size() == 0)
    cout << 0;
  else {
    cout << b.size() << endl;
    for (int i = 0; i < b.size(); i++) cout << b[i] << " " << c[i] << endl;
  }
  return 0;
}
