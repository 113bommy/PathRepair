#include <bits/stdc++.h>
long long n, m, a, b, ans = -1;
long long t1[1010][1010], t2[1010][1010], t3[1010][1010], t4[1010][1010];
long long d1[1010][1010], d2[1010][1010], d3[1010][1010], d4[1010][1010];
long long vrt[1010][1010], wvr[1010][1010], hor[1010][1010], who[1010][1010];
long long tlt[1010][1010], sum[1010][1010];
void solv(long long t[1010][1010], long long d[1010][1010], long long k) {
  for (long long j = 0; j < m; j++) {
    vrt[k - 1][j] = 0;
    for (long long i = 0; i < k; i++) vrt[k - 1][j] += t[i][j];
    for (long long i = k; i < n; i++)
      vrt[i][j] = vrt[i - 1][j] - t[i - k][j] + t[i][j];
    wvr[k - 1][j] = 0;
    for (long long i = 0; i < k; i++) wvr[k - 1][j] += (i + 1) * t[i][j];
    for (long long i = k; i < n; i++)
      wvr[i][j] = wvr[i - 1][j] - vrt[i - 1][j] + k * t[i][j];
  }
  for (long long i = 0; i < n; i++) {
    hor[i][k - 1] = 0;
    for (long long j = 0; j < k; j++) hor[i][k - 1] += t[i][j];
    for (long long j = k; j < m; j++)
      hor[i][j] = hor[i][j - 1] - t[i][j - k] + t[i][j];
    who[i][k - 1] = 0;
    for (long long j = 0; j < k; j++) who[i][k - 1] += (j + 1) * t[i][j];
    for (long long j = k; j < m; j++)
      who[i][j] = who[i][j - 1] - hor[i][j - 1] + k * t[i][j];
  }
  for (long long i = k - 1; i < n; i++) {
    for (long long j = k - 1; j < m; j++) {
      if (i - 1 >= k - 1 && i - 1 < n && j + 1 < m && j + 1 >= k - 1) {
        tlt[i][j] = tlt[i - 1][j + 1] - t[i - k][j + 1] + t[i][j - k + 1];
        continue;
      }
      tlt[i][j] = 0;
      for (long long x = 0; x < k; x++) tlt[i][j] += t[i - x][j - k + x + 1];
    }
  }
  sum[k - 1][k - 1] = 0;
  for (long long i = 0; i < k; i++)
    for (long long j = k - 1; j >= k - 1 - i; j--) sum[k - 1][k - 1] += t[i][j];
  for (long long j = k; j < m; j++)
    sum[k - 1][j] = sum[k - 1][j - 1] - tlt[k - 1][j - 1] + vrt[k - 1][j];
  for (long long i = k; i < n; i++)
    for (long long j = k - 1; j < m; j++)
      sum[i][j] = sum[i - 1][j] - tlt[i - 1][j] + hor[i][j];
  d[k - 1][k - 1] = 0;
  for (long long i = 0; i < k; i++)
    for (long long j = k - 1; j >= k - 1 - i; j--)
      d[k - 1][k - 1] += t[i][j] * (i + j - k + 2);
  for (long long j = k; j < m; j++)
    d[k - 1][j] = d[k - 1][j - 1] - sum[k - 1][j - 1] + wvr[k - 1][j];
  for (long long i = k; i < n; i++)
    for (long long j = k - 1; j < m; j++)
      d[i][j] = d[i - 1][j] - sum[i - 1][j] + who[i][j];
}
int main() {
  long long k;
  scanf("%I64d%I64d%I64d", &n, &m, &k);
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      scanf("%I64d", &t1[i][j]);
      t2[i][m - j - 1] = t1[i][j];
      t3[n - i - 1][j] = t1[i][j];
      t4[n - i - 1][m - j - 1] = t1[i][j];
    }
  }
  if (k > 0) solv(t1, d1, k);
  if (k - 1 > 0) solv(t2, d2, k - 1);
  if (k - 1 > 0) solv(t3, d3, k - 1);
  if (k - 2 > 0) solv(t4, d4, k - 2);
  for (long long i = k - 1; i <= n - k; i++)
    for (long long j = k - 1; j <= m - k; j++) {
      long long v = d1[i][j] + d2[i][m - j - 2] + d3[n - i - 2][j] +
                    d4[n - i - 2][m - j - 2];
      if (ans < v) a = i, b = j, ans = v;
    }
  printf("%I64d %I64d\n", a + 1, b + 1);
}
