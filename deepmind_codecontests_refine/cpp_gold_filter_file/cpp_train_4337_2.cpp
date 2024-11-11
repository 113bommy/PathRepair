#include <bits/stdc++.h>
using namespace std;
const long long int maxN = 1e5 + 10;
long long int n, k, dp[102][100002], a[102];
long long int f(long long int m, long long int n) {
  if (!n) return m;
  if (n < 100 && m < 100000 && dp[n][m] + 1) return dp[n][m];
  if (n < 100 && m < 100000) {
    dp[n][m] = f(m, n - 1) - f(m / a[n], n - 1);
    return dp[n][m];
  }
  return f(m, n - 1) - f(m / a[n], n - 1);
}
int main() {
  memset(dp, -1, sizeof dp);
  cin >> n >> k;
  for (long long int i = 1; i <= k; i++) cin >> a[i];
  sort(a, a + k + 1);
  cout << f(n, k) << endl;
}
