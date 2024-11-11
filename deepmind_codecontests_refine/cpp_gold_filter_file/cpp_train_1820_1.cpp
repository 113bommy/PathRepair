#include <bits/stdc++.h>
using namespace std;
const long long delta = (long long)1e9 + 7;
int n, m, nn = 101;
const int MX = 104;
long long ep[MX][MX], dp[MX], cnt[MX];
long long tmp[MX][MX];
void mull(long long a[MX][MX], long long b[MX][MX]) {
  for (int i = 1; i <= nn; i++)
    for (int j = 1; j <= nn; j++) {
      tmp[i][j] = 0;
      for (int k = 1; k <= nn; k++)
        tmp[i][j] = (tmp[i][j] + b[i][k] * a[k][j]) % delta;
    }
  for (int i = 1; i <= nn; i++)
    for (int j = 1; j <= nn; j++) b[i][j] = tmp[i][j];
}
void mul(long long a[MX], long long b[MX][MX]) {
  long long tmp[MX];
  for (int i = 1; i <= nn; i++) {
    tmp[i] = 0;
    for (int j = 1; j <= nn; j++) {
      tmp[i] = (tmp[i] + dp[j] * ep[j][i]) % delta;
    }
  }
  for (int i = 1; i <= nn; i++) dp[i] = tmp[i];
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    cnt[x]++;
  }
  dp[0] = 1;
  for (int i = 1; i <= 100; i++)
    for (int j = 1; j <= 100; j++)
      if (i - j >= 0) dp[i] = (dp[i] + dp[i - j] * cnt[j]) % delta;
  for (int i = 1; i <= 100; i++) {
    dp[101] = (dp[101] + dp[i]) % delta;
  }
  dp[101]++;
  for (int i = 1; i <= nn; i++) ep[i + 1][i] = 1;
  ep[nn][nn - 1] = 0;
  ep[nn][nn] = 1;
  int j = 1;
  for (int i = 100; i >= 1; i--) {
    ep[j][nn] = cnt[i];
    ep[j][nn - 1] = cnt[i];
    j++;
  }
  if (m <= 100) {
    long long ans = 0;
    for (int i = 0; i <= m; i++) {
      ans = (ans + dp[i]) % delta;
    }
    cout << ans << endl;
    exit(0);
  }
  m -= 100;
  while (m) {
    if (m % 2 == 1) {
      mul(dp, ep);
    }
    mull(ep, ep);
    m >>= 1;
  }
  cout << dp[101] << endl;
  return 0;
}
