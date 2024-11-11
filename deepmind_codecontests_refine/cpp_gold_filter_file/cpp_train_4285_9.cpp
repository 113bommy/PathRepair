#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
int n, k, a[102], now, o, z, t, i;
struct M {
  int a[102][102];
  friend M operator*(M x, M y) {
    M z;
    memset(z.a, 0, sizeof(z.a));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
          z.a[i][j] = (z.a[i][j] + 1ll * x.a[i][k] * y.a[k][j]) % P;
    return z;
  }
  friend M operator^(M x, int y) {
    M z;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) z.a[i][j] = i == j;
    for (; y; y >>= 1, x = x * x)
      if (y & 1) z = z * x;
    return z;
  }
} A;
int pw(int x, int y) {
  int z = 1;
  for (; y; y >>= 1, x = 1ll * x * x % P)
    if (y & 1) z = 1ll * z * x % P;
  return z;
}
int main() {
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]), z += !a[i];
  o = n - z;
  for (i = 1; i <= z; i++) now += !a[i];
  for (i = 0; i <= z; i++) {
    A.a[i][i] =
        z * (z - 1) / 2 + o * (o - 1) / 2 + i * (z - i) + (z - i) * (o - z + i);
    if (i < z) A.a[i][i + 1] = (z - i) * (z - i);
    if (i) A.a[i][i - 1] = i * (o - z + i);
  }
  t = pw(pw(n * (n - 1) / 2, k), P - 2);
  n = z + 1, A = A ^ k;
  printf("%I64d", 1ll * A.a[now][z] * t % P);
}
