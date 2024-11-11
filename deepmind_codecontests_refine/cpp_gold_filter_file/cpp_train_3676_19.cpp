#include <bits/stdc++.h>
using namespace std;
int N, T;
long long int dps[24][14][9];
long long int dp(int n, int t, int h) {
  long long int s = 0;
  if (dps[n][t][h] != -1) return dps[n][t][h];
  if (n == N && t == T) {
    dps[n][t][h] = 1;
    return 1;
  } else if (n == N) {
    dps[n][t][h] = 0;
    return 0;
  } else if (t == T + 1) {
    dps[n][t][h] = 0;
    return 0;
  }
  if (t % 2) {
    for (int i = h + 1; i <= 4; i++) s += dp(n + 1, t + 1, i);
    for (int i = 1; i < h; i++) s += dp(n + 1, t, i);
  } else {
    for (int i = h + 1; i <= 4; i++) s += dp(n + 1, t, i);
    for (int i = 1; i < h; i++) s += dp(n + 1, t + 1, i);
  }
  dps[n][t][h] = s;
  return s;
}
int main() {
  long long int s = 0;
  scanf("%d %d", &N, &T);
  for (int i = 0; i < 24; i++)
    for (int j = 0; j < 14; j++)
      for (int k = 0; k < 9; k++) dps[i][j][k] = -1;
  T = 2 * T - 1;
  for (int i = 1; i <= 4; i++) s += (i - 1) * dp(2, 0, i);
  printf("%lld\n", s);
  return 0;
}
