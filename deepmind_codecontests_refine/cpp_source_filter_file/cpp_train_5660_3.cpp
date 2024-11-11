#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int modulo = 1000000007;
int n, m, k;
long long f[maxn][maxn * maxn], g[maxn][maxn], C[maxn][maxn];
void input() {
  cin >> n >> m >> k;
  C[1][0] = C[1][1] = 1;
  for (register int i = 2; i <= n; i++) {
    C[i][0] = 1;
    for (register int j = 1; j <= i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % modulo;
    }
  }
}
long long pwr(long long x, long long k) {
  long long re = 1;
  x %= modulo;
  while (k) {
    if (k & 1) re = 1ll * re * x % modulo;
    x = 1ll * x * x % modulo;
    k >>= 1;
  }
  return re;
}
void solve() {
  long long ans = 0, a = m / n, b = m % n;
  int lm = min(k, n);
  f[0][0] = 1;
  for (register int i = 1; i <= n; i++) {
    for (register int j = 0; j <= n; j++) {
      g[i][j] = pwr(C[n][j], a + (b >= i));
    }
  }
  for (register int i = 1; i <= n; i++) {
    for (register int p = 0; p <= k; p++) {
      for (register int j = 0, ed = min(lm, p); j <= ed; j++) {
        f[i][p] = (f[i][p] + f[i - 1][p - j] * g[i][j]) % modulo;
      }
    }
  }
  cout << f[n][k] << endl;
}
int main() {
  input();
  solve();
  return 0;
}
