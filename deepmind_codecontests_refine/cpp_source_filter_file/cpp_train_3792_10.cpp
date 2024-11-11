#include <bits/stdc++.h>
using namespace std;
using vll = vector<int64_t>;
using vi = vector<int>;
int constexpr Z = 10150;
int constexpr MOD = 1e9 + 7;
void norm(int64_t &a) {
  if (a >= MOD) a -= MOD;
  if (a < 0) a += MOD;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  vll a(n);
  for (auto &i : a) cin >> i;
  int64_t sum = 0;
  vll dp(20200);
  for (int i = 1; i <= n; ++i) {
    vll new_dp(20200);
    new_dp[Z + a[i - 1]] = new_dp[Z - a[i - 1]] = 1;
    for (int j = 0; j < 20200; ++j) {
      if (j - a[i - 1] >= 0) new_dp[j] += dp[j - a[i - 1]];
      if (j + a[i - 1] < 20200) norm(new_dp[j] += dp[j + a[i - 1]]);
    }
    sum += new_dp[Z];
    swap(new_dp, dp);
  }
  cout << sum;
  return 0;
}
