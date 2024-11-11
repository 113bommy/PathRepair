#include <bits/stdc++.h>
using namespace std;
int dp[1005][2005][4];
long long MOD = 998244353;
int add(int second_last, int last) {
  switch (second_last) {
    case 0:
      switch (last) {
        case 0:
          return 0;
        case 1:
          return 1;
        case 2:
          return 1;
        case 3:
          return 1;
      }
    case 1:
      switch (last) {
        case 0:
          return 0;
        case 1:
          return 0;
        case 2:
          return 2;
        case 3:
          return 0;
      }
    case 2:
      switch (last) {
        case 0:
          return 0;
        case 1:
          return 2;
        case 2:
          return 0;
        case 3:
          return 0;
      }
    case 3:
      switch (last) {
        case 0:
          return 1;
        case 1:
          return 1;
        case 2:
          return 1;
        case 3:
          return 0;
      }
  }
}
int main() {
  long long n, k;
  cin >> n >> k;
  dp[1][1][0] = 1, dp[1][2][1] = 1, dp[1][2][2] = 1, dp[1][1][3] = 1;
  for (int column = 2; column <= n; column++) {
    for (int compo = 1; compo <= k; compo++) {
      for (int second_last = 0; second_last <= 3; second_last++) {
        for (int last = 0; last <= 3; last++) {
          long long new_compo = compo + add(second_last, last);
          dp[column][new_compo][last] += dp[column - 1][compo][second_last];
          dp[column][new_compo][last] %= MOD;
        }
      }
    }
  }
  long long ans = 0;
  for (int last = 0; last <= 3; last++) {
    ans += dp[n][k][last];
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
