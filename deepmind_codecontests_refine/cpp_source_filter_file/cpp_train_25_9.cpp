#include <bits/stdc++.h>
#pragma GCC optimize("-Ofast")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-funroll-loops")
using namespace std;
using ll = long long;
using ld = long double;
const int N = 2e5 + 7, mod = 1e9 + 7;
const ll inf = 2e18;
int n;
string s[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
    }
    int a = s[0][1] + s[1][0] - 2 * '0',
        b = s[n - 1][n - 2] + s[n - 2][n - 1] - 2 * '0';
    vector<pair<int, int> > ans;
    if (a == 0) {
      if (s[n - 1][n - 2] == '0') ans.push_back({n, n - 1});
      if (s[n - 2][n - 1] == '0') ans.push_back({n - 1, n});
    } else if (a == 1) {
      if (b == 1) {
        if (s[0][1] == '0') ans.push_back({1, 2});
        if (s[1][0] == '0') ans.push_back({2, 1});
        if (s[n - 1][n - 2] == '0') ans.push_back({n, n - 1});
        if (s[n - 2][n - 1] == '0') ans.push_back({n - 1, n});
      } else if (b == 0) {
        if (s[0][1] == '0') ans.push_back({1, 2});
        if (s[1][0] == '0') ans.push_back({2, 1});
      } else {
        if (s[0][1] == '1') ans.push_back({1, 2});
        if (s[1][0] == '1') ans.push_back({2, 1});
      }
    } else {
      if (s[n - 1][n - 2] == '1') ans.push_back({n, n - 1});
      if (s[n - 2][n - 1] == '1') ans.push_back({n - 1, n});
    }
    cout << (int)ans.size() << "\n";
    for (auto u : ans) cout << u.first << " " << u.second << "\n";
  }
  return 0;
}
