#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<long long> x(26);
  for (int i = 0; i < 26; ++i) {
    cin >> x[i];
  }
  string s;
  cin >> s;
  int n = s.length();
  vector<long long> pre(n);
  vector<vector<int>> pos(26);
  for (int i = 0; i < n; ++i) {
    pre[i] = x[s[i] - 'a'] + (i > 0 ? pre[i - 1] : 0LL);
    pos[s[i] - 'a'].push_back(i);
  }
  long long ans = 0;
  for (int i = 0; i < 26; ++i) {
    map<int, long long> mp;
    for (int j : pos[i]) mp[pre[j]]++;
    for (int j : pos[i]) {
      mp[pre[j]]--;
      ans += mp[pre[j] + x[i]];
    }
  }
  cout << ans;
  return 0;
}
