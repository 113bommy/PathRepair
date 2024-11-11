#include <bits/stdc++.h>
using namespace std;
bool vis[2000][2000][2];
int dp[2000][2000][2], lenB;
char A[2001], B[2001];
int calc(int i, int j, bool y) {
  if (!A[i]) return lenB - j;
  if (!B[j]) return 0;
  if (!vis[i][j][y]) {
    vis[i][j][y] = true;
    dp[i][j][y] = j ? lenB - j : 2048;
    if (!y) dp[i][j][y] = min(dp[i][j][y], 1 + calc(i, j + 1, y));
    if (!j) dp[i][j][y] = min(dp[i][j][y], calc(i + 1, j, y));
    dp[i][j][y] = min(dp[i][j][y], (A[i] != B[j]) + calc(i + 1, j + 1, true));
  }
  return dp[i][j][y];
}
int main() {
  gets(A);
  gets(B);
  lenB = strlen(B);
  printf("%d", calc(0, 0, false));
  return 0;
}
