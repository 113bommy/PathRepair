#include <bits/stdc++.h>
using namespace std;
const int N = 12, p = 998244353;
int n, k, m, f1[33], f2[33], f3[33], f4[33], dp[33][N][N][N][N][2][2];
struct node {
  int x, y;
} e[114], g[514];
inline int inc(int a, int b) {
  if (a + b >= p) return a + b - p;
  return a + b;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> e[i].x >> e[i].y;
  for (int i = 1; i <= n; i++) {
    k++, g[k] = e[i];
  }
  dp[0][0][0][0][0][0][0] = 1;
  for (int i = 0; i < (1 << k); i++)
    for (int x = 0; x < k; x++) {
      if ((i & (1 << x)) == 0) continue;
      int a = g[x + 1].x, b = g[x + 1].y;
      if (a > 0)
        f1[i] += abs(a);
      else
        f2[i] += abs(a);
      if (b > 0)
        f3[i] += abs(b);
      else
        f4[i] += abs(b);
    }
  for (int i = 1; i <= 32; i++) {
    for (int a = 0; a <= 10; a++)
      for (int b = 0; b <= 10; b++)
        for (int c = 0; c <= 10; c++)
          for (int d = 0; d <= 10; d++)
            for (int e = 0; e <= 1; e++)
              for (int f = 0; f <= 1; f++)
                for (int x = 0; x < (1 << k); x++) {
                  if (((a + f1[x]) & 1) ^ ((b + f2[x]) & 1)) continue;
                  if (((c + f3[x]) & 1) ^ ((d + f4[x]) & 1)) continue;
                  int z1 = 0, z2 = 0;
                  if (((a + f1[x]) & 1) > (m & 1)) z1 = 1;
                  if (((a + f1[x]) & 1) == (m & 1) && e == 1) z1 = 1;
                  if (((c + f3[x]) & 1) > (m & 1)) z2 = 1;
                  if (((c + f3[x]) & 1) == (m & 1) && f == 1) z2 = 1;
                  dp[i][(a + f1[x]) >> 1][(b + f2[x]) >> 1][(c + f3[x]) >> 1]
                    [(d + f4[x]) >> 1][z1][z2] =
                        inc(dp[i][(a + f1[x]) >> 1][(b + f2[x]) >> 1]
                              [(c + f3[x]) >> 1][(d + f4[x]) >> 1][z1][z2],
                            dp[i - 1][a][b][c][d][e][f]);
                }
    m = m >> 1;
  }
  cout << (dp[32][0][0][0][0][0][0] - 1 + p) % p << endl;
}
