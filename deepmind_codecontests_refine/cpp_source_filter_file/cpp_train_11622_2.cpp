#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
int main() {
  int n, ans = 0;
  cin >> n;
  string s, s1, s2;
  while (n--) {
    cin >> s;
    s1 = "";
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'u') {
        s1 += "oo";
        continue;
      }
      if (s[i] == 'h') {
        int len = s1.length();
        len--;
        while (s1[len] == 'k') len--;
        s2 = "";
        for (int j = 0; j <= len; j++) s2[j] = s1[j];
        s2 += 'h';
        s1 = s2;
        continue;
      }
      s1 += s[i];
    }
    if (mp[s1] == 0) ans++, mp[s1]++;
  }
  cout << ans << endl;
  return 0;
}
