#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
const long long mod = 1e9 + 7;
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = getchar();
  return x * f;
}
long long a[N];
long long dp[N][2];
int main() {
  long long n = read(), r1 = read(), r2 = read(), r3 = read(), d = read();
  for (long long i = 1; i <= n; i++) {
    a[i] = read();
  }
  dp[0][0] = 1e9;
  for (long long i = 1; i <= n; i++) {
    long long c1 = min(a[i] * r1 + 2 * r1, r1 + r2);
    long long c0 = a[i] * r1 + r3;
    dp[i][0] = dp[i - 1][1] + c1 + 2 * d;
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + c0;
    dp[i][1] = min(dp[i][1], dp[i - 1][0] + c1);
    if (i == n) dp[i][1] = min(dp[i][1], dp[i - 1][0] + c0 - d);
  }
  cout << min(dp[n][0], dp[n][1]) + (n - 1) * d << endl;
}
