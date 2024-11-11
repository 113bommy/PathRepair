#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long n, k;
long long a[55];
long long c[55][55];
long long dp[105][55][55];
long long num_50, num_100;
long long old, now;
bool ok;
int main() {
  for (int i = 0; i < 50; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
  }
  scanf("%lld%lld", &n, &k);
  k /= 50;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    if (a[i] == 50)
      num_50++;
    else
      num_100++;
  }
  old = 1;
  now = 0;
  dp[0][num_50][num_100] = 1;
  for (int l = 0; l < 2 * n; l++) {
    swap(now, old);
    memset(dp[now], 0, sizeof(dp[now]));
    for (int i = 0; i <= num_50; i++) {
      for (int j = 0; j <= num_100; j++) {
        if (i + j * 2 && (i + j * 2) <= k) {
          for (int x = i; x <= num_50; x++) {
            for (int y = j; y <= num_100; y++) {
              dp[now][num_50 - x + i][num_100 - y + j] +=
                  dp[old][x][y] * c[x][i] % MOD * c[y][j] % MOD;
            }
          }
        }
      }
    }
    if (dp[now][num_50][num_100]) {
      printf("%lld\n", l * 2 + 1);
      printf("%lld\n", dp[now][num_50][num_100] % MOD);
      ok = 1;
      break;
    }
    swap(now, old);
    memset(dp[now], 0, sizeof(dp[now]));
    for (int i = 0; i <= num_50; i++) {
      for (int j = 0; j <= num_100; j++) {
        if (i + j * 2 && (i + j * 2) <= k) {
          for (int x = i; x <= num_50; x++) {
            for (int y = j; y <= num_100; y++) {
              dp[now][num_50 - x + i][num_100 - y + j] +=
                  dp[old][x][y] * c[x][i] % MOD * c[y][j] % MOD;
            }
          }
        }
      }
    }
  }
  if (ok == 0) printf("-1\n0");
  return 0;
}
