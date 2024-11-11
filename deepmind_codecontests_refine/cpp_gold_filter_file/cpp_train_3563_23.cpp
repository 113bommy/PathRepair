#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const long long N = 85;
const long long K = 11;
long long n, k, ans = 1e18;
long long e[N][N];
long long f[K][N], c[N];
signed main() {
  srand(time(0));
  n = read(), k = read();
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= n; j++) e[i][j] = read();
  long long T = 5000;
  while (T--) {
    memset(f, 0x3f, sizeof f);
    for (long long i = 1; i <= n; i++) c[i] = rand() % 2;
    f[0][1] = 0;
    for (long long i = 1; i <= k; i++)
      for (long long u = 1; u <= n; u++)
        for (long long v = 1; v <= n; v++)
          if (c[u] != c[v]) f[i][v] = min(f[i][v], f[i - 1][u] + e[u][v]);
    ans = min(ans, f[k][1]);
  }
  cout << ans;
}
