#include <bits/stdc++.h>
using namespace std;
void optimizeIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  optimizeIO();
  int n;
  cin >> n;
  vector<string> s(n);
  for (typeof(n) i = 0; i < n; i++) {
    cin >> s[i];
  }
  map<string, int> m;
  for (typeof(n) i = 0; i < n; i++) {
    int f = 0;
    vector<char> ch(2, '0');
    for (typeof(s[i].length()) j = 0; j < s[i].length(); j++) {
      if (ch[0] == s[i][j] || ch[1] == s[i][j]) continue;
      if (ch[0] == '0') {
        ch[0] = s[i][j];
        continue;
      }
      if (ch[1] == '0') {
        ch[1] = s[i][j];
        continue;
      }
      f = 1;
      break;
    }
    if (!f) {
      if (ch[1] == '0') {
        string t = "11";
        t[0] = ch[0];
        for (typeof(26) k = 0; k < 26; k++) {
          char ttt = k + 97;
          if (ttt == ch[0]) continue;
          t[0] = min(ttt, ch[0]);
          t[1] = max(ttt, ch[0]);
          m[t] += s[i].length();
        }
      }
    }
  }
  for (typeof(n) i = 0; i < n; i++) {
    int f = 0;
    vector<char> ch(2, '0');
    for (typeof(s[i].length()) j = 0; j < s[i].length(); j++) {
      if (ch[0] == s[i][j] || ch[1] == s[i][j]) continue;
      if (ch[0] == '0') {
        ch[0] = s[i][j];
        continue;
      }
      if (ch[1] == '0') {
        ch[1] = s[i][j];
        continue;
      }
      f = 1;
      break;
    }
    if (!f) {
      if (ch[1] != '0') {
        string t = "as";
        t[0] = (min(ch[0], ch[1]));
        t[1] = (max(ch[0], ch[1]));
        string t1, t2;
        t1 = "a";
        t2 = "3";
        t1[0] = ch[0];
        t2[0] = ch[1];
        m[t] += s[i].length();
      }
    }
  }
  int i = 0, ans = 0, f = 0;
  char tt1, tt2;
  int mx = 0;
  for (typeof(m).begin() it = (m).begin(); it != (m).end(); it++) {
    if (mx < it->second) {
      if (it->first.length() == 1) {
        tt1 = it->first[0];
        f = 1;
      } else
        f = 0;
      mx = it->second;
    }
  }
  int m1 = 0;
  if (f == 1) {
    for (typeof(m).begin() it = (m).begin(); it != (m).end(); it++) {
      if (m1 < it->second && it->first.length() == 1 && it->first[0] != tt1)
        m1 = it->second;
    }
  }
  cout << mx + m1 << endl;
  return 0;
}
