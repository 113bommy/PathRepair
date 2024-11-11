#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, long long> mp;
  mp['>'] = 8;
  mp['<'] = 9;
  mp['+'] = 10;
  mp['-'] = 11;
  mp['.'] = 12;
  mp[','] = 13;
  mp['['] = 14;
  mp[']'] = 15;
  string s, t;
  cin >> s;
  long long d = 0, p = 0, x = 1;
  for (long long i = s.size() - 1; i >= 0; i--) {
    p = mp[s[i]];
    d = (d + (x * p)) % 1000003;
    x = (x * 16) % 1000003;
  }
  cout << d << endl;
}
