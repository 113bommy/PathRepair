#include <bits/stdc++.h>
using namespace std;
map<char, char> mp;
string check(string s) {
  for (int i = 0; i <= s.size() / 2; i++)
    if (s[i] != mp[s[s.size() - 1 - i]]) return "NIE";
  return "TAK";
}
int main() {
  mp['A'] = 'A';
  mp['b'] = 'd';
  mp['d'] = 'b';
  mp['H'] = 'H';
  mp['I'] = 'I';
  mp['M'] = 'M';
  mp['O'] = 'O';
  mp['o'] = 'o';
  mp['p'] = 'q';
  mp['q'] = 'p';
  mp['T'] = 'T';
  mp['U'] = 'U';
  mp['V'] = 'V';
  mp['v'] = 'v';
  mp['W'] = 'W';
  mp['w'] = 'w';
  mp['X'] = 'X';
  mp['x'] = 'x';
  mp['Y'] = 'Y';
  string s;
  cin >> s;
  cout << check(s) << endl;
}
