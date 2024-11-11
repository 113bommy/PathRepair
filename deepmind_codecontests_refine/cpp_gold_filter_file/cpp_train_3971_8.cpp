#include <bits/stdc++.h>
using namespace std;
string s, t, vowel = "aeiou";
bool invowel(char l) {
  for (int i = 0; i < vowel.size(); i++)
    if (vowel[i] == l) return true;
  return false;
}
int main() {
  cin >> s >> t;
  if (s.size() != t.size()) return cout << "No", 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == t[i]) continue;
    if (invowel(s[i]) != invowel(t[i])) return cout << "No", 0;
  }
  cout << "Yes";
  return 0;
}
