#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1000 * 1000 + 10;
map<int, char> mp;
int main() {
  int n;
  cin >> n;
  mp[2] = '1';
  mp[3] = '7';
  mp[4] = '4';
  mp[5] = '5';
  mp[6] = '9';
  mp[7] = '8';
  string ans = "";
  for (int i = 2; i <= 7; i++) {
    string tmp = "";
    if ((n - i) % 2 == 0 && n >= i) {
      tmp += mp[i];
      for (int j = 0; j < (n - i) / 2; j++) tmp += '1';
      if (ans < tmp && ans.size() <= tmp.size()) ans = tmp;
    }
  }
  cout << ans;
  return 0;
}
