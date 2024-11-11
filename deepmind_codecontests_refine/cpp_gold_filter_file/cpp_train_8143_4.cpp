#include <bits/stdc++.h>
using namespace std;
int main() {
  map<char, int> dig;
  dig['>'] = 8;
  dig['<'] = 9;
  dig['+'] = 10;
  dig['-'] = 11;
  dig['.'] = 12;
  dig[','] = 13;
  dig['['] = 14;
  dig[']'] = 15;
  string str;
  cin >> str;
  long long ans = 0;
  for (unsigned int i = 0; i < str.size(); ++i) {
    ans *= 16;
    ans += dig[str[i]];
    ans %= 1000003;
  }
  cout << ans << endl;
}
