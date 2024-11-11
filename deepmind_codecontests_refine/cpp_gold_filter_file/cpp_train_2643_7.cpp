#include <bits/stdc++.h>
using namespace std;
long long powm(long long base, long long exp, long long mod = 1000000007) {
  long long ans = 1;
  while (exp) {
    if (exp & 1) ans = (ans * base) % mod;
    exp >>= 1, base = (base * base) % mod;
  }
  return ans;
}
long long ctl(char x, char an = 'a') { return (long long)(x - an); }
char ltc(long long x, char an = 'a') { return (char)(x + an); }
long long dp[205][205][205];
long long cnt1, cnt2, n, maxm, x;
long long nCr[205][205];
int main() {
  nCr[0][0] = 1;
  for (long long i = 1; i < 205; i++) {
    nCr[i][0] = 1;
    for (long long j = 1; j < 205; j++) {
      nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]);
      if (nCr[i][j] >= 1000000007) nCr[i][j] -= 1000000007;
    }
  }
  cin >> n >> maxm;
  for (long long i = 1; i < n + 1; i++) {
    cin >> x;
    if (x == 50)
      cnt1++;
    else
      cnt2++;
  }
  dp[0][cnt1][cnt2] = 1;
  long long ans = 0;
  while (++ans < 205) {
    for (long long i = 0; i < cnt1 + 1; i++)
      for (long long j = 0; j < cnt2 + 1; j++)
        for (long long k = 0; k < i + 1; k++)
          for (long long l = 0; l < j + 1; l++) {
            long long weight = k * 50 + l * 100;
            if (weight > 0 and weight <= maxm) {
              dp[ans][cnt1 - i + k][cnt2 - j + l] +=
                  (dp[ans - 1][i][j] * (nCr[i][k] * nCr[j][l]) % 1000000007) %
                  1000000007;
              if (dp[ans][cnt1 - i + k][cnt2 - j + l] >= 1000000007)
                dp[ans][cnt1 - i + k][cnt2 - j + l] -= 1000000007;
            }
          }
    if ((ans & 1) && dp[ans][cnt1][cnt2]) {
      cout << ans << '\n' << dp[ans][cnt1][cnt2];
      return 0;
    }
  }
  cout << -1 << '\n' << 0;
  return 0;
}
