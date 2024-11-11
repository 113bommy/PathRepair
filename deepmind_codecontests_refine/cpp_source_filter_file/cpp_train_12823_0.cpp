#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
inline long long read() {
  char ch = getchar();
  long long x = 0, f = 0;
  while (ch < '0' || ch > '9') f |= ch == '-', ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
int t, n, m, a[22][2222], sum[2222][4444], f[2222][4444];
int main() {
  t = read();
  while (t--) {
    n = read();
    m = read();
    for (int i = (0); i <= (n - 1); i++)
      for (int j = (0); j <= (m - 1); j++) a[i][j] = read();
    for (int i = (0); i <= (m - 1); i++)
      for (int S = (0); S <= ((1 << n) - 1); S++) {
        sum[i][S] = 0;
        for (int j = (0); j <= (n - 1); j++) {
          int s = 0;
          for (int k = (0); k <= (n - 1); k++)
            if ((S >> k) & 1) s += a[(j + k) % n][i];
          sum[i][S] = max(sum[i][S], s);
        }
      }
    for (int S = (0); S <= ((1 << n) - 1); S++) f[0][S] = sum[0][S];
    for (int i = (1); i <= (m - 1); i++)
      for (int S = (0); S <= ((1 << n) - 1); S++) {
        f[i][S] = sum[i][S];
        for (int S0 = S; S0; S0 = (S0 - 1) & S)
          f[i][S] = max(f[i][S], f[i - 1][S ^ S0] + sum[i][S0]);
      }
    printf("%d\n", f[m - 1][(1 << n) - 1]);
  }
}
