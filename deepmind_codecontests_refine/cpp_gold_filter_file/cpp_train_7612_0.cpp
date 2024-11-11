#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int MAX = 2e5 + 1;
long long dp[3][MAX];
const int MOD = 1e9 + 7;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  dp[0][0] = 1;
  long long all[3] = {0};
  long long col1 = (3 - (b % 3)) % 3;
  long long col2 = c % 3;
  long long nb = b + col1;
  long long nc = c - col2;
  long long colAll = (nc - nb) / 3;
  if (colAll >= 0) {
    all[2] = all[1] = all[0] = colAll;
    ++all[0];
    for (int i = b; i < nb; ++i) {
      ++all[i % 3];
    }
    for (int i = nc + 1; i <= c; ++i) {
      ++all[i % 3];
    }
  } else {
    for (int i = b; i <= c; ++i) {
      ++all[i % 3];
    }
  }
  int num = 0;
  for (int i = 1; i <= a; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        num = (j + 3 - k) % 3;
        dp[j][i] = (dp[j][i] + all[num] * dp[k][i - 1]) % MOD;
      }
    }
  }
  cout << dp[0][a] << endl;
}
int main() {
  int af = 1;
  while (af-- > 0) {
    solve();
  }
  return 0;
}
