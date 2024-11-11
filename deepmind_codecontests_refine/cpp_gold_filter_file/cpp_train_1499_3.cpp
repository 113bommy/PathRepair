#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  map<string, int> mp, mp2;
  string s[10000];
  int n[10000];
  for (int i = 0; i < t; i++) {
    cin >> s[i] >> n[i];
    mp[s[i]] += n[i];
  }
  int m = 0;
  for (int i = 0; i < t; i++) {
    m = max(m, mp[s[i]]);
  }
  string ans;
  for (int i = 0; i < t; i++) {
    mp2[s[i]] += n[i];
    if (mp2[s[i]] >= m && mp[s[i]] == m) {
      ans = s[i];
      break;
    }
  }
  cout << ans << endl;
}
