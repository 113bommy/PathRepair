#include <bits/stdc++.h>
using namespace std;
char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
bool isVowel(char c) {
  for (int i = 0; i < 5; i++)
    if (vowels[i] == c) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s, t;
  int szS, szT;
  cin >> s >> t;
  szS = s.length();
  szT = s.length();
  if (szS != szT) {
    cout << "No";
    return 0;
  }
  for (int i = 0; i < szS; i++)
    if ((!isVowel(s[i]) && !isVowel(t[i])) ||
        (isVowel(s[i]) && isVowel(t[i])) || (s[i] == t[i])) {
    } else {
      cout << "No";
      return 0;
    }
  cout << "Yes";
  return 0;
}
