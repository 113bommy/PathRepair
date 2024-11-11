#include <bits/stdc++.h>
using namespace std;
int dp[2000 + 1][2000 + 1];
int sp[2000 + 1];
char str[2000 + 10];
char *trim_line(char *str) { return strtok(str, "\r\n"); }
int addmod(int x, int y, int p) {
  long long sum = x;
  sum += y;
  if (sum >= p) sum -= p;
  return (int)sum;
}
int submod(int x, int y, int p) {
  long long diff = x;
  diff -= y;
  if (diff < 0) diff += p;
  return (int)diff;
}
int mulmod(int x, int y, int p) {
  long long prod = x;
  prod = (prod * y) % p;
  return (int)prod;
}
int solve_problem() {
  char *p;
  int n, k;
  if (fgets(str, sizeof(str), stdin) == NULL) return 1;
  p = strtok(str, " ");
  n = atoi(p);
  p = strtok(NULL, " ");
  k = atoi(p);
  if (fgets(str, sizeof(str), stdin) == NULL) return 1;
  p = trim_line(str);
  sp[0] = dp[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= k; j++) {
      char ch = p[i - 1];
      int delta = mulmod(sp[j], ch - 'a', 1000000007);
      int step = n + 1 - i;
      dp[i][j] = addmod(dp[i][j], delta, 1000000007);
      for (int r = 0, q = j - step; r < i && q >= 0; r++, q -= step) {
        int delta = mulmod(dp[i - 1 - r][q], 'z' - ch, 1000000007);
        dp[i][j] = addmod(dp[i][j], delta, 1000000007);
      }
      sp[j] = addmod(sp[j], dp[i][j], 1000000007);
    }
  int result = 0;
  for (int i = 0; i <= n; i++) result = addmod(result, dp[i][k], 1000000007);
  printf("%d\n", result);
  return 0;
}
int main() {
  solve_problem();
  return 0;
}
