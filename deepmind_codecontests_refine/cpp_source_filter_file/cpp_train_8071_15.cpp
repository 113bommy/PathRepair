#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const long long int inf = 1e18;
map<char, int> mp;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  char ch = '0';
  long long int ct = 1, ans = 1;
  while (ch <= '9') {
    mp[ch] = ct;
    ch++;
    ct++;
  }
  ch = 'A';
  while (ch <= 'Z') {
    mp[ch] = ct;
    ct++;
    ch++;
  }
  ch = 'a';
  while (ch <= 'z') {
    mp[ch] = ct;
    ct++;
    ch++;
  }
  mp['_'] = ct;
  ct++;
  mp['-'] = ct;
  string s;
  cin >> s;
  for (int i = 0; i < (int)s.size(); i++) {
    for (int j = 0; j < 6; j++) {
      if (!((mp[s[i]] - 1) & (1 << j))) {
        ans = (ans * 3) % 1000000007;
      }
    }
  }
  cout << ans;
  return 0;
}
