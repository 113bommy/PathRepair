#include <bits/stdc++.h>
using namespace std;
using INT = long long;
using VI = vector<int>;
using pii = pair<int, int>;
template <typename A, typename B>
void smin(A &a, const B &b) {
  if (a > b) a = b;
}
template <typename A, typename B>
void smax(A &a, const B &b) {
  if (a < b) a = b;
}
int power(int a, int b) {
  int ans = 1;
  for (; b; b >>= 1, a = (INT)a * a % 1000000009)
    if (b & 1) {
      ans = (INT)ans * a % 1000000009;
    }
  return ans;
}
int dp[1010][2][33][33][33];
void add(int &u, int first) {
  u += first;
  if (u >= 1000000009) u -= 1000000009;
}
int main() {
  int n, h;
  scanf("%d %d", &n, &h);
  if (h == 1) puts("4"), exit(0);
  dp[1][1][0][0][0] = 4;
  for (int i = 1; i < n; i++) {
    for (int j = 2; j--;) {
      for (int a = h; a--;) {
        int A = a ? (a + 1) % h : 0;
        for (int b = h; b--;) {
          int B = b ? (b + 1) % h : 0;
          for (int c = h; c--;) {
            int C = c ? (c + 1) % h : 0;
            add(dp[i + 1][j][A][B][C], dp[i][j][a][b][c]);
            add(dp[i + 1][a > 0 || i < h][j][B][C], dp[i][j][a][b][c]);
            add(dp[i + 1][b > 0 || i < h][A][j][C], dp[i][j][a][b][c]);
            add(dp[i + 1][c > 0 || i < h][A][C][j], dp[i][j][a][b][c]);
          }
        }
      }
    }
  }
  int ans = 0;
  for (int a = h; a--;) {
    for (int b = h; b--;) {
      for (int c = h; c--;) {
        add(ans, dp[n][1][a][b][c]);
        if (a || b || c) add(ans, dp[n][0][a][b][c]);
      }
    }
  }
  printf("%d", ans);
}
