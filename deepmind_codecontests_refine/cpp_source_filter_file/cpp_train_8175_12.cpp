#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
map<char, bool> sym;
string s;
void init() {
  sym['A'] = 1;
  sym['H'] = 1;
  sym['I'] = 1;
  sym['N'] = 1;
  sym['O'] = 1;
  sym['T'] = 1;
  sym['U'] = 1;
  sym['V'] = 1;
  sym['W'] = 1;
  sym['X'] = 1;
  sym['Y'] = 1;
  sym['o'] = 1;
  sym['v'] = 1;
  sym['w'] = 1;
  sym['x'] = 1;
}
int main() {
  init();
  cin >> s;
  int n = s.size();
  bool yes = true;
  for (int i = 0; i < n; i++) {
    char lf = s[i], rg = s[n - i - 1];
    if (lf == 'b' && rg == 'd')
      ;
    else if (lf == 'd' && rg == 'b')
      ;
    else if (lf == 'p' && rg == 'q')
      ;
    else if (lf == 'q' && rg == 'p')
      ;
    else if (lf == rg && sym[lf])
      ;
    else
      yes = false;
  }
  if (yes)
    cout << "TAK\n";
  else
    cout << "NIE\n";
  return 0;
}
