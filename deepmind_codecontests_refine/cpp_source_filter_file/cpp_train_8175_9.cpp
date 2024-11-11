#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  char sym[] = {'A', 'O', 'M', 'H', 'I', 'M', 'o', 'T',
                'V', 'W', 'U', 'X', 'Y', 'x', 'w', 'v'};
  map<char, char> mp;
  mp['b'] = 'd';
  mp['d'] = 'b';
  mp['p'] = 'q';
  mp['q'] = 'p';
  string s;
  cin >> s;
  int n = s.length();
  int a = n / 2 - 1, b;
  if (n & 1)
    b = n / 2 + 1;
  else
    b = n / 2;
  if (n & 1 && count(sym, sym + 15, s[n / 2]) == 0) {
    cout << "NIE";
    return 0;
  }
  for (int i = 0, j = n - 1; i <= a && j >= b; i++, j--) {
    if (s[i] == s[j] && count(sym, sym + 16, s[i]) == 1) {
      continue;
    }
    if (mp[s[i]] == s[j] && mp[s[j]] == s[i]) {
      continue;
    }
    cout << "NIE";
    return 0;
  }
  cout << "TAK";
}
