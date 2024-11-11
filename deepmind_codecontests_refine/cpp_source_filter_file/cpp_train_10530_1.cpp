#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int K, n, i, j, nn, ans, m, k;
inline void add(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}
struct M {
  int a[202][202];
  friend M operator*(M x, M y) {
    M z;
    memset(z.a, 0, sizeof(z.a));
    for (int i = 0; i < nn; i++)
      for (int j = 0; j < nn; j++)
        for (int k = 0; k < nn; k++)
          add(z.a[i][j], 1ll * x.a[i][k] * y.a[k][j] % P);
    return z;
  }
  friend M operator^(M x, int y) {
    M z;
    memset(z.a, 0, sizeof(z.a));
    z.a[0][0] = 1;
    for (; y; y >>= 1, x = x * x)
      if (y & 1) z = z * x;
    return z;
  }
} A, dp;
int id(int x, int y) { return x * (1 << m) + y; }
int main() {
  scanf("%d%d%d", &n, &K, &m);
  for (i = 0; i <= K; i++)
    for (j = 0; j < 1 << m; j++) {
      k = (j << 1) & ((1 << m) - 1);
      A.a[id(i, j)][id(i, k)] = 1;
      if (i < K) A.a[id(i, j)][id(i + 1, k | 1)] = __builtin_popcount(j) + 1;
    }
  nn = id(K, 1 << m);
  A = A ^ n;
  for (i = 0; i < 1 << m; i++) add(ans, A.a[0][id(K, i)]);
  printf("%d", ans);
}
