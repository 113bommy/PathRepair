#include <bits/stdc++.h>
using namespace std;
int n;
char s[200005], t[200005];
map<char, char> Map;
set<char> S[26];
int main() {
  while (scanf("%d", &n) == 1) {
    scanf("%s", s);
    scanf("%s", t);
    int ans = 0;
    for (int i = 0; i < 26; i++) S[i].clear();
    for (int i = 0; s[i]; i++)
      if (s[i] != t[i]) {
        S[s[i] - 'a'].insert(t[i]);
        ans++;
      }
    char up, down;
    bool flag = false;
    int ansl, ansr;
    for (int i = 0; i < 26; i++)
      for (set<char>::iterator it = S[i].begin(); it != S[i].end(); it++) {
        int j = (*it) - 'a';
        char x = i + 'a';
        if (S[j].find(x) != S[j].end()) {
          flag = true;
          up = i + 'a';
          down = j + 'a';
        }
      }
    if (flag) {
      for (int i = 0; s[i]; i++) {
        if (s[i] == up && t[i] == down) ansl = i;
        if (s[i] == down && t[i] == up) ansr = i;
      }
      cout << ans - 2 << endl;
      cout << ansl + 1 << ' ' << ansr + 1 << endl;
      continue;
    } else {
      ansl = ansr = -1;
      map<char, char> Map;
      for (int i = 0; s[i]; i++)
        if (s[i] != t[i]) Map[t[i]] = i;
      for (int i = 0; s[i]; i++)
        if (s[i] != t[i] && Map.count(s[i])) {
          ansl = i;
          ansr = Map[s[i]];
        }
      if (ansl != -1) {
        cout << ans - 1 << endl;
        cout << ansl + 1 << ' ' << ansr + 1 << endl;
        continue;
      } else {
        cout << ans << endl;
        cout << -1 << ' ' << -1 << endl;
        continue;
      }
    }
  }
  return 0;
}
