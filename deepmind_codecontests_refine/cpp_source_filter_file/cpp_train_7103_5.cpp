#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t, n, k;
  string s;
  cin >> t;
  for (int q = 0; q < t; q++) {
    cin >> n >> k;
    cin >> s;
    vector<map<char, int>> m(k / 2 + 1, map<char, int>());
    int o = 0;
    for (int r = 0; r < s.size(); r++) {
      o = (r % k);
      if (o > k / 2) {
        o = k - 1 - o;
      }
      if (m[o].find(s[r]) == m[o].end()) {
        m[o].insert(make_pair(s[r], 1));
      } else {
        m[o][s[r]]++;
      }
    }
    int ans = 0;
    int MAX = 0;
    for (int i = 0; i < k / 2 + 1; i++) {
      MAX = 0;
      for (auto it = m[i].begin(); it != m[i].end(); it++) {
        MAX = max(MAX, it->second);
      }
      ans += MAX;
    }
    cout << n - ans << endl;
  }
  return 0;
}
