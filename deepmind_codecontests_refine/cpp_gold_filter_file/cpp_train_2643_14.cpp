#include <bits/stdc++.h>
using namespace std;
const int P = 1000 * 1000 * 1000 + 7, N = 50 + 5;
long long n, dp[4 * N + 1][N][N], cnt[2], c[N][N], k, ans = 1;
void com() {
  for (int i = 0; i < N; i++) c[i][0] = 1;
  for (int i = 1; i < N; i++)
    for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % P;
}
void updEve(int s, int x, int y) {
  for (int i = 0; i <= cnt[0] - x; i++)
    for (int j = 0; j <= cnt[1] - y; j++)
      if (i + j != 0 && i * 50 + j * 100 <= k) {
        dp[s + 1][x + i][y + j] +=
            dp[s][x][y] * c[cnt[0] - x][i] % P * c[cnt[1] - y][j] % P;
        dp[s + 1][x + i][y + j] %= P;
      }
}
void updOdd(int s, int x, int y) {
  for (int i = 0; i <= x; i++)
    for (int j = 0; j <= y; j++)
      if (i + j != 0 && i * 50 + j * 100 <= k) {
        dp[s + 1][x - i][y - j] += dp[s][x][y] * c[x][i] % P * c[y][j] % P;
        dp[s + 1][x - i][y - j] %= P;
      }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie();
  cin >> n >> k;
  for (int i = 0, a; i < n; i++) cin >> a, cnt[a / 50 - 1]++;
  dp[0][cnt[0]][cnt[1]] = 1, com();
  for (int i = 0; i < 4 * N; i++)
    for (int j = 0; j <= cnt[0]; j++)
      for (int l = 0; l <= cnt[1]; l++)
        i & 1 ? updEve(i, j, l) : updOdd(i, j, l);
  for (; ans < 4 * N && dp[ans][0][0] == 0; ans += 2)
    ;
  ans < 4 * N ? cout << ans << endl << dp[ans][0][0] : cout << -1 << endl << 0;
}
