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
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> g(n - 1);
  for (int i = (0); i < (n - 1); ++i) {
    cin >> g[i].first >> g[i].second;
    --g[i].first;
    --g[i].second;
  }
  vector<vector<long long>> dp(k + 1, vector<long long>(n));
  vector<vector<long long>> dp2(k + 1, vector<long long>(n));
  for (int i = (0); i < (n); ++i) {
    dp2[0][i] = dp[0][i] = 1;
  }
  for (auto i : g) {
    ++dp[1][i.first];
    ++dp[1][i.second];
    ++dp2[1][i.first];
    ++dp2[1][i.second];
  }
  for (int i = (2); i < (k + 1); ++i) {
    for (auto j : g) {
      dp[i][j.second] += dp2[i - 1][j.first];
      dp[i][j.second] -= dp2[i - 2][j.second];
      dp[i][j.first] += dp2[i - 1][j.second];
      dp[i][j.first] -= dp2[i - 2][j.first];
    }
    for (int j = (0); j < (n); ++j) {
      dp2[i][j] = dp[i][j] + dp2[i - 2][j];
    }
  }
  cout << accumulate(dp[k].begin(), dp[k].end(), 0LL) / 2;
}
