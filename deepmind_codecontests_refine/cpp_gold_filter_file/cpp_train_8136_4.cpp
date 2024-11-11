#include <bits/stdc++.h>
using namespace std;
long long arr[2][100003];
long long dp[2][100003];
long long count(long long n, long long cheak) {
  if (n == 0) return 0;
  if (dp[cheak][n] != -1)
    return dp[cheak][n];
  else {
    dp[cheak][n] =
        max(arr[cheak][n - 1] + count(n - 1, !cheak), count(n - 1, cheak));
    return max(arr[cheak][n - 1] + count(n - 1, !cheak), count(n - 1, cheak));
  }
}
int main() {
  long long n;
  cin >> n;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++) cin >> arr[0][i];
  for (int i = 0; i < n; i++) cin >> arr[1][i];
  long long maxl = max(count(n, 0), count(n, 1));
  cout << maxl << endl;
}
