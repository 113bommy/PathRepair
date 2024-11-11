#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e3 + 5;
int visx[N], visy[N], n;
double dp[N][N];
bool in(int x, int y) { return 1 <= x && x <= n && 1 <= y && y <= n; }
double solve(int i, int j) {
  if (i == n && j == n) return dp[i][j] = 0;
  if (!in(i, j)) return dp[i][j] = 0;
  if (dp[i][j] != -1) return dp[i][j];
  return dp[i][j] = (solve(i + 1, j) * (j * n - i * j) +
                     solve(i, j + 1) * (i * n - i * j) +
                     solve(i + 1, j + 1) * (n - i) * (n - j) + n * n) /
                    (1.0 * n * n - i * j);
}
int main() {
  int k;
  cin >> n >> k;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dp[i][j] = -1;
    }
  }
  int i = 0, j = 0;
  for (int _ = 1; _ <= k; _++) {
    int x, y;
    cin >> x >> y;
    if (!visx[x]) {
      i++;
    }
    if (!visy[y]) {
      j++;
    }
    visx[x] = visy[y] = 1;
  }
  printf("%.5lf", solve(i, j));
}
