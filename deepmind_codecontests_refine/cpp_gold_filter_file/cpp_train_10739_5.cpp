#include <bits/stdc++.h>
long long MOD = 998244353;
using namespace std;
vector<vector<long long> > dp(501, vector<long long>(501, 0));
vector<long long> c(501);
vector<vector<long long> > used(501, vector<long long>(501, 0));
long long solve(long long l, long long r, long long N) {
  if (r <= l) return 1;
  if (used[l][r]) return dp[l][r];
  dp[l][r] = 0;
  used[l][r] = 1;
  long long pos = l;
  for (int i = l + 1; i <= r; i++) {
    if (c[pos] > c[i]) pos = i;
  }
  for (int i = 1; i < l; i++) {
    if (c[i] == c[pos]) return 0;
  }
  for (int i = r + 1; i <= N; i++) {
    if (c[i] == c[pos]) return 0;
  }
  long long left_dp = 0, right_dp = 0;
  for (int i = l; i <= pos; i++) {
    left_dp = (left_dp + solve(l, i - 1, N) * solve(i, pos - 1, N)) % MOD;
  }
  for (int i = pos; i <= r; i++) {
    right_dp = (right_dp + solve(pos + 1, i, N) * solve(i + 1, r, N)) % MOD;
  }
  long long ans = (left_dp * right_dp) % MOD;
  dp[l][r] = ans;
  return ans;
}
int main() {
  long long n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) cin >> c[i];
  cout << solve(1, n, n);
  return 0;
}
