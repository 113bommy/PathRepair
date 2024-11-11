#include <bits/stdc++.h>
using namespace std;
int k;
string s;
string ans;
int main(void) {
  cin >> s >> k;
  int cnt = 0, scnt = 0, ccnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '*' || s[i] == '?') {
      cnt++;
      scnt += (s[i] == '*' ? 1 : 0);
      ccnt += (s[i] == '?' ? 1 : 0);
    }
  }
  if (k < s.size() - cnt - cnt || (scnt == 0 && k > s.size() - ccnt)) {
    cout << "Impossible" << endl;
  } else if (k < s.size() - cnt) {
    int dis = s.size() - cnt - k;
    for (int i = 0; i < s.size() - 1; i++) {
      if (dis > 0 && (s[i + 1] == '?' || s[i + 1] == '*')) {
        i++;
        dis--;
      } else if ('a' <= s[i] && s[i] <= 'z') {
        ans += s[i];
      }
    }
    if ('a' <= s[s.size() - 1] && s[s.size() - 1] <= 'z')
      ans += s[s.size() - 1];
    cout << ans << endl;
  } else {
    int dis = k - s.size() + cnt;
    for (int i = 0; i < s.size() - 1; i++) {
      if (dis > 0 && s[i + 1] == '*') {
        for (int j = 0; j <= dis; j++) {
          ans += s[i];
        }
        dis = 0;
      } else if ('a' <= s[i] && s[i] <= 'z') {
        ans += s[i];
      }
    }
    if ('a' <= s[s.size() - 1] && s[s.size() - 1] <= 'z')
      ans += s[s.size() - 1];
    cout << ans << endl;
  }
  return 0;
}
