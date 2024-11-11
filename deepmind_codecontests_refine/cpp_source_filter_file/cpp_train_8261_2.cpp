#include <bits/stdc++.h>
const int mod = 1000000007;
int n, h, dp[2][32][32][32][32], now, last = 1, ans, a, b, c, d, v;
void upd(int A, int B, int C, int D) {
  ++A;
  ++B;
  ++C;
  ++D;
  if (D > h + 1) D = h + 1;
  if (C > h + 1) C = h + 1;
  if (B > h + 1) B = h + 1;
  if (A > h + 1) A = h + 1;
  dp[now][A][B][C][D] = (dp[now][A][B][C][D] + v) % mod;
}
int main() {
  scanf("%d%d", &n, &h);
  dp[0][1][1][1][1] = 1;
  while (n--) {
    last = now;
    now ^= 1;
    for (a = 1; a <= h; a++)
      for (b = a; b <= h + 1; b++)
        for (c = b; c <= h + 1; c++)
          for (d = c; d <= h + 1; d++) dp[now][a][b][c][d] = 0;
    for (a = 1; a <= h; a++)
      for (b = a; b <= h + 1; b++)
        for (c = b; c <= h + 1; c++)
          for (d = c; d <= h + 1; d++)
            if (dp[last][a][b][c][d]) {
              v = dp[last][a][b][c][d];
              if (a <= h)
                upd(0, b, c, d);
              else
                upd(a, b, c, d);
              if (b <= h)
                upd(0, a, c, d);
              else
                upd(a, b, c, d);
              if (c <= h)
                upd(0, a, b, d);
              else
                upd(a, b, c, d);
              if (d <= h)
                upd(0, a, b, c);
              else
                upd(a, b, c, d);
            }
  }
  for (a = 1; a <= h; a++)
    for (b = a; b <= h + 1; b++)
      for (c = b; c <= h + 1; c++)
        for (d = c; d <= h + 1; d++)
          if (dp[now][a][b][c][d]) ans = (ans + dp[now][a][b][c][d]) % mod;
  printf("%d\n", ans);
}
