#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e+9 + 7;
const long long MAXN = 1e+5 + 7;
const long long INF = 1e+18;
long long n, m;
long long res1, res2;
long long dp[MAXN][47] = {};
long long add(long long a, long long b) { return (a + b) % MOD; }
long long mult(long long a, long long b) { return (a * b) % MOD; }
long long sub(long long a, long long b) { return (a - b + MOD) % MOD; }
long long fastexp(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) {
      res = mult(res, x);
    }
    y /= 2;
    x = mult(x, x);
  }
  return res;
}
long long solve(long long n, long long m) {
  if (m == 1) swap(n, m);
  if (m == 1 && n == 1) {
    return 2;
  }
  dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 1;
  long long res = 0;
  for (int i = 2; i < m - 1; i += 2) {
    dp[i][0] = add(add(dp[i - 2][0], dp[i - 2][1]), dp[i - 2][3]);
    dp[i][1] = add(add(dp[i - 2][0], dp[i - 2][1]), dp[i - 2][2]);
    dp[i][2] = add(dp[i - 2][0], dp[i - 2][3]);
    dp[i][3] = add(dp[i - 2][1], dp[i - 2][2]);
  }
  if (m & 1) {
    int i = m - 1;
    res = add(res, add(add(mult(dp[i - 2][0], 2), mult(dp[i - 2][1], 2)),
                       add(dp[i - 2][2], dp[i - 2][3])));
  }
  if (m & 1 && n == 1) {
    res1 = res;
  } else if (m % 2 != 0 && n != 1)
    res1 = add(add(add(dp[m - 1][0], dp[m - 1][1]),
                   add(dp[m - 1][2], dp[m - 1][3])),
               res) +
           2;
  else if (m % 2 == 0 && n != 1) {
    res = add(
        add(add(dp[m - 2][0], dp[m - 2][1]), add(dp[m - 2][2], dp[m - 2][3])),
        fastexp(2, m / 2 - 1));
    if (m <= 2)
      res1 = res + 1;
    else
      res1 = res;
  } else
    res1 =
        add(add(dp[m - 2][0], dp[m - 2][1]), add(dp[m - 2][2], dp[m - 2][3]));
  return res1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  if (m == 1 && n == 1) {
    cout << 2;
    return 0;
  }
  if (m == 1) swap(n, m);
  if (n == 1)
    cout << solve(n, m);
  else
    cout << sub(add(solve(1, n), solve(1, m)), 2);
}
