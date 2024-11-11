#include <bits/stdc++.h>
using namespace std;
char c[17];
int r[17], b[17];
int f[1 << 16][200], sumr[1 << 16], sumb[1 << 16];
int n, MAX;
int main() {
  scanf("%d\n", &n);
  for (int i = 1; i <= n; ++i) scanf("%c %d %d\n", &c[i], &r[i], &b[i]);
  MAX = 1 << n;
  for (int i = 0; i < MAX; ++i)
    for (int j = 0; j < n; ++j)
      if (((1 << j) & i) != 0)
        if (c[j + 1] == 'R')
          ++sumr[i];
        else
          ++sumb[i];
  for (int i = 0; i <= n * (n - 1) / 2; ++i)
    for (int s = 0; s < MAX; ++s) f[s][i] = 1e9;
  f[0][0] = 0;
  for (int i = 0; i <= n * (n - 1) / 2; ++i)
    for (int s = 0; s < MAX; ++s)
      for (int j = 0; j < n; ++j)
        if (((1 << j) & s) != 0) {
          if (sumr[s - ((1 << j) & s)] >= r[j + 1]) {
            if (i >= r[j + 1])
              f[s][i] =
                  min(f[s][i], f[s - ((1 << j) & s)][i - r[j + 1]] +
                                   max(0, b[j + 1] - sumb[s - ((1 << j) & s)]));
          } else {
            if (i >= sumr[s - ((1 << j) & s)])
              f[s][i] = min(
                  f[s][i], f[s - ((1 << j) & s)][i - sumr[s - ((1 << j) & s)]] +
                               max(0, b[j + 1] - sumb[s - ((1 << j) & s)]));
          }
        }
  int s = 0, ans = 1e9;
  for (int i = 1; i <= n; ++i) s += r[i];
  for (int i = 0; i <= min(s, n * (n - 1) / 2); ++i)
    ans = min(ans, max(s - i, f[MAX - 1][i]));
  printf("%d", ans + n);
  return 0;
}
