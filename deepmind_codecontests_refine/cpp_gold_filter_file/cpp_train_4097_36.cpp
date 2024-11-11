#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int count[26];
  int len = s.length();
  for (int i = 0; i < 26; i++) count[i] = 0;
  for (int i = 0; i < len; i++) count[s[i] - 'a']++;
  int x = 25;
  for (int i = 0; i < len; i++) {
    if (count[x] == 0) {
      x--;
      i--;
      continue;
    }
    if (s[i] - 'a' == x) {
      cout << s[i];
      count[x]--;
    } else
      count[s[i] - 'a']--;
  }
  cout << endl;
}
