#include <bits/stdc++.h>
using namespace std;
long long dp[55][12];
bool valid(char s[], int len) {
  int i, x, y, sum;
  for ((i) = 0; (i) < (len - 1); (i)++) {
    sum = s[i] - '0' + s[i + 1] - '0';
    x = sum / 2 + '0';
    y = (sum + 1) / 2 + '0';
    if (s[i + 1] != x && s[i + 1] != y) return false;
  }
  return true;
}
void input() {
  int i, j, x, sum, len;
  char s[55];
  scanf("%s", &s);
  len = strlen(s);
  for ((i) = 0; (i) < (10); (i)++) dp[0][i] = 1;
  for ((i) = 0; (i) < (len - 1); (i)++) {
    x = s[i + 1] - '0';
    for ((j) = 0; (j) < (10); (j)++) {
      sum = x + j;
      dp[i + 1][sum / 2] += dp[i][j];
      if (sum % 2) dp[i + 1][(sum + 1) / 2] += dp[i][j];
    }
  }
  long long res = 0;
  for ((i) = 0; (i) < (10); (i)++) res += dp[len - 1][i];
  printf("%d", res - valid(s, len));
}
int main() {
  input();
  return 0;
}
