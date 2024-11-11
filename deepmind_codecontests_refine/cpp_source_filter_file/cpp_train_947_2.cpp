#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXN = 100000;
const int MAXV = 200;
int dp[MAXN + 5][MAXV + 5][3];
int prefixUp[MAXV + 5][3], prefixDown[MAXV + 5][3];
bool valid(vector<int> &a, int i, int val) {
  if (a[i] == -1)
    return true;
  else
    return a[i] == val;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  memset(dp, 0, sizeof(dp));
  for (int curr = 1; curr <= 200; curr++)
    if (valid(a, 0, curr)) dp[0][curr][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int curr = 200; curr >= 1; curr--) {
      for (int t = 0; t < 3; t++) {
        prefixUp[curr][t] =
            curr == 200
                ? 0
                : (prefixUp[curr + 1][t] + dp[i - 1][curr + 1][t]) % MOD;
      }
    }
    for (int curr = 1; curr <= 200; curr++) {
      for (int t = 0; t < 3; t++) {
        prefixDown[curr][t] =
            curr == 1
                ? 0
                : (prefixDown[curr - 1][t] + dp[i - 1][curr - 1][t]) % MOD;
      }
    }
    for (int curr = 1; curr <= 200; curr++)
      if (valid(a, i, curr)) {
        for (int t = 0; t <= 2; t++) {
          dp[i][curr][0] += prefixDown[curr][t];
          dp[i][curr][0] %= MOD;
        }
        for (int t = 1; t <= 2; t++) {
          dp[i][curr][2] += prefixUp[curr][t];
          dp[i][curr][2] %= MOD;
        }
        for (int t = 0; t <= 2; t++) {
          dp[i][curr][1] += dp[i - 1][curr][t];
          dp[i][curr][1] %= MOD;
        }
      }
  }
  int sol = 0;
  for (int curr = 1; curr <= 200; curr++)
    if (valid(a, n - 1, curr)) {
      sol += (dp[n - 1][curr][1] + dp[n - 1][curr][2]);
      sol %= MOD;
    }
  cout << sol << '\n';
}
