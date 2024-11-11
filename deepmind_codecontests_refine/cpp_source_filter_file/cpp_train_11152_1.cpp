#include <bits/stdc++.h>
using namespace std;
const int maxn = 400 + 10;
int fac[maxn], f[maxn], g[maxn][maxn], dp[maxn], cas, P;
inline int inc(int a, int b) { return (a + b >= P) ? (a + b - P) : (a + b); }
inline int dec(int a, int b) { return (a >= b) ? (a - b) : (a + P - b); }
inline int mul(int a, int b) { return 1LL * a * b % P; }
inline void updata(int &x, int y) { x = inc(x, y); }
inline void prepare(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
  for (int i = 1; i <= n; i++) {
    f[i] = fac[i];
    for (int j = 1; j < i; j++) f[i] = dec(f[i], mul(f[j], fac[i - j]));
  }
  g[0][0] = 1;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (!g[i][j]) continue;
      for (int k = 1; i + k <= n; k++) {
        updata(g[i + k][j + 1], mul(g[i][j], fac[k]));
      }
    }
  }
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = fac[i];
    for (int j = 1; j < i; j++)
      dp[i] = dec(dp[i], mul(2, mul(f[j], fac[i - j])));
    for (int j = 3; j < i; j++) dp[i] = dec(dp[i], mul(dp[j], g[i][j]));
  }
}
int main() {
  scanf("%d%d", &cas, &P);
  prepare(400);
  f[2] = 2;
  while (cas--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", dp[x]);
  }
  return 0;
}
