#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int choose[1001][1001];
void run() {
  int n;
  scanf("%d", &n);
  vector<int> x(n);
  for (int i = (0); i < (n); ++i) scanf("%d", &x[i]);
  vector<int> y(n);
  for (int i = (0); i < (n); ++i) scanf("%d", &y[i]);
  int xsum = 0;
  for (int i = (0); i < (n); ++i) xsum += x[i];
  int at = 0;
  vector<int> dp[2];
  dp[at] = vector<int>(xsum + 1, 0);
  dp[at][0] = 1;
  int xdone = 0;
  for (int i = (0); i < (n); ++i) {
    int to = 1 - at;
    dp[to] = vector<int>(xsum + 1, 0);
    int z1 = choose[xsum - xdone][x[i]];
    for (int j = (0); j <= (xsum); ++j)
      if (dp[at][j] > 0) {
        int z2 = dp[at][j];
        int have = j + x[i];
        for (int k = (0); k <= (min(have, y[i])); ++k) {
          int z3 = choose[have][k];
          dp[to][have - k] =
              (dp[to][have - k] + (long long)z1 * z2 % MOD * z3) % MOD;
        }
      }
    at = to;
    xdone += x[i];
  }
  printf("%d\n", dp[at][0]);
}
int main() {
  for (int i = (0); i <= (1000); ++i) {
    choose[i][0] = choose[i][i] = 1;
    for (int j = (1); j < (i); ++j) {
      choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
      if (choose[i][j] >= MOD) choose[i][j] -= MOD;
    }
  }
  run();
  return 0;
}
