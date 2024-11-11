#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:108777216")
using namespace std;
int const MAX_N = 64;
long long const LL_INF = 3000000000000000000LL;
int n, m;
int nnew[2][MAX_N][MAX_N];
long long dp_1[MAX_N][MAX_N], dp_2[MAX_N][MAX_N];
struct {
  int x1, y1, x2, y2;
} ms[MAX_N * MAX_N * 10];
long long calc(int XX = 0, int YY = 0) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) dp_1[i][j] = dp_2[i][j] = 0;
  dp_1[0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (i + 1 < n)
        if (!nnew[0][i][j]) {
          dp_1[i + 1][j] += dp_1[i][j];
          if (dp_1[i + 1][j] > LL_INF) dp_1[i + 1][j] = LL_INF;
        }
      if (j + 1 < m)
        if (!nnew[1][i][j]) {
          dp_1[i][j + 1] += dp_1[i][j];
          if (dp_1[i][j + 1] > LL_INF) dp_1[i][j + 1] = LL_INF;
        }
    }
  dp_2[n - 1][m - 1] = 1;
  for (int i = n - 1; i >= 0; i--)
    for (int j = m - 1; j >= 0; j--) {
      if (i - 1 >= 0)
        if (!nnew[0][i - 1][j]) {
          dp_2[i - 1][j] += dp_2[i][j];
          if (dp_2[i - 1][j] > LL_INF) dp_2[i - 1][j] = LL_INF;
        }
      if (j - 1 >= 0)
        if (!nnew[1][i][j - 1]) {
          dp_2[i][j - 1] += dp_2[i][j];
          if (dp_2[i][j - 1] > LL_INF) dp_2[i][j - 1] = LL_INF;
        }
    }
  return dp_1[n - 1][m - 1];
}
int main() {
  long long T;
  cin >> T;
  for (int MX_VV = 32; MX_VV <= 512; MX_VV *= 2)
    for (n = 1; n <= 50; n++)
      for (m = 1; m <= 50; m++) {
        for (int j = 0; j < n; j++)
          for (int k = 0; k < m; k++) nnew[0][j][k] = nnew[1][j][k] = 0;
        long long GG = calc();
        if (GG < T) continue;
        long long last_GG = -1;
        while (GG > T) {
          int tp = -1, x = -1, y = -1;
          long long mn = LL_INF + 10000;
          int vv_len = 0;
          for (int i = n - 2; i >= 0 && vv_len < MX_VV; i--)
            for (int j = m - 1; j >= 0 && vv_len < MX_VV; j--)
              if (!nnew[0][i][j]) {
                long long rem_C = GG - dp_1[i][j] * dp_2[i + 1][j];
                if (T <= rem_C) {
                  vv_len++;
                  if (rem_C < mn) {
                    mn = rem_C;
                    x = i;
                    y = j;
                    tp = 0;
                  }
                }
              }
          for (int j = m - 2; j >= 0 && vv_len < MX_VV; j--)
            for (int i = n - 1; i >= 0 && vv_len < MX_VV; i--)
              if (!nnew[1][i][j]) {
                long long rem_C = GG - dp_1[i][j] * dp_2[i][j + 1];
                if (T <= rem_C) {
                  vv_len++;
                  if (rem_C < mn) {
                    mn = rem_C;
                    x = i;
                    y = j;
                    tp = 0;
                  }
                }
              }
          if (vv_len <= 0) break;
          nnew[tp][x][y] = 1;
          last_GG = GG;
          GG = calc();
          if (GG == last_GG) break;
        }
        if (GG != T) continue;
        int ms_len = 0;
        for (int i = 0; i <= n - 2; i++)
          for (int j = 0; j < m; j++)
            if (nnew[0][i][j]) {
              ms[ms_len].x1 = i;
              ms[ms_len].y1 = j;
              ms[ms_len].x2 = i + 1;
              ms[ms_len].y2 = j;
              ms_len++;
            }
        for (int j = 0; j <= m - 2; j++)
          for (int i = 0; i < n; i++)
            if (nnew[1][i][j]) {
              ms[ms_len].x1 = i;
              ms[ms_len].y1 = j;
              ms[ms_len].x2 = i;
              ms[ms_len].y2 = j + 1;
              ms_len++;
            }
        if (ms_len <= 300) {
          printf("%d %d\n", n, m);
          printf("%d\n", ms_len);
          for (int i = 0; i < ms_len; i++)
            printf("%d %d %d %d\n", ms[i].x1 + 1, ms[i].y1 + 1, ms[i].x2 + 1,
                   ms[i].y2 + 1);
          return 0;
        }
      }
  return 0;
}
