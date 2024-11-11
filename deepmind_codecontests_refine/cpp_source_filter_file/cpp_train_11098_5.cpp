#include <bits/stdc++.h>
using namespace std;
int main() {
  char c1, c2;
  int n;
  cin >> c1 >> c2 >> n;
  n %= 4;
  map<char, int> mp;
  mp['^'] = 0;
  mp['>'] = 1;
  mp['v'] = 2;
  mp['<'] = 3;
  int x = mp[c1], y = mp[c2];
  if ((x + n) % 4 == y && (x - n + 4) % 4 != y)
    cout << "cw" << endl;
  else if ((x + n) % 4 != y && (x - n) % 4 == y)
    cout << "ccw" << endl;
  else
    cout << "undefined" << endl;
  return 0;
}
