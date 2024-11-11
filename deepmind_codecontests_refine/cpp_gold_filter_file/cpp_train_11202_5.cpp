#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1;
  string s2;
  s1.reserve(27);
  s2.reserve(27);
  getline(cin, s1);
  getline(cin, s2);
  map<char, char> symbols;
  for (short i = 0; i < 26; ++i) {
    symbols.insert(make_pair(s1[i], s2[i]));
  }
  std::transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
  std::transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
  for (short i = 0; i < 26; ++i) {
    symbols.insert(make_pair(s1[i], s2[i]));
  }
  s1.reserve(1001);
  getline(cin, s1);
  for (short i = 0; i < s1.length(); ++i) {
    if (s1[i] > '9' || s1[i] < '0') s1[i] = symbols[s1[i]];
  }
  cout << s1;
  return 0;
}
