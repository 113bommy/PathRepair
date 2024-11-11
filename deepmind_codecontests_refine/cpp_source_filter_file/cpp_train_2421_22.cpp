#include <bits/stdc++.h>
const int N = 1e5 + 10;
int n, m, nq;
int sta[N][4];
int f[N][2], g[N][2];
void doDP(const int &ar, const int &rol, const int &col, int dp[][2]) {
  int *sid[2] = {sta[ar], sta[ar | 1]},
      *bond[2] = {sta[ar ^ 2], sta[(ar ^ 2) | 1]};
  for (int c = 0; c < 2; ++c) {
    dp[1][c] += (sid[0][1] != c) + (sid[1][1] != c);
    for (int j = 1; j <= col; ++j) dp[1][c] += (bond[0][j] != c);
  }
  for (int i = 2; i <= rol; ++i)
    for (int c = 0; c < 2; ++c)
      dp[i][c] = std::min(dp[i - 1][c], dp[i - 1][!c] + col) +
                 (sid[0][i] != c) + (sid[1][i] != c);
  for (int c = 0; c < 2; ++c)
    for (int j = 1; j <= col; ++j) dp[rol][c] += (bond[1][j] != c);
}
int main() {
  scanf("%d%d%d", &n, &m, &nq);
  for (int i = 0; i < 4; ++i) {
    static char inp[N];
    scanf("%s", inp + 1);
    for (int j = 1, lmt_j = i < 2 ? n : m; j <= lmt_j; ++j)
      sta[j][i] = inp[j] == 'R';
  }
  doDP(0, n, m, f), doDP(2, m, n, g);
  printf("%d\n",
         std::min(std::min(f[n][0], f[n][1]), std::min(g[m][0], g[m][1])));
  return 0;
}
