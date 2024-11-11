#include <bits/stdc++.h>
using namespace std;
int pc[26];
bool check(int sic[], int wcard) {
  int diff = 0;
  for (int i = 0; i < 26; i++) {
    if (sic[i] > pc[i])
      return false;
    else
      diff += (pc[i] - sic[i]);
  }
  return (diff <= wcard);
}
int main() {
  string s, p;
  int sic[26] = {0};
  int ans = 0, i = 0, wcard = 0;
  cin >> s;
  cin >> p;
  memset(pc, 0, sizeof(pc));
  for (int j = 0; j < p.length(); j++) pc[p[j] - 'a']++;
  if (p.length() <= s.length()) {
    for (int j = 0; j < p.length(); j++) {
      if (s[j] == '?')
        wcard++;
      else
        sic[s[j] - 'a']++;
    }
  }
  if (check(sic, wcard)) ans++;
  i = 1;
  while (i + p.length() - 1 < s.length()) {
    if (s[i - 1] == '?')
      wcard--;
    else
      sic[s[i - 1] - 'a']--;
    if (s[i + p.length() - 1] == '?')
      wcard++;
    else
      sic[s[i + p.length() - 1] - 'a']++;
    if (check(sic, wcard)) ans++;
    i++;
  }
  cout << ans << "\n";
  return 0;
}
