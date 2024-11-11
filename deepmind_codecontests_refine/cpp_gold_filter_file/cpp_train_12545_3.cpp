#include <bits/stdc++.h>
using namespace std;
bool cek(string s) {
  string ss = s;
  reverse(ss.begin(), ss.end());
  return (ss == s);
}
int main() {
  int k, occ[26], left, right;
  string s;
  bool ada, bisa;
  cin >> k;
  cin >> s;
  memset(occ, 0, sizeof occ);
  for (int i = 0; i <= s.length() - 1; i++) {
    if (s[i] >= 'a' && s[i] <= 'z') occ[s[i] - 'a']++;
  }
  left = s.length() / 2 - 1;
  right = s.length() / 2 + (s.length() % 2 == 0 ? 0 : 1);
  if (s.length() % 2 == 1 && s[s.length() / 2] == '?') {
    ada = false;
    for (int i = k - 1; i >= 0; i--) {
      if (occ[i] == 0) {
        s[s.length() / 2] = i + 'a';
        ada = true;
        occ[i] = 1;
        break;
      }
    }
    if (ada == false) s[s.length() / 2] = 'a';
  }
  while (left >= 0) {
    if (s[left] != '?' && s[right] == '?')
      s[right] = s[left];
    else if (s[left] == '?' && s[right] != '?')
      s[left] = s[right];
    else if (s[left] == '?' && s[right] == '?') {
      ada = false;
      for (int i = k - 1; i >= 0; i--) {
        if (occ[i] == 0) {
          occ[i] = 1;
          ada = true;
          s[left] = s[right] = i + 'a';
          break;
        }
      }
      if (ada == false) s[left] = s[right] = 'a';
    }
    left--;
    right++;
  }
  for (int i = 0; i <= s.length() - 1; i++) {
    if (s[i] == '?') s[i] = 'a';
  }
  bisa = true;
  for (int i = 0; i <= k - 1; i++) {
    if (occ[i] == 0) bisa = false;
  }
  if (cek(s) == true && bisa == true)
    cout << s << endl;
  else
    cout << "IMPOSSIBLE\n";
  return 0;
}
