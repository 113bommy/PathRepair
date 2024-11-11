#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
using namespace std;
const long long mod = 998244351;
long long F[155];
long long I[155];
long long powmod(long long a, long long b) {
  long long res = 1;
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) res = res * a % mod;
  return res;
}
long long inv(long long a) { return powmod(a, mod - 2); }
long long C(long long n, long long r) {
  if (r < 0 || r > n) return 0;
  long long res = 1;
  for (long long i = n; i > n - r; i--) res = res * i % mod;
  return res * I[r] % mod;
}
long long l[115], r[115];
long long emp[115][115];
long long dp[115][230][115];
int main() {
  ios_base::sync_with_stdio(false);
  F[0] = 1;
  for (int i = 1; i <= 104; i++) F[i] = F[i - 1] * i % mod;
  I[104] = inv(F[104]);
  for (int i = 104; i > 0; i--) I[i - 1] = I[i] * i % mod;
  int n;
  cin >> n;
  vector<int> comp;
  long long x = 1;
  for (int i = n; i; i--) {
    cin >> l[i] >> r[i];
    r[i]++;
    comp.push_back(l[i]);
    comp.push_back(r[i]);
    x = (x * inv(r[i] - l[i])) % mod;
  }
  comp.push_back(-1);
  sort(comp.begin(), comp.end());
  comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
  int m = comp.size() - 1;
  for (int i = 0; i < m; i++)
    for (int j = 0; j <= n; j++)
      emp[i][j] = C(comp[i + 1] - comp[i] + j - 1, j);
  for (int i = 1; i <= n; i++) {
    l[i] = lower_bound(comp.begin(), comp.end(), l[i]) - comp.begin();
    r[i] = lower_bound(comp.begin(), comp.end(), r[i]) - comp.begin();
  }
  dp[0][0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = l[i]; j < r[i]; j++) {
      for (int k = 1; k <= i; k++)
        if (k > 1)
          dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % mod;
        else
          for (int jj = 0; jj < j; jj++)
            dp[i][j][k] = (dp[i][j][k] + dp[i - 1][jj][0]) % mod;
      for (int k = 1; k <= i; k++)
        dp[i][j][0] = (dp[i][j][0] + dp[i][j][k] * emp[j][k]) % mod;
    }
  long long ans = 0;
  for (int i = 1; i <= m; i++) ans = (ans + dp[n][i][0]) % mod;
  ans = ans * x % mod;
  cout << ans;
}
