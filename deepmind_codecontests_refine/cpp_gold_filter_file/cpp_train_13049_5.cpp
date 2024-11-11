#include <bits/stdc++.h>
using namespace std;
long long int inv[128], fac[128];
int N, A[10];
long long int dp[128][10];
bool vis[128][10];
long long int solve(int n, int d) {
  if (d == 10) {
    if (n == 0)
      return 1;
    else
      return 0;
  }
  if (vis[n][d]) return dp[n][d];
  vis[n][d] = true;
  long long int total = 0;
  for (int i = A[d]; i <= n; i++)
    total = (total + (inv[i] * solve(n - i, d + 1)) % 1000000007) % 1000000007;
  return dp[n][d] = total;
}
int main() {
  fac[0] = fac[1] = 1;
  for (int i = 2; i < 128; i++) fac[i] = (i * fac[i - 1]) % 1000000007;
  inv[0] = inv[1] = 1;
  for (int i = 2; i < 128; i++)
    inv[i] =
        (1000000007 - (1000000007 / i) * inv[1000000007 % i] % 1000000007) %
        1000000007;
  for (int i = 2; i < 128; i++) inv[i] = (inv[i - 1] * inv[i]) % 1000000007;
  cin >> N;
  for (int i = 0; i < 10; i++) cin >> A[i];
  long long int ans = 0;
  if (A[0] == 0) {
    for (int i = 1; i <= N; i++)
      ans = (ans + (fac[i] * solve(i, 1)) % 1000000007) % 1000000007;
    A[0] = 1;
  }
  for (int i = A[0]; i <= N; i++)
    for (int j = A[0]; j <= i; j++) {
      long long int p = (inv[j] * solve(i - j, 1)) % 1000000007;
      p = (p * fac[i]) % 1000000007;
      long long int n = (inv[j - 1] * solve(i - j, 1)) % 1000000007;
      n = (n * fac[i - 1]) % 1000000007;
      ans = (ans + p + 1000000007 - n) % 1000000007;
    }
  cout << ans << endl;
  return 0;
}
