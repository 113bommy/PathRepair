#include <bits/stdc++.h>
using namespace std;
const int N = 107;
const int M = 1e9 + 7;
long long f[N], pf[N];
int k, n;
string x;
long long dp[N][N][N];
int ff = 0;
long long calc(int n, int l, int r) {
  if (dp[n][l][r] >= 0) return dp[n][l][r];
  if (n < 2) {
    if (r - l >= 2)
      return dp[n][l][r] = 0;
    else if (r - l == 1)
      return dp[n][l][r] = (n == x[l] - '0');
  }
  if (l == r) {
    if (l == 0 || r == k)
      return dp[n][l][r] = pf[n];
    else
      return dp[n][l][r] = 1;
  }
  long long ans = 0;
  for (int k = l; k <= r; k++)
    ans = (ans + calc(n - 1, l, k) * calc(n - 2, k, r)) % M;
  return dp[n][l][r] = ans;
}
void pre() {
  pf[0] = pf[1] = 2;
  for (int i = 2; i < N; i++) pf[i] = (pf[i - 1] * pf[i - 2]) % M;
}
int main() {
  memset(dp, -1, sizeof dp);
  pre();
  cin >> k >> n >> x;
  cout << calc(n, 0, k) << endl;
}
