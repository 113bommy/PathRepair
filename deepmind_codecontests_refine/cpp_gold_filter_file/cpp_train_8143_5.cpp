#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  string s;
  int t[128];
  t['>'] = 8;
  t['<'] = 9;
  t['+'] = 10;
  t['-'] = 11;
  t['.'] = 12;
  t[','] = 13;
  t['['] = 14;
  t[']'] = 15;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < (int)(s).size(); ++i) {
    ans = (ans * 16 + t[(int)s[i]]) % 1000003;
  }
  cout << ans << endl;
  return 0;
}
