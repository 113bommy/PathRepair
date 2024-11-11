#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInverse(long long a, long long p) { return power(a, p - 2, p); }
long long gcd(long long x, long long y) {
  if (x == 0 || y == 0) {
    return max(y, x);
  }
  return gcd(y % x, x);
}
double dp[104][104][104][4];
void solve() {
  long long r, s, p;
  cin >> r >> s >> p;
  ;
  for (long long i = 0; i <= r; i++) {
    for (long long j = 0; j <= s; j++) {
      for (long long k = 0; k <= p; k++) {
        for (long long safe = 0; safe < 3; safe++) {
          if (i == 0 && j == 0 & k == 0) continue;
          if (j == 0 && k == 0 && safe == 0) {
            dp[i][j][k][safe] = 1;
            continue;
          }
          if (i == 0 && k == 0 && safe == 1) {
            dp[i][j][k][safe] = 1;
            continue;
          }
          if (i == 0 && j == 0 && safe == 2) {
            dp[i][j][k][safe] = 1;
            continue;
          }
          double total = (i * j + j * k + k * i);
          if (total == 0) continue;
          if (j >= 1) {
            dp[i][j][k][safe] += ((i * j) / total) * (dp[i][j - 1][k][safe]);
          }
          if (k >= 1) {
            dp[i][j][k][safe] += ((k * j) / total) * (dp[i][j][k - 1][safe]);
          }
          if (i >= 1) {
            dp[i][j][k][safe] += ((k * i) / total) * (dp[i - 1][j][k][safe]);
          }
        }
      }
    }
  }
  for (long long i = 0; i < 3; i++)
    cout << setprecision(7) << dp[r][s][p][i] << ' ';
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  ;
  solve();
}
