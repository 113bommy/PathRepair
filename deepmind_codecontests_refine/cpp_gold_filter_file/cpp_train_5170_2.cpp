#include <bits/stdc++.h>
using namespace std;
string tolower(string s) {
  for (int i = 0; i < s.size(); i++) s[i] = tolower(s[i]);
  return s;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> w(n);
  for (int i = 0; i < n; i++) cin >> w[i];
  string s;
  char c;
  cin >> s >> c;
  int l = s.size();
  vector<bool> ch(l, false);
  for (int i = 0; i < n; i++) {
    int cl = w[i].size();
    for (int j = 0; j <= l - cl; j++) {
      if (tolower(w[i]) == tolower(s.substr(j, cl))) {
        for (int k = 0; k < cl; k++) {
          ch[j + k] = true;
        }
      }
    }
  }
  for (int i = 0; i < l; i++) {
    if (ch[i]) {
      if (tolower(s[i]) == c) {
        if (c == 'a') {
          if (isupper(s[i]))
            cout << 'B';
          else
            cout << 'b';
        } else {
          if (isupper(s[i]))
            cout << 'A';
          else
            cout << 'a';
        }
      } else {
        if (isupper(s[i]))
          cout << char(toupper(c));
        else
          cout << char(tolower(c));
      }
    } else
      cout << s[i];
  }
  return 0;
}
