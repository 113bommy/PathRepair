#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long dp1[200005][2];
long long dp3[200005];
long long f1(long long i, long long j) {
  if (dp1[i][j] != -1) return dp1[i][j];
  if (i == 0) {
    if (j == 0)
      return dp1[i][j] = 1;
    else
      return dp1[i][j] = 0;
  }
  return dp1[i][j] = (f1(i - 1, j) + f1(i - 1, (j + 1) % 2)) % mod;
}
long long f2(vector<long long> &dp2, long long i, long long n) {
  if (i == 0) {
    return dp3[i] = 1;
  }
  if (dp3[i] != -1) return dp3[i];
  long long ans = 0;
  if (n % 2) {
    ans += f2(dp2, i - 1, n);
    ans %= mod;
  } else {
    ans += dp2[i - 1];
    ans %= mod;
  }
  long long d = dp1[n][0];
  if (n % 2 == 0) {
    d = (d - 1 + mod) % mod;
  }
  ans += d * f2(dp2, i - 1, n) % mod;
  ans %= mod;
  return dp3[i] = ans;
}
void solvef() {
  long long n, k;
  cin >> n >> k;
  for (int i = 0; i < 200005; i++) dp1[i][0] = dp1[i][1] = -1;
  f1(n, 0);
  if (k == 0) {
    cout << 1 << endl;
    return;
  }
  long long pn = 1;
  for (int i = 0; i < n; i++) pn = pn * n % mod;
  vector<long long> dp2(k + 1);
  dp2[0] = 1;
  for (int i = 1; i <= k; i++) {
    dp2[i] = dp2[i - 1] * pn % mod;
  }
  for (int i = 0; i < 200005; i++) dp3[i] = -1;
  long long ans = f2(dp2, k, n);
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) solvef();
  return 0;
}
