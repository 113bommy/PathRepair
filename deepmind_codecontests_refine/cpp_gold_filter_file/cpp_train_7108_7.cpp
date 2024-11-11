#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10, md = 998244353;
int n, a[N], b[N][N], c[N], dp[N][N], ans;
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
inline int mod(int k) {
  if (k >= md) return k -= md;
  if (k < 0) return k += md;
  return k;
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    dp[1][i] = 1;
    b[1][i] = mod(b[1][i - 1] + 1);
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i) {
    c[i] = c[i - 1];
    while (a[c[i] + 1] * 2 <= a[i]) ++c[i];
  }
  for (int i = 2; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      dp[i][j] =
          mod(1ll * dp[i - 1][j] * max(0, c[j] - i + 2) % md + b[i - 1][c[j]]);
      b[i][j] = mod(b[i][j - 1] + dp[i][j]);
    }
  for (int i = 1; i <= n; ++i) ans = mod(ans + dp[n][i]);
  printf("%d", ans);
  return 0;
}
