#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:306777216")
using namespace std;
using ll = long long;
using ull = unsigned long long;
using str = string;
const int INF = 1e9 + 7;
const int mod = 998244353;
const ll inf = 1e18;
const ull oo = 1000000000000001;
template <class T>
istream& operator>>(istream& in, vector<T>& arr) {
  for (size_t i = 0; i < arr.size(); ++i) {
    in >> arr[i];
  }
  return in;
}
template <class F, class S>
istream& operator>>(istream& in, pair<F, S>& elem) {
  in >> elem.first >> elem.second;
  return in;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  string s, t;
  cin >> s >> t;
  int cntA = 0;
  vector<vector<int>> dp(k + 2, vector<int>(n + 2));
  for (int i = 0; i < n; ++i) {
    vector<vector<int>> dpp(k + 2, vector<int>(n + 2));
    for (int j = 0; j < min(k + 1, i + 1); ++j) {
      for (int a = 0; a < n; ++a) {
        if (a > cntA + j) {
          continue;
        }
        int nowA = a + (s[i] == t[0]);
        dpp[j][nowA] = max(dpp[j][nowA], dp[j][a] + (s[i] == t[1] ? a : 0));
        dpp[j + 1][a + 1] =
            max(dpp[j + 1][a + 1], dp[j][a] + (t[0] == t[1] ? a : 0));
        dpp[j + 1][a + (t[0] == t[1])] =
            max(dpp[j + 1][a + (t[0] == t[1])], dp[j][a] + a);
      }
    }
    dp = dpp;
    cntA += (s[i] == t[0]);
  }
  int ans = 0;
  for (int i = 0; i <= k; ++i) {
    for (int j = 0; j <= n; ++j) {
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << '\n';
}
