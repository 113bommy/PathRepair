#include <bits/stdc++.h>
using namespace std;
long long a[100002];
long long dp[100002];
int main() {
  long long n, i, j, x;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> x;
    a[x]++;
  }
  dp[1] = a[1];
  for (i = 2; i <= 1e5; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + a[i] * i);
  }
  cout << dp[(int)1e5];
  return 0;
}
