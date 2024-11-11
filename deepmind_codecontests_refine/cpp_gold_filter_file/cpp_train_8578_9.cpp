#include <bits/stdc++.h>
using namespace std;
vector<long long> azaza;
long long x, mid, x1, x2, z, max1, i, j, k, n, y, lp, rp, p, l, r, ql, qr, m,
    M_cnt, k1, k2, ost, ur, a[100500][3], dp[100500][2];
vector<long long> f;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  long long rez;
  string s1, s2, s3;
  cin >> n;
  for (j = 0; j < 3; j++)
    for (i = 0; i < n; i++) cin >> a[i][j];
  for (i = 0; i <= n; i++)
    for (j = 0; j < 2; j++) dp[i][j] = -(long long)1e+10;
  dp[0][0] = a[0][0];
  dp[0][1] = a[0][1];
  for (i = 1; i <= n; i++) {
    dp[i][0] =
        max(dp[i][0], max(dp[i - 1][0] + a[i][1], dp[i - 1][1] + a[i][0]));
    dp[i][1] =
        max(dp[i][1], max(dp[i - 1][0] + a[i][2], dp[i - 1][1] + a[i][1]));
  }
  cout << dp[n - 1][0] << endl;
  return 0;
}
