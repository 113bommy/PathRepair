#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
long long dp[101][1001];
long long C[1001][1001];
long long fact[1001];
void pre() {
  memset(C, 0, sizeof(C));
  memset(dp, 0, sizeof(dp));
  fact[0] = 1;
  for (int i = 1; i < 1001; i++)
    fact[i] = fact[i - 1] * i, fact[i] %= 1000000007;
  for (int i = 1; i < 1001; i++) {
    for (int j = 0; j < i + 1; j++) {
      if (i == j || j == 0)
        C[i][j] = 1;
      else {
        C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        C[i][j] %= 1000000007;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  long long m, n = 0;
  pre();
  cin >> m;
  long long x[m];
  long long y[m];
  for (int i = 0; i < m; i++) cin >> x[i], n += x[i];
  for (int i = 0; i < m; i++) cin >> y[i];
  dp[0][0] = 1;
  long long sum = 0;
  for (int i = 1; i < m + 1; i++) {
    sum += x[i - 1];
    for (int j = 0; j < n + 1; j++) {
      for (int k = 0; k < y[i - 1] + 1; k++) {
        if (k > j || sum < j) break;
        dp[i][j] += (dp[i - 1][j - k] * C[sum - (j - k)][k]) % 1000000007;
        dp[i][j] %= 1000000007;
      }
    }
  }
  long long ans = dp[m][n];
  ans *= fact[n];
  ans %= 1000000007;
  for (int i = 1; i < n + 1; i++)
    ans *= powmod(fact[i], 1000000007 - 2), ans %= 1000000007;
  cout << ans;
  return 0;
}
