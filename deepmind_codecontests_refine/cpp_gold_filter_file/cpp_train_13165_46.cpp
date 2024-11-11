#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, int> m;
  m['0'] = 2;
  m['1'] = 7;
  m['2'] = 2;
  m['3'] = 3;
  m['4'] = 3;
  m['5'] = 4;
  m['6'] = 2;
  m['7'] = 5;
  m['8'] = 1;
  m['9'] = 2;
  string s;
  cin >> s;
  cout << m[s[0]] * m[s[1]];
  return 0;
}
