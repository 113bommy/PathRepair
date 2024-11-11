#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int M = 1e2 + 2;
const int P = 1e9 + 7;
LL dp[M][2][M][M];
int c[M][M];
int n, m, k;
void make_cmod() {
  int i, j;
  for (i = 0; i < M; i++) c[i][0] = 1;
  for (i = 1; i < M; i++)
    for (j = 1; j <= i; j++) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
      if (c[i][j] > 100) c[i][j] = 200;
    }
}
void clear(int id) {
  int i, p, q;
  for (i = 0; i <= n; i++)
    for (p = 0; p <= n; p++)
      for (q = 1; q <= k; q++) dp[i][id][p][q] = 0;
}
int main() {
  make_cmod();
  int i, j, p, q, t, mn, ks, flag = 0;
  bool first = true;
  LL res = 0, tmp = 0;
  cin >> n >> m >> k;
  n++;
  mn = min(m, n);
  for (i = 1; i <= n; i++) dp[i][1][i - 1][1] = 1;
  for (j = 2; j <= mn; j++, flag ^= 1) {
    clear(flag);
    for (i = 0; i <= n; i++)
      for (p = 1; p < n; p++)
        for (q = 1; q <= k; q++) {
          if (dp[i][flag ^ 1][p][q]) {
            for (t = p; t <= n - i; t++) {
              ks = q * c[t - 1][p - 1];
              if (ks > k) continue;
              dp[i + t][flag][t - p][ks] =
                  (dp[i + t][flag][t - p][ks] + dp[i][flag ^ 1][p][q]) % P;
            }
          }
        }
    tmp = 0;
    for (i = 2; i <= n; i++)
      for (q = 1; q <= k; q++) tmp = (tmp + dp[i][flag][0][q]) % P;
    res = (res + tmp * (m - j + 1) % P) % P;
  }
  cout << res;
}
