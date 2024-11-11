#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  string s;
  cin >> n >> s;
  map<char, long long> mp;
  set<char> se;
  for (long long i = 0; i < n; ++i) {
    mp[s[i]]++;
    se.insert(s[i]);
  }
  string ne = "";
  char lastInserted = '0';
  char firstInserted = '9';
  for (long long i = 0; i < n; ++i) {
    if (*se.begin() == s[i] and s[i] < firstInserted) {
      ne += '1';
      mp[s[i]]--;
      if (mp[s[i]] == 0) {
        se.erase(se.begin());
      }
    } else {
      if (s[i] < lastInserted) {
        cout << "-" << endl;
        return;
      }
      firstInserted = min(s[i], firstInserted);
      lastInserted = s[i];
      mp[s[i]]--;
      if (mp[s[i]] == 0) {
        se.erase(se.find(s[i]));
      }
      ne += '2';
    }
  }
  cout << ne << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
