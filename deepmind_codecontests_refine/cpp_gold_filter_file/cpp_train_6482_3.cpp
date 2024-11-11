#include <bits/stdc++.h>
using namespace std;
long long dp[100001][2];
long long fun(long long i, long long a[], long long n, long long ck) {
  if (i == n - 1) {
    if (ck == 1) return 1;
    return 2;
  }
  if (dp[i][ck - 1] != -1) return dp[i][ck - 1];
  if (a[i] == 0) return dp[i][ck - 1] = fun(i + 1, a, n, ck);
  if (a[i] == 1) return dp[i][ck - 1] = fun(i + 1, a, n, 3 - ck);
  if (fun(i + 1, a, n, ck) == ck) return dp[i][ck - 1] = ck;
  if (fun(i + 1, a, n, 3 - ck) == ck) return dp[i][ck - 1] = ck;
  return dp[i][ck - 1] = 3 - ck;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    memset(dp, -1, sizeof dp);
    for (long long i = 0; i < n; i++) cin >> a[i];
    if (fun(0, a, n, 1) == 1)
      cout << "First"
           << "\n";
    else
      cout << "Second\n";
  }
  return 0;
}
