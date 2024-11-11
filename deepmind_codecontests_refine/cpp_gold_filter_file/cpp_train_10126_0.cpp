#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int MAXN = (int)1e6 + 6;
int T;
int main() {
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    unordered_map<char, int> mp;
    mp.clear();
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      for (int l = 0; l < s.length(); ++l) ++mp[s[l]];
    }
    if (n == 1) {
      cout << "YES\n";
      continue;
    }
    int ok = 1;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
      if ((int)it->second % n != 0) ok = 0;
    }
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
