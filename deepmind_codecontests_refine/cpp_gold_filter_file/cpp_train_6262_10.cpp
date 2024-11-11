#include <bits/stdc++.h>
using namespace std;
const long long N = 5000 + 5, mod = 998244353;
long long inv[N], n, dp[N][N];
int mp[N];
long long fp(long long base, long long exp) {
  if (exp == 0) return 1;
  long long ans = fp(base, exp / 2);
  ans = (ans * ans) % mod;
  if (exp % 2 != 0) ans = (ans * (base % mod)) % mod;
  return ans;
}
long long solve(int indx, int ba2e) {
  if (indx == n + 1) return 0;
  if (~dp[indx][ba2e]) return dp[indx][ba2e];
  long long ret = solve(indx + 1, ba2e) % mod;
  if (mp[indx]) {
    long long op = (solve(indx + 1, ba2e - 1) * mp[indx]) % mod;
    op = (op * (inv[ba2e] % mod)) % mod;
    ret = (ret + op) % mod;
    op = (mp[indx] * inv[ba2e]) % mod;
    long long op2 = ((mp[indx] - 1) * (inv[ba2e - 1])) % mod;
    ret = (ret + ((op * op2) % mod)) % mod;
  }
  return dp[indx][ba2e] = ret % mod;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    cin >> n;
    for (long long i = 0; i < N; i++) inv[i] = fp(i, mod - 2);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      mp[x]++;
    }
    memset(dp, -1, sizeof dp);
    cout << solve(1, n);
  }
  return 0;
}
