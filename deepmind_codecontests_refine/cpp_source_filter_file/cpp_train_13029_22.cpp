#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6, M = 3e3 + 6, P = 998244353;
int n, m, a[N], b[N], s, t, v[M][M], f[M][M], g[M][M];
inline int ksm(int a, int b = P - 2) {
  int c = 1;
  while (b) {
    if (b & 1) c = (long long)c * a % P;
    a = (long long)a * a % P;
    b >>= 1;
  }
  return c;
}
void dp(int i, int j) {
  if (v[i][j]) return;
  v[i][j] = 1;
  if (i + j == m) return f[i][j] = g[i][j] = 1, void();
  dp(i + 1, j);
  dp(i, j + 1);
  int inv = ksm(s - i + t + j);
  f[i][j] = ((long long)(s - i - 1) * f[i + 1][j] % P +
             (long long)(t + j) * f[i][j + 1] % P) %
            P * inv % P;
  g[i][j] = ((long long)(s - i) * g[i + 1][j] % P +
             (long long)(t + j + 1) * g[i][j + 1] % P) %
            P * inv % P;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    (a[i] ? t : s) += b[i];
  }
  dp(0, 0);
  for (int i = 1; i <= n; i++)
    printf("%lld\n", (long long)(a[i] ? g[0][0] : f[0][0]) * b[i] % P);
  return 0;
}
