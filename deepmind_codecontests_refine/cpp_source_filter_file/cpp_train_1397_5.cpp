#include <bits/stdc++.h>
using namespace std;
long long a[105];
long long b[105];
long long dp[105][10005];
long long n;
long long K;
long long fun(int i, int k) {
  if (i > n) {
    if (k == 0) return 0;
    return INT_MIN;
  }
  if (dp[i][k] != -1) return dp[i][k];
  long long a1 = fun(i + 1, k);
  long long b1 = a[i] + fun(i + 1, k + a[i] - b[i] * K);
  return dp[i][k] = max(a1, b1);
}
int main() {
  memset(dp, -1, sizeof dp);
  cin >> n >> K;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  long long x = fun(1, 0);
  if (x < 1) x = -1;
  cout << x << "\n";
  return 0;
}
