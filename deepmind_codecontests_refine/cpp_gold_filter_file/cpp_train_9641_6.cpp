#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
const int maxn = 100000 + 10;
const int mod = 1e9 + 7;
char MAP[260][260];
int n, m;
int dp[2][(1 << 15)][2][3];
int main() {
  dp[0][0][0][0] = 1;
  int op = 0;
  scanf("%d%d", &n, &m);
  if (m <= n) {
    for (int i = 0; i < n; i++) {
      scanf("%s", MAP[i]);
    }
  } else {
    for (int i = 0; i < n; i++) {
      getchar();
      for (int j = 0; j < m; j++) {
        MAP[j][i] = getchar();
      }
    }
    swap(n, m);
  }
  for (int i = 0; i < n; i++) {
    int j;
    for (j = 0; j < m; j++) {
      int flag = (j != m - 1);
      int now = m - j - 1;
      int k;
      memset(dp[op ^ 1], 0, sizeof(dp[op ^ 1]));
      if (MAP[i][j] == '.') {
        for (k = 0; k < (1 << m); k++) {
          for (int m = 0; m < 2; m++) {
            for (int w = 0; w < 2; w++) {
              int st = (k >> now) & 1;
              int S = k | ((m | st) << now);
              st = (m | w | st) ^ 1;
              for (int h = 0; h < 2; h++) {
                dp[op ^ 1][S][(w | m) & flag][h + st] += dp[op][k][w][h];
                dp[op ^ 1][S][(w | m) & flag][h + st] %= mod;
              }
            }
          }
        }
        op ^= 1;
      } else {
        for (k = 0; k < (1 << m); k++) {
          for (int w = 0; w < 2; w++) {
            int st = (k >> now) & 1;
            int S = (k ^ (st << now));
            for (int h = 0; h < 2; h++) {
              dp[op ^ 1][S][0][h] += dp[op][k][w][h];
              dp[op ^ 1][S][0][h] %= mod;
            }
          }
        }
        op ^= 1;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < (1 << m); i++) {
    for (int j = 0; j < 2; j++) {
      ans += dp[op][i][0][j];
      ans %= mod;
    }
  }
  cout << ans << endl;
  return 0;
}
