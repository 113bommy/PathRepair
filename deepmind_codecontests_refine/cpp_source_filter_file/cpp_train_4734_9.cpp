#include <bits/stdc++.h>
using namespace std;
bool isVowel(char c) {
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}
int main() {
  string s = "";
  getline(cin, s);
  reverse(s.begin(), s.end());
  for (int i = 0; i < s.length(); i++) {
    if (isalpha(s[i]) > 0) {
      if (isVowel(s[i])) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
      break;
    }
  }
  return 0;
}
