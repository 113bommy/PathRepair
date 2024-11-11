#include <bits/stdc++.h>
using namespace std;
int n, ans, tmp;
char c, jawaban;
bool bol[100];
string s;
int main() {
  cin >> n;
  memset(bol, true, sizeof(bol));
  for (int i = 1; i < n; i++) {
    cin >> c;
    cin >> s;
    if (tmp == 25) {
      if (c == '!') ans++;
      if (c == '?') {
        if (s[0] != jawaban) ans++;
      }
    } else {
      if (c == '.') {
        for (int i = 0; i < s.length(); i++) {
          if (bol[s[i] - 'a']) {
            bol[s[i] - 'a'] = false;
            tmp++;
          }
        }
      }
      if (c == '!') {
        bool cek[30];
        memset(cek, false, sizeof(cek));
        for (int i = 0; i < s.length(); i++) cek[s[i] - 'a'] = true;
        for (int i = 0; i < 26; i++) {
          if (bol[i] && !cek[i]) {
            tmp++;
            bol[i] = false;
          }
        }
      }
      if (c == '?') {
        if (bol[c - 'a']) {
          tmp++;
          bol[c - 'a'] = false;
        }
      }
    }
    if (tmp == 25) {
      for (int i = 0; i < 26; i++)
        if (bol[i]) jawaban = i + 'a';
    }
  }
  cin >> c >> s;
  cout << ans << endl;
}
