#include <bits/stdc++.h>
using namespace std;
map<char, int> mp;
int main() {
  mp['6'] = 1;
  mp['7'] = 2;
  mp['8'] = 3;
  mp['9'] = 4;
  mp['T'] = 5;
  mp['J'] = 6;
  mp['Q'] = 7;
  mp['K'] = 8;
  mp['A'] = 9;
  char suit;
  cin >> suit;
  char x1, s1, x2, s2;
  cin >> x1 >> s1 >> x2 >> s2;
  if (s1 == s2) {
    if (mp[x1] > mp[x2])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else {
    if (s1 == suit)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
