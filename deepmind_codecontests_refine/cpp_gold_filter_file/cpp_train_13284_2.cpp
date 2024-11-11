#include <bits/stdc++.h>
using namespace std;
const int maxn = 309;
const int mod = 1e9 + 7;
int f[maxn][maxn], C[maxn][maxn], b[maxn], a[maxn], fac[maxn];
int n;
inline void update(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void init(int mr) {
  fac[0] = 1;
  for (int i = 1; i <= mr; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  for (int i = 0; i <= mr; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  }
}
int main() {
  n = read();
  init(n);
  for (int i = 1; i <= n; i++) {
    int x = read(), res = 1;
    for (int j = 2; j * j <= x; j++) {
      int cnt = 0;
      while (x % j == 0) {
        x /= j;
        cnt ^= 1;
      }
      if (cnt) res *= j;
    }
    if (x > 1) res *= x;
    a[i] = res;
  }
  sort(a + 1, a + 1 + n);
  a[n + 1] = -1;
  int last = -1, cnt = 0;
  for (int i = 1; i <= n + 1; i++) {
    if (last == a[i])
      cnt++;
    else {
      if (cnt) b[++b[0]] = cnt;
      cnt = 1;
      last = a[i];
    }
  }
  sort(b + 1, b + 1 + b[0]);
  int sum = b[1];
  f[1][b[1] - 1] = 1;
  for (int i = 1; i < b[0]; i++) {
    for (int j = 0; j <= sum - i; j++)
      for (int k = 1; k <= b[i + 1]; k++)
        for (int p = 0; p <= j && p <= k; p++)
          update(f[i + 1][j + b[i + 1] - k - p],
                 1ll * f[i][j] * C[b[i + 1] - 1][k - 1] % mod * C[j][p] % mod *
                     C[sum - 1 - j + 2][k - p] % mod);
    sum += b[i + 1];
  }
  int ans = f[b[0]][0];
  for (int i = 1; i <= b[0]; i++) ans = 1ll * ans * fac[b[i]] % mod;
  cout << ans << endl;
  return 0;
}
