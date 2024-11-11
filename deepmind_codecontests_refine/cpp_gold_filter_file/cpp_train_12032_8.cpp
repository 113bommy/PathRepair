#include <bits/stdc++.h>
using namespace std;
int limit[20];
long long C[20][20], dp[20][20];
void out(int x) {
  if (x < 10)
    printf("%d", x);
  else
    printf("%c", x - 10 + 'a');
}
long long solve(int len, int flag) {
  if (len == 0 && flag != 0)
    return 1;
  else if (len == 0 && flag == 0)
    return 1;
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i <= len && i <= limit[0]; i++) dp[0][i] = C[len][i];
  for (int i = 1; i < 16; i++)
    for (int j = 0; j <= len; j++) {
      for (int k = 0; k <= j && k <= limit[i]; k++) {
        dp[i][j] += dp[i - 1][j - k] * C[len - j + k][k];
      }
    }
  return dp[15][len];
}
int res[20];
int main() {
  long long n, ans;
  int m;
  scanf("%lld%d", &n, &m);
  ans = n;
  for (int i = 0; i < 16; i++) limit[i] = m;
  for (int i = 0; i <= 15; i++) C[i][0] = 1;
  for (int i = 1; i <= 15; i++)
    for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  int pos = -1;
  for (int i = 0; i >= 0; i++) {
    long long tmp = 0;
    for (int j = 1; j < 16; j++) {
      limit[j]--;
      tmp += solve(i, j);
      limit[j]++;
      if (tmp >= ans) {
        pos = i;
        break;
      }
    }
    if (tmp >= ans)
      break;
    else
      ans -= tmp;
  }
  n = ans;
  for (int i = pos; i >= 0; i--) {
    for (int j = 0; j < 16; j++) {
      if (i == pos && j == 0) continue;
      if (limit[j] == 0) continue;
      limit[j]--;
      long long tmp = solve(i, j);
      limit[j]++;
      if (tmp < n) {
        n -= tmp;
      } else {
        res[i] = j;
        limit[j]--;
        break;
      }
    }
  }
  for (int i = pos; i >= 0; i--) {
    out(res[i]);
  }
  printf("\n");
}
