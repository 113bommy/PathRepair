#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  long long n, l, r;
  cin >> n >> l >> r;
  long long i, j, k;
  long long a = 0, b = 0, c = 0;
  long long x, y;
  if (r - l < 10) {
    for (i = l; i <= r; i++) {
      if (i % 3 == 0)
        a++;
      else if (i % 3 == 1)
        b++;
      else
        c++;
    }
  } else {
    if (l % 3 == 0)
      x = l;
    else
      x = l + 3 - l % 3;
    if (r % 3 == 0)
      y = r;
    else
      y = r - r % 3;
    a = (y - x) / 3 + 1;
    b = a - 1;
    c = b;
    for (i = l; i < x; i++) {
      if (i % 3 == 0)
        a++;
      else if (i % 3 == 1)
        b++;
      else
        c++;
    }
    for (i = y + 1; i <= r; i++) {
      if (i % 3 == 0)
        a++;
      else if (i % 3 == 1)
        b++;
      else
        c++;
    }
  }
  long long z;
  x = a;
  y = b;
  z = c;
  long long dp[n + 1][3];
  dp[0][0] = a % 1000000007;
  dp[0][1] = b % 1000000007;
  dp[0][2] = c % 1000000007;
  for (i = 1; i < n; i++) {
    dp[i][0] =
        ((dp[i - 1][0] * a) % 1000000007 + (dp[i - 1][1] * c) % 1000000007 +
         (dp[i - 1][2] * b) % 1000000007) %
        1000000007;
    dp[i][1] =
        ((dp[i - 1][0] * b) % 1000000007 + (dp[i - 1][1] * a) % 1000000007 +
         (dp[i - 1][2] * c) % 1000000007) %
        1000000007;
    dp[i][2] =
        ((dp[i - 1][0] * c) % 1000000007 + (dp[i - 1][1] * b) % 1000000007 +
         (dp[i - 1][2] * a) % 1000000007) %
        1000000007;
  }
  cout << dp[n - 1][0];
  return 0;
}
