#include <bits/stdc++.h>
using namespace std;
long long int fact[100010];
long long int ifact[100010];
long long int ncr(int n, int r) {
  if (r < 0 || n < 0) return 0;
  return (fact[n] * ifact[n - r] % 1000000007) * ifact[r] % 1000000007;
}
int A[10];
long long int dp[11][101];
int main() {
  fact[0] = 1;
  for (int i = 1; i < 100010; i++) fact[i] = (fact[i - 1] * i) % 1000000007;
  ifact[0] = ifact[1] = 1;
  for (int i = 2; i < 100010; i++)
    ifact[i] =
        (1000000007 - (1000000007 / i) * ifact[1000000007 % i] % 1000000007) %
        1000000007;
  for (int i = 1; i < 100010; i++)
    ifact[i] = (ifact[i - 1] * ifact[i]) % 1000000007;
  int N;
  cin >> N;
  for (int i = 0; i < 10; i++) cin >> A[i];
  dp[10][0] = 1;
  for (int i = 9; i >= 0; i--)
    for (int j = A[i]; j <= N; j++)
      for (int k = A[i]; k <= j; k++) {
        int rem = (j - k) + (i > 0 ? 1 : 0);
        int n = k, r = rem;
        dp[i][j] =
            (dp[i][j] + ncr(n + r - 1, r - 1) * dp[i + 1][j - k]) % 1000000007;
      }
  long long int total = 0;
  for (int i = 1; i <= N; i++) total = (total + dp[0][i]) % 1000000007;
  cout << total << endl;
  return 0;
}
