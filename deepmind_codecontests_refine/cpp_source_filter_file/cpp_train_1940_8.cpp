#include <bits/stdc++.h>
using namespace std;
const int md = 1e9 + 7;
inline int add(int a, int b) {
  a += b;
  if (a >= md) a -= md;
  return a;
}
inline int mul(int a, int b) { return (int)((long long)a * b); }
const int N = 500;
bool seg[N + 1][N + 1];
int dp[N][N + 1][2];
int main() {
  int n;
  scanf("%d", &n);
  int v;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      scanf("%d", &v);
      seg[i][j] = v;
      if (!i) seg[n][j] = seg[i][j];
      if (!j) seg[i][n] = seg[i][j];
    }
  for (int i = 0; i < n; ++i) seg[n][i] = seg[0][i];
  for (int i = n - 1; i >= 0; --i) {
    dp[i][i + 1][0] = dp[i][i + 1][1] = 1;
    for (int j = i + 2; j <= n; ++j) {
      for (int k = i + 1; k < j; ++k) {
        if (seg[i][k]) {
          dp[i][j][1] = add(dp[i][j][1], mul(dp[i][k][1], dp[k][j][1]));
        }
        if (seg[k][j]) {
          dp[i][j][1] = add(dp[i][j][1], mul(dp[k][j][1], dp[i][k][0]));
          dp[i][j][0] = add(dp[i][j][0], mul(dp[k][j][1], dp[i][k][0]));
        }
      }
    }
  }
  printf("%d\n", dp[0][n][0]);
  return 0;
}
