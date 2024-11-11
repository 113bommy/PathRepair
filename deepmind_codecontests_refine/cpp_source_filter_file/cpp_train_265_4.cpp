#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
  set<char> special_vowel = {'e', 'o'};
  for (int i = 0; i < n; ++i) {
    if (vowel.find(s[i]) == vowel.end()) {
      cout << s[i];
    } else {
      int len = 0;
      while (i + len < n and s[i] == s[i + len]) {
        ++len;
      }
      if (len == 2 and special_vowel.find(s[i]) != special_vowel.end()) {
        cout << s[i] << s[i];
        ++i;
      } else {
        cout << s[i];
        i += len - 1;
      }
    }
  }
}
