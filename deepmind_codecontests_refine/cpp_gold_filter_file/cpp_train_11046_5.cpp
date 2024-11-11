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
  int n;
  cin >> n;
  string a[n];
  vector<vector<int> > vi(n);
  map<long long, long long> mp;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    a[i] = s;
    vector<int> hh(26, 0);
    long long mask = 0;
    for (auto j : s) {
      hh[j - 'a'] += 1;
    }
    for (int i = 0; i < 26; i++) {
      if (hh[i] % 2 == 0) {
        mask += (1 << i);
      }
    }
    ans += mp[mask];
    for (int j = 0; j < 26; j++) {
      long long tmp = mask ^ (1 << j);
      int p = mp.count(tmp);
      if (tmp > 0) {
        ans += mp[tmp];
      }
    }
    mp[mask] += 1;
  }
  cout << ans << "\n";
}
