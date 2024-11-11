#include <bits/stdc++.h>
using namespace std;
void opt() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long dp[210][100][100];
long long c[100][100];
long long const mod = 1000000007;
int main() {
  opt();
  c[0][0] = 1;
  for (int i = 1; i < 100; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
  }
  int n, k;
  cin >> n >> k;
  int sum0 = 0, sum1 = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 50)
      sum0++;
    else
      sum1++;
  }
  dp[0][sum0][sum1] = 1;
  for (int x = 0; x <= 200; x++) {
    for (int i = sum0; i >= 0; i--)
      for (int j = sum1; j >= 0; j--) {
        for (int kk = 0; kk <= i; kk++)
          for (int kkk = 0; kkk <= j; kkk++) {
            if (kk == 0 && kkk == 0) continue;
            if ((long long)kk * 50 + kkk * 100 > k) continue;
            if (kk + kkk * 2 > k) continue;
            dp[x + 1][sum0 - i + kk][sum1 - j + kkk] +=
                dp[x][i][j] * (c[i][kk] % mod) * (c[j][kkk] % mod) % mod;
            dp[x + 1][sum0 - i + kk][sum1 - j + kkk] %= mod;
          }
      }
    if (!(x & 1) && dp[x + 1][sum0][sum1]) {
      cout << x + 1 << endl << dp[x + 1][sum0][sum1] << endl;
      return 0;
    }
  }
  cout << -1 << endl << 0;
}
