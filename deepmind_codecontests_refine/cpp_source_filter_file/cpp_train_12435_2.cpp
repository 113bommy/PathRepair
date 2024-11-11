#include <bits/stdc++.h>
using namespace std;
const long double E = 2.71828182845904523536;
const long double pi = acos(-1);
const double eps = 1e-9;
const long long mod = 1e9 + 7;
const long long inf = 1LL << 30;
int dp[55][10];
string s;
int sz;
long long sol() {
  long long ans = 0;
  long long a, b;
  for (int st = 0; st < 10; st++) dp[0][st] = 1;
  for (int i = 1; i < sz; i++) {
    for (int j = 0; j <= 9; j++) {
      if (dp[i - 1][j]) {
        if ((j + s[i]) & 1) {
          a = ceil(((j + (s[i] - '0')) * 1.0) / 2);
          b = floor(((j + (s[i] - '0')) * 1.0) / 2);
          dp[i][a] += dp[i - 1][j];
          dp[i][b] += dp[i - 1][j];
        } else {
          dp[i][(j + (s[i] - '0')) / 2] += dp[i - 1][j];
        }
      }
    }
  }
  for (int k = 0; k < 10; k++) {
    ans += dp[sz - 1][k];
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  sz = s.size();
  long long ans;
  ans = sol();
  bool flag = 1;
  int x;
  for (int i = 1; i < sz; i++) {
    x = abs((s[i] - '0') - (s[i - 1] - '0'));
    if (x > 1) flag = 0;
  }
  if (flag) ans--;
  cout << ans;
  return 0;
}
