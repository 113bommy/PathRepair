#include <bits/stdc++.h>
using namespace std;
const int N = 2222;
int n, h;
double dp[N][N][2][2];
int a[N];
int lf[N], rg[N];
double p;
double get(int i, int j, int t1, int t2) {
  return (i > j ? 0.0 : dp[i][j][t1][t2]);
}
int main() {
  ios::sync_with_stdio(false);
  scanf("%d%d%lf", &n, &h, &p);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  sort(a + 1, a + n + 1);
  rg[n] = n;
  for (int i = n - 1; i >= 1; i--)
    if (a[i + 1] - a[i] < h)
      rg[i] = rg[i + 1];
    else
      rg[i] = i;
  lf[1] = 1;
  for (int i = 2; i <= n; i++)
    if (a[i] - a[i - 1] < h)
      lf[i] = lf[i - 1];
    else
      lf[i] = i;
  for (int i = n; i >= 1; i--)
    for (int j = i; j <= n; j++)
      for (int t1 = 0; t1 < 2; t1++)
        for (int t2 = 0; t2 < 2; t2++) {
          double ret = 0.0;
          int from, to;
          if (i == j) {
            {
              from = a[i];
              to = a[i] + h;
              if (i > 1) from = max(from, t1 == 0 ? a[i - 1] : a[i - 1] + h);
              if (i < n) to = min(to, t2 == 0 ? a[i + 1] - h : a[i + 1]);
              if (from < to) ret += (to - from) * (1 - p);
            }
            {
              from = a[i] - h;
              to = a[i];
              if (i > 1) from = max(from, t1 == 0 ? a[i - 1] : a[i - 1] + h);
              if (i < n) to = min(to, t2 == 0 ? a[i + 1] - h : a[i + 1]);
              if (from < to) ret += (to - from) * p;
            }
          } else {
            {
              from = a[i] - h;
              to = a[i];
              if (i > 1) from = max(from, t1 == 0 ? a[i - 1] : a[i - 1] + h);
              if (j < n) to = min(to, t2 == 0 ? a[j + 1] - h : a[j + 1]);
              if (from < to) ret += (to - from) * p;
              ret += dp[i + 1][j][0][t2] * p;
            }
            {
              from = a[i];
              to = a[rg[i]] + h;
              if (i > 1) from = max(from, t1 == 0 ? a[i - 1] : a[i - 1] + h);
              if (j < n) to = min(to, t2 == 0 ? a[j + 1] - h : a[j + 1]);
              if (from < to) ret += (to - from) * (1 - p);
              ret += get(rg[i] + 1, j, 1, t2) * (1 - p);
            }
            {
              from = a[lf[j]] - h;
              to = a[j];
              if (i > 1) from = max(from, t1 == 0 ? a[i - 1] : a[i - 1] + h);
              if (j < n) to = min(to, t2 == 0 ? a[j + 1] - h : a[j + 1]);
              if (from < to) ret += (to - from) * p;
              ret += get(i, lf[j] - 1, t1, 0) * p;
            }
            {
              from = a[j];
              to = a[j] + h;
              if (i > 1) from = max(from, t1 == 0 ? a[i - 1] : a[i - 1] + h);
              if (j < n) to = min(to, t2 == 0 ? a[j + 1] - h : a[j + 1]);
              if (from < to) ret += (to - from) * (1 - p);
              ret += dp[i][j - 1][t1][1] * (1 - p);
            }
            ret *= 0.5;
          }
          dp[i][j][t1][t2] = ret;
        }
  printf("%.7lf", dp[1][n][0][0]);
  return 0;
}
