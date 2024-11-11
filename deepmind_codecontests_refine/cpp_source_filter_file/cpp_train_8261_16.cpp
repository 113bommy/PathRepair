#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
const int MAXN = 1e4 + 10;
const int MODULO = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int dp[2][2][32][32][32];
int n, h;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> h;
  dp[0][0][0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int now = i % 2;
    memset(dp[now], 0, sizeof(dp[now]));
    for (int a = 0; a <= 1; a++)
      for (int b = 0; b <= h; b++)
        for (int c = 0; c <= h; c++)
          for (int d = 0; d <= h; d++) {
            int val = dp[1 - now][a][b][c][d];
            (dp[now][a][min(b + 1, h)][min(c + 1, h)][min(d + 1, h)] += val) %=
                MODULO;
            (dp[now][b < h ? 0 : 1][min(c + 1, h)][min(d + 1, h)]
               [a < 1 ? 1 : h] += val) %= MODULO;
            (dp[now][c < h ? 0 : 1][min(d + 1, h)][a < 1 ? 1 : h]
               [min(b + 1, h)] += val) %= MODULO;
            (dp[now][d < h ? 0 : 1][a < 1 ? 1 : h][min(b + 1, h)]
               [min(c + 1, h)] += val) %= MODULO;
          }
  }
  int res = 0;
  for (int a = 0; a <= 1; a++)
    for (int b = 0; b <= h; b++)
      for (int c = 0; c <= h; c++)
        for (int d = 0; d <= h; d++)
          if (a != 1 || b != h || c != h || d != h)
            (res += dp[n % 2][a][b][c][d]) %= MODULO;
  cout << res;
  return 0;
}
