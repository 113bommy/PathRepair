#include <bits/stdc++.h>
using namespace std;
const int SZ = 500 + 10;
const long long MOD = 998244353;
int n, m;
long long arr[SZ];
long long dp[SZ][SZ];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int r, ind, tl, tr;
  long long fir, sec;
  long long calc[4];
  for (int len = 1; len <= n; len++) {
    for (int l = 0; l <= (n - len); l++) {
      if (len == 1) {
        dp[l][l] = 1ll;
        continue;
      }
      r = l + len - 1;
      ind = l;
      for (int i = l; i <= r; i++) {
        if (arr[i] < arr[ind]) ind = i;
      }
      dp[l][r] = 0;
      fir = 0;
      sec = 0;
      for (tl = l; tl <= ind; tl++) {
        if (tl > (ind - 1))
          calc[0] = 1ll;
        else
          calc[0] = dp[tl][ind - 1];
        if (l > (tl - 1))
          calc[1] = 1ll;
        else
          calc[1] = dp[l][tl - 1];
        calc[0] *= calc[1];
        calc[0] %= MOD;
        fir += calc[0];
        fir %= MOD;
      }
      for (tr = ind; tr <= r; tr++) {
        if ((ind + 1) > tr)
          calc[2] = 1ll;
        else
          calc[2] = dp[ind + 1][tr];
        if ((tr + 1) > r)
          calc[3] = 1ll;
        else
          calc[3] = dp[tr + 1][r];
        calc[2] *= calc[3];
        calc[2] %= MOD;
        sec += calc[2];
        sec %= MOD;
      }
      dp[l][r] += fir * sec;
      dp[l][r] %= MOD;
    }
  }
  cout << dp[0][n - 1] << endl;
  return 0;
}
