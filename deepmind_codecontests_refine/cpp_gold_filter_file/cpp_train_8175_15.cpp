#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
map<char, char> mp;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  long long fl = 1;
  mp['a'] = '*';
  mp['b'] = 'd';
  mp['c'] = '*';
  mp['d'] = 'b';
  mp['e'] = '*';
  mp['f'] = '*';
  mp['g'] = '*';
  mp['h'] = '*';
  mp['i'] = '*';
  mp['j'] = '*';
  mp['k'] = '*';
  mp['l'] = '*';
  mp['m'] = '*';
  mp['n'] = '*';
  mp['o'] = 'o';
  mp['p'] = 'q';
  mp['q'] = 'p';
  mp['r'] = '*';
  mp['s'] = '*';
  mp['t'] = '*';
  mp['u'] = '*';
  mp['v'] = 'v';
  mp['w'] = 'w';
  mp['x'] = 'x';
  mp['y'] = '*';
  mp['z'] = '*';
  mp['A'] = 'A';
  mp['B'] = '*';
  mp['C'] = '*';
  mp['D'] = '*';
  mp['E'] = '*';
  mp['F'] = '*';
  mp['G'] = '*';
  mp['H'] = 'H';
  mp['I'] = 'I';
  mp['J'] = '*';
  mp['K'] = '*';
  mp['L'] = '*';
  mp['M'] = 'M';
  mp['N'] = '*';
  mp['O'] = 'O';
  mp['P'] = '*';
  mp['Q'] = '*';
  mp['R'] = '*';
  mp['S'] = '*';
  mp['T'] = 'T';
  mp['U'] = 'U';
  mp['V'] = 'V';
  mp['W'] = 'W';
  mp['X'] = 'X';
  mp['Y'] = 'Y';
  mp['Z'] = '*';
  for (long long i = 0, j = s.size() - 1; i <= j; i++, j--) {
    if (i != j) {
      if (mp[s[i]] != s[j] || mp[s[j]] != s[i]) {
        fl = 0;
        break;
      }
    } else if (mp[s[i]] != s[i]) {
      fl = 0;
    }
  }
  if (fl)
    cout << "TAK" << endl;
  else
    cout << "NIE" << endl;
}
