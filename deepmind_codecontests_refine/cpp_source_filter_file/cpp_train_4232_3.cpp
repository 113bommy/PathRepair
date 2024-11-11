#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void add(int& a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}
const int nmax = 5050;
int dp[nmax][2];
int nx[nmax][2];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  dp[0][1] = 1;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    memset(nx, 0, sizeof(nx));
    if (s == "s") {
      int sum = 0;
      for (int j = nmax - 1; j >= 0; --j) {
        sum += dp[j][1];
        nx[j][1] = sum;
      }
      for (int j = 0; j < nmax; ++j) {
        if (j + 1 < nmax) {
          add(nx[j + 1][1], dp[j][0]);
        }
      }
    } else {
      int sum = 0;
      for (int j = nmax - 1; j >= 0; --j) {
        add(sum, dp[j][1]);
        nx[j][0] = sum;
      }
      for (int j = 0; j < nmax; ++j) {
        if (j + 1 < nmax) {
          add(nx[j + 1][0], dp[j][0]);
        }
      }
    }
    memcpy(dp, nx, sizeof(dp));
  }
  int ans = 0;
  for (int j = 0; j < nmax; ++j) {
    add(ans, dp[j][1]);
  }
  cout << ans << "\n";
}
