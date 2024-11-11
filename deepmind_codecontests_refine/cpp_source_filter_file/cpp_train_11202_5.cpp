#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b, c;
  map<char, char> mp;
  mp.clear();
  int s = 0;
  cin >> a;
  cin >> b;
  cin >> c;
  s = c.size();
  for (int i = 0; i < 26; i++) {
    mp[a[i]] = b[i];
  }
  for (int i = 0; i < s; i++) {
    if (c[i] < 97 && c[i] >= 65) {
      c[i] += 32;
      cout << char(mp[c[i]] - 32);
    } else if (c[i] > 97)
      cout << mp[c[i]];
    else
      cout << c[i];
  }
}
