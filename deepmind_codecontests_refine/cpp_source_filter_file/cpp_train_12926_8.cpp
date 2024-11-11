#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, y = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') y = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch & 15);
    ch = getchar();
  }
  return x * y;
}
const int N = 109, M = 30;
long long n, m, ans = 0;
long long f[N][N][M];
char s[N];
int main() {
  register long long i, j, k, l;
  n = read(), m = read();
  scanf("%s", s + 1);
  for (i = 1; i <= n; i++) {
    f[i][1][s[i] - 'a' + 1] = 1;
    for (j = 1; j <= i; j++) {
      for (k = 1; k <= 26; k++) {
        if (k == s[i] - 'a' + 1) {
          for (l = 1; l <= 26; l++) {
            f[i][j][k] += f[i - 1][j - 1][l];
            if (f[i][j][k] > k) {
              f[i][j][k] = k;
              break;
            }
          }
        } else
          f[i][j][k] += f[i - 1][j][k];
        if (f[i][j][k] > k) {
          f[i][j][k] = k;
          break;
        }
      }
    }
  }
  for (i = n; i > 0; i--) {
    if (!k) break;
    for (j = 1; j <= 26; j++) {
      ans += min(m, f[n][i][j]) * (n - i);
      m -= min(m, f[n][i][j]);
      if (!k) break;
    }
  }
  if (!m)
    printf("%lld\n", ans);
  else if (m == 1)
    printf("%lld\n", ans + n);
  else
    puts("-1");
  return 0;
}
