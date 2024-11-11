#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int x = 0, f = 1;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = getchar();
  return x * f;
}
const int P = 998244353;
const int N = 505;
int n, a[N], b[N], c[4], d[N], vi[N], fa[N];
long long f[N], g[N], h[N], ans[N], C[N][N], A[N][N], S[N][N];
int go(int x) {
  while (fa[x] && !vi[x]) vi[x] = 1, x = fa[x];
  vi[x] = 1;
  return x;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) b[i] = read();
  for (int i = 1; i <= n; i++) {
    if (a[i]) fa[i] = a[i] + n, d[a[i] + n] = 1;
    if (b[i]) fa[b[i] + n] = i, d[i] = 1;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!d[i]) {
      if (go(i) <= n)
        c[0]++;
      else
        c[1]++;
    }
    if (!d[i + n]) {
      if (go(i + n) <= n)
        c[2]++;
      else
        c[3]++;
    }
  }
  for (int i = 1; i <= n * 2; i++)
    if (!vi[i]) ++cnt, go(i);
  C[0][0] = A[0][0] = S[0][0] = 1;
  for (int i = 1; i <= n * 2; i++) {
    C[i][0] = A[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
      A[i][j] = (A[i - 1][j] + A[i - 1][j - 1] * j) % P;
      S[i][j] = (S[i - 1][j - 1] + (i - 1) * S[i - 1][j]) % P;
    }
  }
  for (int i = 0; i <= c[1]; i++)
    for (int j = i; j <= c[1]; j++)
      f[i] =
          (f[i] + C[c[1]][j] * S[j][i] % P * A[c[0] + c[1] - j][c[1] - j]) % P;
  for (int i = c[1]; ~i; i--)
    for (int j = c[1]; j > i; j--) f[i] = (f[i] - C[j][i] * f[j] % P + P) % P;
  for (int i = 0; i <= c[2]; i++)
    for (int j = i; j <= c[2]; j++)
      g[i] =
          (g[i] + C[c[2]][j] * S[j][i] % P * A[c[3] + c[2] - j][c[2] - j]) % P;
  for (int i = c[2]; ~i; i--)
    for (int j = c[2]; j > i; j--) g[i] = (g[i] - C[j][i] * g[j] % P + P) % P;
  for (int i = 0; i <= c[1]; i++)
    for (int j = 0; j <= c[2]; j++) h[i + j] = (h[i + j] + f[i] * g[j]) % P;
  int m = c[1] + c[2];
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= c[0]; j++)
      ans[i + j] = (ans[i + j] + h[i] * S[c[0]][j]) % P;
  if (cnt)
    for (int i = n - 1; ~i; i--) ans[i + cnt] = ans[i], ans[i] = 0;
  for (int i = n; i; i--) printf("%lld ", ans[i] * A[c[0]][c[0]] % P);
  return 0;
}
