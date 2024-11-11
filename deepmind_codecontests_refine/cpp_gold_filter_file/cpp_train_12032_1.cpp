#include <bits/stdc++.h>
using namespace std;
long long C[20][20], dp[16][20], k;
int num[16], t;
long long solve(int len) {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i <= num[0]; i++) dp[0][i] = C[len][i];
  for (int i = 1; i < 16; i++)
    for (int l = 0; l <= len; l++)
      for (int j = 0; j <= min(num[i], l); j++)
        dp[i][l] += dp[i - 1][l - j] * C[len - l + j][j];
  return dp[15][len];
}
int main() {
  for (int i = 0; i < 20; i++) C[i][0] = 1;
  for (int i = 1; i < 20; i++)
    for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  cin >> k >> t;
  for (int i = 0; i < 16; i++) num[i] = t;
  int len = 1;
  for (;; len++) {
    long long tmp = 0;
    if (len == 1)
      tmp = 15;
    else {
      for (int j = 1; j < 16; j++) {
        num[j]--;
        tmp += solve(len - 1);
        num[j]++;
      }
    }
    if (k > tmp)
      k -= tmp;
    else
      break;
  }
  for (int i = len; i > 0; i--) {
    if (i == 1) {
      for (int j = 0; j < 16; j++) {
        if (j == 0 && len == 1) continue;
        if (num[j] != 0) k--;
        if (k == 0) {
          if (j < 10)
            cout << j;
          else
            cout << (char)(j + 'a' - 10);
          break;
        }
      }
      break;
    }
    for (int j = 0; j < 16; j++) {
      if (i == len && j == 0) continue;
      num[j]--;
      long long tmp = solve(i - 1);
      if (k > tmp)
        k -= tmp;
      else {
        if (j < 10)
          cout << j;
        else
          cout << (char)(j + 'a' - 10);
        break;
      }
      num[j]++;
    }
  }
  return 0;
}
