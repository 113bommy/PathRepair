#include <bits/stdc++.h>
using namespace std;
int gi() {
  int x = 0, w = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') w = 0, ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return w ? x : -x;
}
const int N = 1005;
const int mod = 1e9 + 7;
int n, m, jc[N], C[N][N], A[N], B[N];
int main() {
  n = gi();
  m = gi();
  for (int i = jc[0] = 1; i <= n; ++i) jc[i] = 1ll * jc[i - 1] * i % mod;
  for (int i = 0; i <= n; ++i)
    for (int j = C[i][0] = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  for (int i = 0; i <= n; ++i) A[i] = C[n - i][i];
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= i; ++j) B[i] = (B[i] + 1ll * A[j] * A[i - j]) % mod;
  for (int i = 0; i <= n; ++i) B[i] = 1ll * B[i] * jc[n - i] % mod;
  for (int i = n; i; --i)
    for (int j = i + 1; j <= n; ++j)
      B[i] = (B[i] - 1ll * B[j] * C[j][i] % mod + mod) % mod;
  printf("%d\n", B[m]);
  return 0;
}
