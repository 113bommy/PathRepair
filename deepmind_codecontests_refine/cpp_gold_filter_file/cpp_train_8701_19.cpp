#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long MOD = 1e9 + 7;
const double PI = acos(-1.0);
int A[5010];
int B[5010];
int dp[2][55][55][500];
int ab(int x) {
  if (x < 0) return 0;
  return x;
}
int Cei(int a, int b) {
  if (a % b != 0) return a / b + 1;
  return a / b;
}
int main() {
  int n, p, k;
  memset(A, 0, sizeof A);
  memset(B, 0, sizeof B);
  memset(dp, -INF, sizeof dp);
  cin >> n >> p >> k;
  if (p > 2 * (k - 1 + n) / k) p = 2 * (n + k - 1) / k;
  int xx;
  int tt;
  cin >> tt;
  for (int i = 1; i <= tt; ++i) cin >> xx, A[xx] = 1;
  cin >> tt;
  for (int i = 1; i <= tt; ++i) cin >> xx, B[xx] = 1;
  int pre = 0, now = 1;
  dp[0][0][0][0] = 0;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int x = 0; x <= p; ++x) {
      for (int a = 0; a <= k - 1; ++a) {
        for (int b = 0; b <= k - 1; ++b) {
          dp[now][k - 1][ab(b - 1)][x + 1] =
              max(dp[now][k - 1][ab(b - 1)][x + 1],
                  dp[pre][a][b][x] + (A[i] || (b && B[i])));
          dp[now][ab(a - 1)][k - 1][x + 1] =
              max(dp[now][ab(a - 1)][k - 1][x + 1],
                  dp[pre][a][b][x] + ((A[i] && a) || (B[i])));
          dp[now][ab(a - 1)][ab(b - 1)][x] =
              max(dp[now][ab(a - 1)][ab(b - 1)][x],
                  dp[pre][a][b][x] + ((A[i] && a) || (B[i] && b)));
        }
      }
    }
    memset(dp[pre], -INF, sizeof dp[pre]);
    now ^= 1;
    pre ^= 1;
  }
  for (int i = 0; i <= p; ++i) {
    for (int a = 0; a <= k; ++a)
      for (int b = 0; b <= k; ++b) ans = max(ans, dp[pre][a][b][i]);
  }
  cout << ans << endl;
}
