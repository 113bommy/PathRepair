#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, t = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') t = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
  return s * t;
}
const int P = 998244353;
const int N = 55;
int n, m, cnt, tot, C[N][N], dp[N][N], f[N], g[N];
long long p[N], d[N];
int Mod(int x) { return x >= P ? x - P : x; }
int Ksm(int x, int k) {
  int res = 1;
  while (k) {
    if (k & 1) res = 1ll * res * x % P;
    x = 1ll * x * x % P, k >>= 1;
  }
  return res;
}
void Ins(long long x) {
  for (int i = m - 1; i >= 0; i--)
    if (x >> i & 1) {
      if (!p[i]) {
        p[i] = x, cnt++;
        return;
      }
      x ^= p[i];
    }
}
void DFS1(int k, long long S) {
  if (k == tot) {
    g[__builtin_popcountll(S)]++;
    return;
  }
  DFS1(k + 1, S), DFS1(k + 1, S ^ p[k]);
}
void DFS2(int k, long long S) {
  if (k == tot) {
    f[__builtin_popcountll(S)]++;
    return;
  }
  DFS2(k + 1, S), DFS2(k + 1, S ^ d[k]);
}
int main() {
  n = read(), m = read();
  for (int i = 0; i <= m; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) C[i][j] = Mod(C[i - 1][j - 1] + C[i - 1][j]);
  }
  for (int i = 1; i <= n; i++) Ins(read());
  if (cnt <= 26) {
    for (int i = 0; i < m; i++)
      if (p[i]) p[tot++] = p[i];
    DFS1(0, 0);
  } else {
    for (int i = 0; i < m; i++)
      for (int j = i - 1; j >= 0; j--)
        if (p[i] >> j & 1) p[i] ^= p[j];
    for (int i = 0; i < m; i++)
      if (!p[i]) {
        for (int j = 0; j < m; j++)
          if (p[j] >> i & 1) d[tot] |= (1ll << j);
        d[tot++] = (1 << i);
      }
    for (int c = 0; c <= m; c++)
      for (int i = 0; i <= m; i++)
        for (int k = 0; k <= min(m, i); k++) {
          int t = 1ll * (k & 1 ? P - 1 : 1) * C[i][k] % P * C[m - i][c - k] % P;
          dp[c][i] = Mod(dp[c][i] + t);
        }
    DFS2(0, 0);
    for (int c = 0; c <= m; c++)
      for (int i = 0; i <= m; i++) g[c] = Mod(g[c] + 1ll * f[i] * dp[c][i] % P);
    for (int c = 0; c <= m; c++)
      g[c] = (1ll << cnt) % P * Ksm((1ll << m) % P, P - 2) % P * g[c] % P;
  }
  for (int c = 0; c <= m; c++) cout << 1ll * g[c] * Ksm(2, n - cnt) % P << ' ';
  return 0;
}
