#include <bits/stdc++.h>
using namespace std;
int fr[30];
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); ++i) fr[s[i] - 'a']++;
  for (int i = 26; i > 0; --i)
    if (fr[i]) {
      char ch = i + 'a';
      for (int j = 1; j <= fr[i]; ++j) cout << ch;
      return 0;
    }
  return 0;
}
