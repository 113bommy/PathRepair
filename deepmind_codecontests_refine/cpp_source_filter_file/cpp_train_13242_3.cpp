#include <bits/stdc++.h>
const int mod = 998244353;
using namespace std;
string s;
int dp1[3000][3000], dp2[3000][3000];
void sol() {
  memset(dp2, 0, sizeof(dp2));
  memset(dp1, 0, sizeof(dp1));
  int n = s.size();
  dp1[0][0] = 1;
  dp2[n + 1][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (s[i - 1] == '(') {
        if (j) dp1[i][j] = (dp1[i][j] + dp1[i - 1][j - 1]) % mod;
      } else if (s[i - 1] == ')') {
        dp1[i][j] = (dp1[i][j] + dp1[i - 1][j]) % mod;
      } else {
        dp1[i][j] = (dp1[i][j] + dp1[i - 1][j]) % mod;
        if (j) {
          dp1[i][j] = (dp1[i][j] + dp1[i - 1][j - 1]) % mod;
        }
      }
    }
  }
  for (int i = n; i > 0; --i) {
    for (int j = 0; j <= n; ++j) {
      if (s[i - 1] == ')') {
        if (j) dp2[i][j] = (dp2[i][j] + dp2[i + 1][j - 1]) % mod;
      } else if (s[i] == '(') {
        dp2[i][j] = (dp2[i][j] + dp2[i + 1][j]) % mod;
      } else {
        dp2[i][j] = (dp2[i][j] + dp2[i + 1][j]) % mod;
        if (j) dp2[i][j] = (dp2[i][j] + dp2[i + 1][j - 1]) % mod;
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      ans = (ans + ((1ll * j * dp1[i][j]) % mod) * dp2[i + 1][j]) % mod;
    }
  }
  cout << ans << endl;
}
int main() {
  cin >> s;
  sol();
}
