#include <bits/stdc++.h>
using namespace std;
string str = "0123456789ABCDEF";
int main() {
  map<char, int> mp;
  mp['0'] = 1;
  mp['1'] = 0;
  mp['2'] = 0;
  mp['3'] = 0;
  mp['4'] = 1;
  mp['5'] = 0;
  mp['6'] = 1;
  mp['7'] = 0;
  mp['8'] = 2;
  mp['9'] = 1;
  mp['A'] = 1;
  mp['B'] = 2;
  mp['C'] = 0;
  mp['D'] = 1;
  mp['E'] = 0;
  mp['F'] = 0;
  long long n;
  cin >> n;
  if (n == 0) {
    cout << 1 << endl;
    return 0;
  }
  string ans;
  while (n) {
    ans += str[n % 16];
    n = n / 16;
  }
  int res = 0;
  for (int i = 0; i < ans.size(); i++) {
    res += mp[ans[i]];
  }
  cout << res << endl;
}
