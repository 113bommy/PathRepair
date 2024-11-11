#include <bits/stdc++.h>
using namespace std;
bool chk(vector<int>& s1, vector<int>& s2, int sz) {
  int c = 0;
  for (int i = 0; i < 27; i++) {
    if ((s1[i] + s2[i]) % 2 != 0) c += 1;
  }
  if (c == 0) return true;
  if (c > 1) return false;
  if (c == 1) {
    if (sz % 2 != 0)
      return true;
    else
      return false;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  unordered_map<string, int> mp;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    vector<int> hh(26, 0);
    for (auto j : s) {
      hh[j - 'a'] += 1;
    }
    string mask = string(26, '0');
    for (int i = 0; i < 26; i++) {
      if (hh[i] % 2 == 0) {
        mask[i] = '0';
      } else
        mask[i] = '1';
    }
    ans += mp[mask];
    for (int j = 0; j < 26; j++) {
      if (mask[j] == '0') {
        string tmp = mask;
        tmp[j] = '1';
        ans += mp[tmp];
      } else {
        string tmp = mask;
        tmp[j] = '0';
        ans += mp[tmp];
      }
    }
    mp[mask] += 1;
  }
  cout << ans << "\n";
}
