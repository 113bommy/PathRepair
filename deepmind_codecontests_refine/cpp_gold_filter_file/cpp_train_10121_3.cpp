#include <bits/stdc++.h>
using namespace std;
const int S = 22, T = 9;
const int mod = 998244353;
int n, m, x[6], y[6], dp[31][S + 1][S + 1][T + 1][T + 1];
void inc(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
  int totx = 0, toty = 0;
  for (int i = 1; i <= n; ++i)
    if (x[i] > 0) totx++;
  if (totx > n / 2)
    for (int i = 1; i <= n; ++i) x[i] = -x[i];
  for (int i = 1; i <= n; ++i)
    if (y[i] > 0) toty++;
  if (toty > n / 2)
    for (int i = 1; i <= n; ++i) y[i] = -y[i];
  totx = toty = 0;
  for (int i = 1; i <= n; ++i)
    if (x[i] > 0) totx++;
  for (int i = 1; i <= n; ++i)
    if (y[i] > 0) toty++;
  int bx = totx * 4 + 1, by = toty * 4 + 1;
  dp[30][bx][by][0][0] = 1;
  for (int i = 29; i >= 0; --i) {
    for (int i1 = 0 - bx; i1 <= S - bx; ++i1)
      for (int i2 = 0 - by; i2 <= S - by; ++i2)
        for (int i3 = 0; i3 <= T; ++i3)
          for (int i4 = 0; i4 <= T; ++i4)
            if (dp[i + 1][i1 + bx][i2 + by][i3][i4])
              for (int J = 0; J <= (1 << n) - 1; ++J) {
                int I1 = i1 << 1, I2 = i2 << 1, I3 = i3 << 1 | (m >> i & 1),
                    I4 = i4 << 1 | (m >> i & 1);
                for (int j = 1; j <= n; ++j)
                  if (J >> j - 1 & 1) {
                    I1 += x[j];
                    I2 += y[j];
                    if (x[j] > 0) I3 -= x[j];
                    if (y[j] > 0) I4 -= y[j];
                  }
                I1 += bx;
                I2 += by;
                I3 = min(I3, T);
                I4 = min(I4, T);
                if (I1 >= 0 && I1 <= S && I2 >= 0 && I2 <= S && I3 >= 0 &&
                    I4 >= 0)
                  inc(dp[i][I1][I2][I3][I4],
                      dp[i + 1][i1 + bx][i2 + by][i3][i4]);
              }
  }
  int ans = 0;
  for (int i = 0; i <= T; ++i)
    for (int j = 0; j <= T; ++j) inc(ans, dp[0][bx][by][i][j]);
  cout << (ans + mod - 1) % mod << endl;
}
