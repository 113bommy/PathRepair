#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e3 + 5, Mo = 998244353;
int pwr(int x, int y) {
  int z = 1;
  for (; y; y >>= 1, x = (long long)x * x % Mo)
    if (y & 1) z = (long long)z * x % Mo;
  return z;
}
int n, a, b, p, q, P[N], Q[N], Cp[N][N], G[N], F[N];
int main() {
  scanf("%d", &n);
  scanf("%d%d", &a, &b);
  int p = (long long)a * pwr(b, Mo - 2), q = Mo + 1 - p;
  P[0] = 1;
  for (int i = 1; i <= n; i++) P[i] = (long long)P[i - 1] * p % Mo;
  Q[0] = 1;
  for (int i = 1; i <= n; i++) Q[i] = (long long)Q[i - 1] * q % Mo;
  Cp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    Cp[i][0] = 1;
    for (int j = 1; j <= i; j++)
      Cp[i][j] = ((long long)Cp[i - 1][j] * Q[j] % Mo +
                  (long long)Cp[i - 1][j - 1] * P[i - j] % Mo) %
                 Mo;
  }
  G[1] = 1;
  for (int i = 2; i <= n; i++) {
    G[i] = 1;
    for (int j = 1; j <= i - 1; j++)
      (G[i] += Mo - (long long)G[j] * Cp[i][j] % Mo) %= Mo;
  }
  F[1] = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i - 1; j++) {
      int now = 0;
      (now += F[i - j] + F[j]) %= Mo;
      (now += j * (j - 1) / 2) %= Mo;
      (now += (i - j) * j) %= Mo;
      (F[i] += (long long)now * G[j] % Mo * Cp[i][j] % Mo) %= Mo;
    }
    (F[i] += (long long)i * (i - 1) / 2 * G[i] % Mo * Cp[i][i] % Mo) %= Mo;
    F[i] = (long long)F[i] *
           pwr(1 + Mo - (long long)G[i] * Cp[i][i] % Mo, Mo - 2) % Mo;
  }
  printf("%d\n", F[n]);
  return 0;
}
