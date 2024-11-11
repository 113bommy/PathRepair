#include <bits/stdc++.h>
using namespace std;
const int ALL = 5000;
const int MAXN = 5005;
const int MOD = (1 << 30) - 1;
int is[MAXN], mu[MAXN], p[MAXN], t, g[MAXN][MAXN];
inline int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
int gcd(int x, int y) {
  if (g[x][y]) return g[x][y];
  if (!y) return x;
  return g[y][x % y] = (y, x % y);
}
inline void prepare() {
  is[1] = mu[1] = 1;
  for (int i = 2; i <= ALL; i++) {
    if (!is[i]) p[++t] = i, mu[i] = -1;
    for (int j = 1; j <= t && i * p[j] <= ALL; j++) {
      is[i * p[j]] = 1, mu[i * p[j]] = -mu[i];
      if (i % p[j] == 0) {
        mu[i * p[j]] = 0;
        break;
      }
    }
  }
}
inline long long f(int d, int k, int n) {
  long long ans = 0;
  for (int i = d; i <= n; i += d)
    if (g[k][i] == 1) ans += n / i;
  return ans;
}
int main() {
  prepare();
  long long ans = 0;
  int a = read(), b = read(), c = read();
  for (int i = 1; i <= ALL; i++)
    for (int j = 1; j <= ALL; j++) g[i][j] = gcd(i, j);
  for (int k = 1; k <= c; k++)
    for (int d = 1; d <= min(a, b); d++)
      if (gcd(k, d) == 1) ans += c / k * mu[d] * f(d, k, a) * f(d, k, b);
  cout << (ans & MOD) << endl;
  return 0;
}
