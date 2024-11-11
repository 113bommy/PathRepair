#include <bits/stdc++.h>
using namespace std;
const int N = 2010, Mo = 998244353;
int s1[N], s2[N], C[N][N], f[N], g[N], v[N];
inline int Pow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = 1LL * ret * x % Mo;
    x = 1LL * x * x % Mo, y >>= 1;
  }
  return ret;
}
int main() {
  int n, p, q;
  cin >> n >> p >> q;
  p = 1LL * p * Pow(q, Mo - 2), q = 1 - p;
  for (int i = s1[0] = s2[0] = 1; i <= n; i++) {
    s1[i] = 1LL * s1[i - 1] * p % Mo;
    s2[i] = 1LL * s2[i - 1] * q % Mo;
  }
  for (int i = 0; i <= n; i++)
    for (int j = C[i][0] = 1; j <= i; j++)
      C[i][j] =
          (1LL * C[i - 1][j] * s1[j] + 1LL * C[i - 1][j - 1] * s2[i - j]) % Mo;
  for (int i = 1; i <= n; i++) {
    f[i] = 1;
    int x = i * (i - 1) / 2;
    for (int j = 1; j < i; j++) {
      f[i] = (f[i] - 1LL * C[i][j] * f[j]) % Mo;
      g[i] = (g[i] + 1LL * C[i][j] * f[j] % Mo * (x + g[j] + v[i - j])) % Mo;
    }
    g[i] = (g[i] + 1LL * f[i] * x) % Mo * Pow(1 - f[i], Mo - 2) % Mo;
    for (int j = 1; j <= i; j++)
      v[i] = (v[i] + 1LL * C[i][j] * f[j] % Mo * (g[j] + v[i - j])) % Mo;
  }
  cout << (g[n] + Mo) % Mo;
  return 0;
}
