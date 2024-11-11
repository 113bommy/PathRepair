#include <bits/stdc++.h>
using namespace std;
int n, m, a[200009], b[2009], sum[200009], dp[200009], L[200009], R[200009];
int read() {
  int x = 1;
  char ch;
  while (ch = getchar(), ch < '0' || ch > '9')
    if (ch == '-') x = -1;
  int s = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
  return s * x;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + n + 1);
  a[0] = a[1] - 1000, a[n + 1] = a[n] + 1000;
  for (int i = 1; i <= n; ++i)
    if (a[i] == a[i - 1] + 1)
      L[i] = L[i - 1];
    else
      L[i] = i;
  for (int i = n; i; --i)
    if (a[i] == a[i + 1] - 1)
      R[i] = R[i + 1];
    else
      R[i] = i;
  sum[0] = 0;
  for (int i = 1; i <= m; i++) b[i] = read(), sum[b[i]]++;
  sort(b + 1, b + m + 1);
  for (int i = 1; i <= 200000; i++) sum[i] += sum[i - 1];
  for (int i = 1; i <= n; i++) {
    dp[i] = max(dp[i], dp[i - 1]);
    int Max;
    if (L[i] == i)
      Max = dp[i - 1] + sum[a[i]] - sum[a[i] - 1];
    else
      Max = -10000000;
    dp[i] = max(dp[i], Max);
    for (int l = 1; b[l] <= a[i] && l <= m; l++)
      if (i - (a[i] - b[l]) >= 1) {
        dp[i] = max(dp[i],
                    dp[L[i - (a[i] - b[l])] - 1] + sum[a[i]] - sum[b[l] - 1]);
        Max =
            max(Max, dp[L[i - (a[i] - b[l])] - 1] + sum[a[i]] - sum[b[l] - 1]);
      }
    for (int r = m; b[r] >= a[i] && r; r--)
      if (i + b[r] - a[i] <= n)
        dp[R[i + b[r] - a[i]]] =
            max(dp[R[i + b[r] - a[i]]], Max + sum[b[r]] - sum[a[i]]);
  }
  printf("%d\n", dp[n]);
  return 0;
}
