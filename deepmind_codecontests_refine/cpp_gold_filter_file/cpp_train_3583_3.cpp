#include <bits/stdc++.h>
using namespace std;
int a[101];
int p[101];
int team[25];
int dp[(1 << 20)];
int count(int x) {
  int tot = 0;
  for (int i = 0; (1 << i) <= x; ++i)
    if (x & (1 << i)) ++tot;
  return tot;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  reverse(a, a + n);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    char s;
    cin >> s >> team[i];
    p[i] = s == 'p';
  }
  dp[0] = 0;
  for (int msk = 1; msk < (1 << n); ++msk) {
    dp[msk] = -(1 << 29);
    int omar = n - count(msk);
    for (int i = 0; i < n; ++i)
      if ((1 << i) & msk) {
        if (team[omar] == team[omar + 1])
          dp[msk] = max(dp[msk], dp[msk ^ (1 << i)] + a[i] * p[omar]);
        else
          dp[msk] = max(dp[msk], -dp[msk ^ (1 << i)] + a[i] * p[omar]);
      }
  }
  if (team[0] == 2) dp[(1 << n) - 1] *= -1;
  cout << dp[(1 << n) - 1] << endl;
}
