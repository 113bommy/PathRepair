#include <bits/stdc++.h>
using namespace std;
const int N = 50 + 10;
const int P = (int)1e9 + 7;
int n, a[N];
int dp[2][N][N][N][N];
void Update(int &a, long long v) { a = (a + v) % P; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  int cur = 1, nxt = 0;
  dp[0][a[1] == 2][a[1] == 3][a[2] == 2][a[2] == 3] = 1;
  for (int i = 2; i <= n - 1; ++i) {
    cur ^= 1;
    nxt ^= 1;
    memset(dp[nxt], 0, sizeof dp[nxt]);
    for (int x1 = 0; x1 <= i; ++x1)
      for (int x2 = 0; x2 <= i - x1; ++x2)
        for (int y1 = 0; y1 <= i - x1 - x2; ++y1)
          for (int y2 = 0; y2 <= i - x1 - x2 - y1; ++y2) {
            long long val = dp[cur][x1][x2][y1][y2];
            if (val == 0) continue;
            if (x1 == 0 && x2 == 0) {
              if (y1 > 0)
                Update(dp[nxt][y1 - 1][y2][a[i + 1] == 2][a[i + 1] == 3],
                       val * y1);
              if (y2 > 0)
                Update(dp[nxt][y1 + 1][y2 - 1][a[i + 1] == 2][a[i + 1] == 3],
                       val * y2);
            }
            if (x1 > 0) {
              if (a[i + 1] == 2) {
                Update(dp[nxt][x1 - 1][x2][y1 + 1][y2], val * x1);
                if (y1 > 0)
                  Update(dp[nxt][x1 - 1][x2][y1 - 1][y2], val * x1 * y1);
                if (y2 > 0)
                  Update(dp[nxt][x1 - 1][x2][y1 + 1][y2 - 1], val * x1 * y2);
              } else {
                Update(dp[nxt][x1 - 1][x2][y1][y2 + 1], val * x1);
                if (y1 > 1)
                  Update(dp[nxt][x1 - 1][x2][y1 - 2][y2],
                         val * x1 * y1 * (y1 - 1) / 2);
                if (y2 > 1)
                  Update(dp[nxt][x1 - 1][x2][y1 + 2][y2 - 2],
                         val * x1 * y2 * (y2 - 1) / 2);
                if (y1 > 0 && y2 > 0)
                  Update(dp[nxt][x1 - 1][x2][y1][y2 - 1], val * x1 * y1 * y2);
                if (y1 > 0) Update(dp[nxt][x1 - 1][x2][y1][y2], val * x1 * y1);
                if (y2 > 0)
                  Update(dp[nxt][x1 - 1][x2][y1 + 2][y2 - 1], val * x1 * y2);
              }
            }
            if (x2 > 0) {
              if (a[i + 1] == 2) {
                Update(dp[nxt][x1 + 1][x2 - 1][y1 + 1][y2], val * x2);
                if (y1 > 0)
                  Update(dp[nxt][x1 + 1][x2 - 1][y1 - 1][y2], val * x2 * y1);
                if (y2 > 0)
                  Update(dp[nxt][x1 + 1][x2 - 1][y1 + 1][y2 - 1],
                         val * x2 * y2);
              } else {
                Update(dp[nxt][x1 + 1][x2 - 1][y1][y2 + 1], val * x2);
                if (y1 > 1)
                  Update(dp[nxt][x1 + 1][x2 - 1][y1 - 2][y2],
                         val * x1 * y1 * (y1 - 1) / 2);
                if (y2 > 1)
                  Update(dp[nxt][x1 + 1][x2 - 1][y1 + 2][y2 - 2],
                         val * x1 * y2 * (y2 - 1) / 2);
                if (y1 > 0 && y2 > 0)
                  Update(dp[nxt][x1 + 1][x2 - 1][y1][y2 - 1],
                         val * x2 * y1 * y2);
                if (y1 > 0)
                  Update(dp[nxt][x1 + 1][x2 - 1][y1][y2], val * x2 * y1);
                if (y2 > 0)
                  Update(dp[nxt][x1 + 1][x2 - 1][y1 + 2][y2 - 1],
                         val * x2 * y2);
              }
            }
          }
  }
  printf("%d", dp[nxt][0][0][0][0]);
  return 0;
}
