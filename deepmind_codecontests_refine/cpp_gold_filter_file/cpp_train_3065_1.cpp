#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
template <class T>
typename T::value_type arr_sum(const T& v, int n) {
  typename T::value_type sum = 0;
  for (int i = (0); i < (n); ++i) sum += v[i];
  return sum;
}
struct Sync_stdio {
  Sync_stdio() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
  }
} _sync_stdio;
int main() {
  int n, m, s, e;
  cin >> n >> m >> s >> e;
  vector<int> v(n);
  vector<int> w(m);
  for (int __i = 0; __i < (n); ++__i) cin >> v[__i];
  ;
  for (int __i = 0; __i < (m); ++__i) cin >> w[__i];
  ;
  const int C = 305;
  vector<vector<int>> dp(C, vector<int>(n, INT_MAX));
  vector<vector<int>> dpmin(C, vector<int>(n, INT_MAX));
  vector<vector<int>> second(100001);
  for (int i = (0); i < (m); ++i) {
    second[w[i]].push_back(i);
  }
  for (int i = (0); i < (n); ++i) {
    dp[0][i] = -1;
    dpmin[0][i] = -1;
  }
  for (int i = (1); i < (C); ++i) {
    for (int j = (0); j < (n); ++j) {
      int x = j - 1 >= 0 ? dpmin[i - 1][j - 1] : i == 1 ? -1 : INT_MAX;
      auto& b = second[v[j]];
      auto t = upper_bound(b.begin(), b.end(), x);
      if (t != b.end()) {
        dp[i][j] = *t;
      }
      dpmin[i][j] = dp[i][j];
      if (j > 0) {
        dpmin[i][j] = min(dpmin[i][j], dpmin[i][j - 1]);
      }
    }
  }
  int res = 0;
  for (int i = (0); i < (C); ++i) {
    for (int j = (0); j < (n); ++j) {
      if (dp[i][j] == INT_MAX) {
        continue;
      }
      long long t = (long long)s - (long long)e * i - j - dp[i][j] - 2;
      if (t >= 0) {
        res = max(res, i);
      }
    }
  }
  cout << res;
}
