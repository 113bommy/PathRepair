#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, r;
  cin >> t >> r;
  int n = 402;
  long long f[n];
  f[0] = 1;
  for (long long i = 1; i < n; i++) f[i] = (f[i - 1] * i) % r;
  long long d[n], p[n], dp[n][n];
  p[1] = 1;
  d[1] = 1;
  for (long long i = 2; i < n; i++) {
    d[i] = f[i];
    for (long long j = 1; j < i; j++) d[i] = (d[i] - d[j] * f[i - j]) % r;
    if (d[i] < 0) d[i] += r;
  }
  dp[0][0] = 1;
  for (long long i = 1; i < n; i++) {
    dp[i][1] = f[i];
    for (long long j = 2; j <= i; j++)
      for (long long k = 1; k < i; k++)
        dp[i][j] = (dp[i][j] + f[k] * dp[i - k][j - 1]) % r;
  }
  for (long long i = 2; i < n; i++) {
    long long h = 0;
    for (long long j = 1; j < i - 1; j++) {
      for (long long k = j; k < i - 1; k++) {
        long long c = f[k - j + 1];
        c = (c * d[j]) % r;
        c = (c * d[i - k - 1]) % r;
        h += c;
        if (h >= r) h -= r;
      }
    }
    h = (h * 2) % r;
    long long s = f[i];
    s = (s - h + r) % r;
    for (long long j = 3; j < i; j++) {
      s = (s - dp[i][j] * p[j]) % r;
    }
    if (i != 2) {
      for (long long j = 1; j < i; j++) s = (s - d[j] * d[i - j]) % r;
      for (long long j = 1; j < i; j++) s = (s - d[j] * d[i - j]) % r;
    }
    s = (s + r) % r;
    p[i] = s;
  }
  while (t--) {
    long long a;
    cin >> a;
    cout << p[a] << endl;
  }
  return 0;
}
