#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  string s;
  cin >> s;
  map<char, int> mp;
  for (int i = 0; i < s.size(); i++) {
    mp[s[i]]++;
  }
  int mn = 110;
  if (mn > mp['i']) mn = mp['i'];
  if (mn > mp['t']) mn = mp['t'];
  if (mn > mp['e'] / 3) mn = mp['e'] / 3;
  int tm = (mp['n'] - 2) / 2;
  if (mn > (mp['n'] + tm) / 3) mn = (mp['n'] + tm) / 3;
  cout << mn << endl;
  return 0;
}
