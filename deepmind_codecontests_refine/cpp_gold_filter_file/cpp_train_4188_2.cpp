#include <bits/stdc++.h>
using namespace std;
long long int ft[100005];
void factorial(long long int p) {
  ft[0] = 1;
  for (long long int i = 1; i < 100005; i++) {
    ft[i] = (ft[i - 1] * i) % p;
  }
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int ncr(long long int n, long long int r, long long int p) {
  factorial(p);
  return (ft[n] * ((power(ft[r], p - 2, p) * power(ft[n - r], p - 2, p)) % p)) %
         p;
}
signed main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n];
    long long int sum = 0;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      sum = sum + a[i];
    }
    long long int dp[2][n + 1];
    dp[0][0] = 0;
    dp[1][n] = 0;
    for (long long int i = 0; i < n; i++) {
      dp[0][i + 1] = dp[0][i] + a[i];
    }
    for (long long int i = n - 1; i >= 0; i--) {
      dp[1][i] = dp[1][i + 1] + a[i];
    }
    long long int flag = 1;
    long long int l = 0;
    long long int r = 0;
    long long int f = 0;
    for (long long int i = 0; i < n && f == 0; i++) {
      if (a[i] <= 0) {
        if (flag == 1) {
          l = i;
          r = i + 1;
          if (dp[0][l] >= sum || dp[1][r] >= sum) {
            cout << "NO" << endl;
            f = 1;
          }
        } else {
          r = i + 1;
          if (dp[0][l] >= sum || dp[1][r] >= sum) {
            cout << "NO" << endl;
            f = 1;
          }
        }
        flag = 0;
      } else {
        flag = 1;
      }
    }
    if (f == 0) cout << "YES" << endl;
  }
}
