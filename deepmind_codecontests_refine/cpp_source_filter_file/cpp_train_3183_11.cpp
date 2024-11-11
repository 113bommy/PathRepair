#include <bits/stdc++.h>
using namespace std;
const int nMax = 1004;
const int maxVal = 9;
const int maxConf = 1 << 8;
int a[nMax], n;
int freq[maxVal];
int Next[maxVal][nMax][nMax];
int dp[nMax][maxConf];
int Solve(const int maxLength) {
  int ans = 0;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j < maxConf; ++j) dp[i][j] = -(1 << 29);
  dp[0][0] = 0;
  for (int i = 0; i <= n; ++i) {
    for (int val = 1; val <= 8; ++val) {
      for (int length = maxLength - 1; length <= maxLength; ++length) {
        int pos = Next[val][i + 1][length];
        if (pos != 0) {
          for (int j = 0; j < maxConf; ++j) {
            if (((1 << (val - 1)) & j) != 0) continue;
            dp[pos][j | (1 << (val - 1))] =
                max(dp[pos][j | (1 << (val - 1))], dp[i][j] + length);
          }
        }
      }
    }
    ans = max(ans, dp[i][maxConf - 1]);
  }
  return ans;
}
int main() {
  int sol = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (freq[a[i]] == 0) sol++;
    freq[a[i]] = 1;
  }
  for (int val = 1; val <= 8; ++val) {
    for (int i = 1; i <= n; ++i) {
      int steps = 0;
      for (int j = i; j <= n; ++j) {
        if (a[j] == val) {
          steps++;
          Next[val][i][steps] = j;
        }
      }
    }
  }
  for (int i = 2; i <= 2; ++i) {
    sol = max(sol, Solve(i));
  }
  cout << sol;
  return 0;
}
