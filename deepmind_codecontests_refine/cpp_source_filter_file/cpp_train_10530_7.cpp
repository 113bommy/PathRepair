#include <bits/stdc++.h>
using namespace std;
inline int Get() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const long long mod = 1e9 + 7;
int n, m, k;
long long f[15][1 << 4], g[15][1 << 4];
int bin[1 << 4];
int main() {
  n = Get(), k = Get(), m = Get();
  for (int S = 0; S < 1 << m; S++)
    for (int i = 0; i < n; i++) bin[S] += (S >> i & 1);
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    memset(g, 0, sizeof(g));
    for (int j = 0; j <= k; j++) {
      for (int S = 0; S < 1 << m; S++) {
        if (!f[j][S]) continue;
        (g[j][S >> 1] += f[j][S]) %= mod;
        if (j < k)
          (g[j + 1][(S >> 1) | (1 << m - 1)] += f[j][S] * (bin[S] + 1)) %= mod;
      }
    }
    memcpy(f, g, sizeof(f));
  }
  int ans = 0;
  for (int S = 0; S < 1 << m; S++) (ans += f[k][S]) %= mod;
  cout << ans;
  return 0;
}
