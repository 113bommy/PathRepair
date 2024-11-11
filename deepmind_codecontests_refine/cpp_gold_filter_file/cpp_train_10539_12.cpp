#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ii = pair<ll, ll>;
string S, A;
ll dp[4000][4000], mod = 998244353;
ll solve(ll n, ll j) {
  if (dp[n][j] != -1) return dp[n][j];
  if (n >= A.size() && j == 0) {
    return dp[n][j] = S.size() - n + 1;
  }
  if (n == S.size()) return dp[n][j] = 0;
  ll& ret = dp[n][j];
  ret = 0;
  if (j != 0 && S[n] == A[j - 1]) {
    ret = (ret + solve(n + 1, j - 1)) % mod;
  }
  if (j + n < A.size() && S[n] == A[j + n]) {
    ret = (ret + solve(n + 1, j)) % mod;
  } else if (j + n >= A.size()) {
    if (j >= A.size()) {
      ret = (ret + 2 * solve(n + 1, j)) % mod;
    } else
      ret = (ret + solve(n + 1, j)) % mod;
  }
  return ret;
}
int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> S >> A;
  for (int i = (0); i < (4000); i++) {
    for (int j = (0); j < (4000); j++) {
      dp[i][j] = -1;
    }
  }
  ll ret = 0;
  for (int i = (0); i < (A.size()); i++) {
    if (S[0] == A[i]) {
      ret = (ret + solve(1, i)) % mod;
    }
  }
  ret = (ret + solve(1, A.size())) % mod;
  cout << (2 * ret) % mod << endl;
  return 0;
}
