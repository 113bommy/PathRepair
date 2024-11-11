#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, int> mp;
  mp['0'] = 0;
  mp['1'] = 1;
  mp['2'] = 2;
  mp['3'] = 3;
  mp['4'] = 4;
  mp['5'] = 5;
  mp['6'] = 6;
  mp['7'] = 7;
  mp['8'] = 8;
  mp['9'] = 9;
  int ls = 0, rs = 0, n;
  bool c4 = 0, c7 = 0;
  string x;
  cin >> n;
  cin >> x;
  for (int i = 0; i < n; i++) {
    if (mp[x[i]] == 4)
      c4 = 1;
    else if (mp[x[i]] == 7)
      c7 = 1;
    else {
      cout << "NO" << '\n';
      return 0;
    }
    if (i < (n / 2))
      ls += mp[x[i]];
    else
      rs += mp[x[i]];
  }
  if ((c4 || c7) && ls == rs)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
